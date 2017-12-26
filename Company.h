#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H


#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <queue>
#include "Passenger.h"
#include "Plane.h"
#include "Exceptions.cpp"
#include "tecnico.h"

using namespace std;

struct SortOrder
{
	bool operator()(const Plane* p1, const Plane* p2)
	{
		if (p1->getNextMaintenance() == p2->getNextMaintenance())
			return p1->getId() < p2->getId();
		else
			return p1->getNextMaintenance() < p2->getNextMaintenance();
	}
};

class Technician;
class PassengerWCard;

/*
 * @class Company Class that represents a airline company where are stored all its planes, registered passengers, maintenances and technicians
 */

class Company
{
private:
    vector<PassengerWCard *> PassengerCards;			/** < @brief All of passengers registered in the company */
    vector<Plane *> planes;							    /** < @brief All of the planes of the airline company */
    priority_queue <Technician> technicians;            /** < @brief All of the technicians of the company ordered according to their availability*/
    string planesFile, passFile, reservFile, techFile;	/** < @brief Names of the files where the information is imported from */
	set<Plane*, SortOrder> maintenance;

public:

    /**
	 * @brief Constructor called when there's an error opening the files. No data is imported.
	 */
    Company();

    /**
     * @brief Constructor Data will be imported from the files
     * @param passengersFile File with the passengers' information
     * @param planesFile File with the planes' information
     * @param reservFile File with the reservations' information
     * @param techFile File with the techs' information
     * @throw ErrorOpeningFile If there isn't a file with the name specified in the parameters
     * @throw InvalidDate If there's an invalid date in one of the files
     */
    Company(string passengersFile, string planesFile, string reservFile, string techFile);

    /* Get methods */
    /**
     * @returns The planes of the airline company
     */
    vector<Plane *> getPlanes() const;

    /**
     * @returns The passengers registered on the company
     */
    vector<PassengerWCard *> getRegPassengers () const;

    /* Open files */
    /**
     * @brief Opens the file with the information regarding the passengers.
     * Uses the member value passFile as the name of the file.
     * @throw ErrorOpeningFile If there's an error opening the file
     */
    void openPassFile ();

    /**
     * @brief Opens the file with the information regarding the planes
     * Uses the member value planesFile as the name of the file
     * @throw ErrorOpeningFile If there's an error opening the file
     */
    void openPlanesFile ();

    /**
     * @brief Opens the reservation file with the information regarding the reservations
     * Uses the member value reservFile as the name of the file
     */
    void openReservFile ();


    void openTechFile();

    /**
     * @brief Calls the three functions that update the data on each file
     */
	void logOut ();

	/**
	 * @brief Writes all the data regarding the passengers with cards
	 * Uses the member value passFile as the name of the file.
	 */
	void closePassFile();

	/**
	 * @brief Writes all the data regarding the planes
	 * Uses the member value planesFile as the name of the file.
	 */
	void closePlanesFile();

	/**
	 * @brief Writes all the data regarding the reservations with cards
	 * Uses the member value reservFile as the name of the file.
	 */
    void closeReservFile();

    void closeTechFile();

    /**
    	 * @brief Reads a complex string meaning a string with several nouns separated by spaces. Used when reading strings from the files.
    	 * @param &s the stringstream where the string should be imported from
    	 * @param separate the character that indicates the end of the string
    	 * @return The string read
    	 */
    static string readComplexString (istringstream &s, char separate);

    /* Edit planes' vector */

	void insertPlanesInTree();

	void maintenanceList();

	void maintenanceList(Date &d1);

    /**
     * @brief Adds a plane to the company. Calculates the id it should have and sets the plane id.
     * @param p The plane to be added
     */
    void addPlane(Plane *p);

    /**
     * @brief Deletes a plane of the company based on its id.
     * @param nrid The id of the plane to be deleted
     * @throw NoSuchPlane If there isn't a plane with the id specified as a parameter
     * @return A pointer to the plane that was deleted
     */
    Plane * deletePlane (unsigned int nrid);

    /**
     * @brief Searches a plane of the company based on its id.
     * @param nrid The id of the plane that is being searched
     * @param i Used as a return value: the index of the plane on the company's vector
     * @throw NoSuchPlane If there isn't a plane with the id specified as a parameter
     * @return A pointer to the plane
     */
    Plane * searchPlane (unsigned int nrid, int &i);
	
	/**
	 * @brief Orders all the existing airports (departure and arrival)
	 * @return A 2D vector with the flights leaving or arriving to every airport
	 */
	vector <vector <Flight *> > getAirportsFlights ();

    /**
     * @brief Adds a flight to the company, assigning it to the first plane to be free at that flight's time
     * @param f The flight to be added
     * @throw RepeatedFlight If there's no plane available at the time of the flight
     */
	void addFlight (Flight *f);

	/**
	 * @brief Calculates the number of flights of the company
	 * @return The number of flights of the company
	 */
	unsigned long numOfFlights();

    void scheduleMaintenances ();


	/*Edit Passenger vector */
	/**
	 * @brief Adds a registered passenger to the company
	 * @param p1 The passenger to be added to the company
	 */
	void addPassenger(PassengerWCard * p1);

	/**
	 * @brief Searches a registered passenger based on his id
	 * @param nrid The id of the passenger to be searched for
	 * @param i Used as a return value: the index of the passenger on the company's vector
	 * @throw NoSuchPassenger If there's not a passenger with that id
	 * @return A pointer to the passenger that was just deleted
	 */
	PassengerWCard * searchPassenger(unsigned int nrid, int &i);

	/**
	 * @brief Deletes a registered passenger based on his id
	 * @param nrid The id of the passenger to be deleted
	 * @return A pointer to the passenger that was just deleted
	 */
	PassengerWCard * deletePassenger(unsigned int nrid);

    /* Edit flights */
	/**
	 * @brief Searches for a flight in all planes based on its id
	 * @param FlightId The id of the flight to be searched for
	 * @throw NoSuchFlight If there's not a flight with that id
	 * @return A pointer to the flight
	 */
    Flight * searchFlight (unsigned int FlightId);

    /**
     * @brief Adds a technician to the company inserting him in the queue according to his priority
     * @param t Technician to be added to the company
     */
    void addTechnician (Technician t);

    /**
     * @brief Deletes a technician from the company's database
     * @param id Id of the technician to be deleted
     * @throw NoSuchTechnician If there is not a technician with the given id in th company's database
     * @return The information of the deleted technician
     */
    Technician deleteTechnician (int id);

    /**
     * @brief Searches for a technician in the company
     * @param id Id of the technician who is been searched
     * @throw NoSuchTechnician If there's no technician with the given id
     * @return The technician with the given id
     */
    Technician searchTechnician (int id);


    /**
     * @brief Prints all of the technicians of a company - the ones that are stored in the priority_queue
     */
    void printAllTechnicians ();

};

#endif //AEDA_COMPANY_H
