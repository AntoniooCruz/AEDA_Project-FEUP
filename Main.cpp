#include "Main.h"

using namespace std;

string checkString(string s1) {
	cin.ignore(1000, '\n');
	getline(cin, s1);

	while (cin.fail())
	{
		cout << "Invalid Input" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, s1);
	}
	return s1;
}

int checkBoundaries(int linf, int lsup) {
	int nr;

	cin >> nr;

	while (cin.fail() || nr > lsup || nr < linf) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}

	return nr;
}

int checkBoundaries(int linf) {
	int nr;
	cin >> nr;

	while (cin.fail() || nr < linf) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}
	return nr;
}

float checkFloatBoundaries(float linf) {
	float nr;
	cin >> nr;

	while (cin.fail() || nr < linf) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}
	return nr;
}

void waitToContinue () {
    string waiting;

    cout << "\nPress any key to continue...\n";
    cin.ignore();
    getline(cin, waiting);
}


/*             MENUS          */

void mainMenu(Company &companyName) {
	int choice = 0;
	
	while (choice != 7) {
		cout << "____________________________________________________" << endl;
		cout << "|                  MAIN MENU                       |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Manage Planes                             |" << endl;
		cout << "|     2) Manage Flights                            |" << endl;
		cout << "|     3) Manage Passengers                         |" << endl;
		cout << "|     4) Manage Reservations                       |" << endl;
		cout << "|     5) Manage Maintenance                        |" << endl;
        cout << "|     6) Manage Tecnhicians                        |" << endl;
		cout << "|     7) Exit                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 7);


		switch (choice) {
		case 1:
			planesMenu(companyName);
			break;

		case 2:
			flightsMenu(companyName);
			break;

		case 3:
			passengersMenu(companyName);
			break;

		case 4:
			reservationsMenu(companyName);
			break;

		case 5:
			maintenanceMenu(companyName);
			break;

            case 6:
                technicianMenu(companyName);
                break;


		case 7:
			cout << endl;
			companyName.logOut();
			cout << "See you next time!\n";
			break;
		}
	}
}

void planesMenu(Company &companyName) {
	int choice = 0;

	while (choice != 6) {
		try {
            cout << "____________________________________________________" << endl;
            cout << "|                   MANAGE PLANES                  |" << endl;
            cout << "|                                                  |" << endl;
            cout << "|        Type your option:                         |" << endl;
            cout << "|     1) Add Plane                                 |" << endl;
            cout << "|     2) Delete Plane                              |" << endl;
            cout << "|     3) Print Flights of a Plane                  |" << endl;
            cout << "|     4) Print Plane Information                   |" << endl;
            cout << "|     5) Print All Planes                          |" << endl;
            cout << "|     6) Go Back to Main Menu                      |" << endl;
            cout << "|    Option: ";
            choice = checkBoundaries(1, 6);

            switch (choice) {
                case 1:
                    cout << endl;
                    addPlane(companyName);
                    waitToContinue();
                    break;

                case 2:
                    cout << endl << endl;
                    deletePlane(companyName);
                    waitToContinue();
                    break;

                case 3:
                    cout << endl << endl;
                    printFlights(companyName);
                    waitToContinue();
                    break;

                case 4:
                    cout << endl << endl;
                    printPlaneInformation(companyName);
                    waitToContinue();
                    break;

                case 5:
                    cout << endl << endl;
                    printAllPlanes(companyName);
                    waitToContinue();
                    break;
            }

        } catch (OperationCanceled &e) {
            cout << "Operation was canceled\n";
        }
	}
}

void flightsMenu(Company &companyName) {
	int choice = 0;

	while (choice != 6) {
		try {
			cout << "____________________________________________________" << endl;
			cout << "|                MANAGE FLIGHTS                    |" << endl;
			cout << "|                                                  |" << endl;
			cout << "|        Type your option:                         |" << endl;
			cout << "|     1) Create Flight                             |" << endl;
			cout << "|     2) Cancel Flight                             |" << endl;
			cout << "|     3) Postpone Flight                           |" << endl;
			cout << "|     4) Display all existing flights              |" << endl;
            cout << "|     5) Display flights of an airport              |" << endl;
			cout << "|     6) Go Back to Main Menu                      |" << endl;
			cout << "|    Option: ";

			choice = checkBoundaries(1, 6);



			switch (choice) {
			case 1:
				cout << endl;
				addFlight(companyName);
                    waitToContinue();
				break;

			case 2:
				cout << endl << endl;
				cancelFlight(companyName);
                    waitToContinue();
				break;

			case 3:
				cout << endl << endl;
				postponeFlight(companyName);
                    waitToContinue();
				break;

			case 4:
				cout << endl << endl;
				printAllFlights(companyName);
                    waitToContinue();
				break;

                case 5:
                    cout << endl << endl;
                    printFlightsAirport(companyName);
                    waitToContinue();
                    break;
			}
		}
		catch (OperationCanceled &e) {
			cout << "Operation was canceled\n";
		}
        catch (Repeated &f) {

            string createPlane;
            cout << "There's no plane available for that time" << endl
                 << "Do you wish to add one plane to the company (y/n)? ";
            cin >> createPlane;

            if (createPlane == "0")
                throw OperationCanceled();

            else if (createPlane == "y" || createPlane == "Y") {
                addPlane(companyName);
            }

            else if (createPlane != "n" && createPlane != "N") {
                cout << "Operation not successfull\n";
            }
        }
	}
}

void passengersMenu(Company &companyName) {
	int choice = 0;

	while (choice != 8) {
        try {
            cout << "____________________________________________________" << endl;
            cout << "|              MANAGE PASSENGERS                   |" << endl;
            cout << "|                                                  |" << endl;
            cout << "|        Type your option:                         |" << endl;
            cout << "|     1) Add Passenger                             |" << endl;
			cout << "|     2) Change Phone Number                       |" << endl;
			cout << "|     3) Delete Passenger                          |" << endl;
            cout << "|     4) Print Passenger Reservations              |" << endl;
            cout << "|     5) Print Passenger Informations              |" << endl;
			cout << "|     6) Print Inactive Passengers                 |" << endl;
			cout << "|     7) Print All Passengers                      |" << endl;
			cout << "|     8) Back to Main Menu                         |" << endl;
			cout << "|    Option: ";

            choice = checkBoundaries(1, 8);


            switch (choice) {
                case 1:
                    cout << endl;
                    addPassenger(companyName);
                    waitToContinue();
                    break;

				case 2:
					cout << endl << endl;
					changePhoneNumber(companyName);
                    waitToContinue();
					break;

                case 3:
                    cout << endl << endl;
                    deletePassenger(companyName);
                    waitToContinue();
                    break;

                case 4:
                    cout << endl << endl;
                    printPassengerReservations(companyName);
                    waitToContinue();
                    break;

				case 5:
					cout << endl << endl;
					printPassengerInformation(companyName);
                    waitToContinue();
					break;

                case 6:
                    cout << endl << endl;
					cout << "Inactive Passengers:\n\n";
					companyName.printInactivePassengers();
					waitToContinue();
                    break;

                case 7:
                    cout << endl << endl;
                    printAllPassengers(companyName);
                    waitToContinue();
                    break;

					
            }
        }
        catch (OperationCanceled &e) {
            cout << "Operation was canceled\n";
        }
	}
}

void reservationsMenu(Company &companyName) {
	int choice = 0;

	while (choice != 6) {
        try {
            cout << "______________________________________________________" << endl;
            cout << "|                  MANAGE RESERVATIONS               |" << endl;
            cout << "|                                                    |" << endl;
            cout << "|        Type your option:                           |" << endl;
            cout << "| 1) Make a reservation for a registred passenger    |" << endl;
            cout << "| 2) Make a reservations for an unregistred passenger|" << endl;
            cout << "| 3) Cancel a reservation                            |" << endl;
            cout << "| 4) Display a passengers reservations               |" << endl;
            cout << "| 5) Display all reservations                        |" << endl;
            cout << "| 6) Back to Main Menu                               |" << endl;
            cout << "|    Option: ";

            choice = checkBoundaries(1, 6);


            switch (choice) {
                case 1:
                    cout << endl;
                    addReservationToPass(companyName);
                    waitToContinue();
                    break;

                case 2:
                    cout << endl << endl;
                    addReservationAndNewPass(companyName);
                    waitToContinue();
                    break;

                case 3:
                    cout << endl << endl;
                    deleteReservation(companyName);
                    waitToContinue();
                    break;

                case 4:
                    cout << endl << endl;
                    printPassengerReservations(companyName);
                    waitToContinue();
                    break;

                case 5:
                    cout << endl << endl;
                    printAllReservations (companyName);
                    waitToContinue();
                    break;
            }
        }
        catch (OperationCanceled &e) {
            cout << "Operation was canceled\n";
        }


	}
}

void maintenanceMenu(Company &companyName) {
	int choice = 0;

	while (choice != 7) {
		try {
            cout << "____________________________________________________" << endl;
            cout << "|                   MANAGE MAINTENANCE             |" << endl;
            cout << "|                                                  |" << endl;
            cout << "|        Type your option:                         |" << endl;
            cout << "|     1) Do maintenance                            |" << endl;
            cout << "|     2) Cancel maintenance                        |" << endl;
            cout << "|     3) Postpone maintenance                      |" << endl;
            cout << "|     4) List maintenances to do                   |" << endl;
            cout << "|     5) List maintenances to do between 2 dates   |" << endl;
			cout << "|     6) List maintenances in the next days        |" << endl;
            cout << "|     7) Go Back to Main Menu                      |" << endl;
            cout << "|    Option: ";
            choice = checkBoundaries(1, 7);

			switch (choice) {
                case 1:
                    cout << endl;
                    doMaintenance (companyName);
                    waitToContinue();
                    break;

                case 2:
                    cout << endl;
					cancelMaintenance(companyName);
                    waitToContinue();
                    break;

                case 3:
                    cout << endl;
					postponeMaintenance(companyName);
                    waitToContinue();
                    break;

                case 4:
                    cout << endl;
                    companyName.maintenanceList();
                    waitToContinue();
                    break;

                case 5:
                    cout << endl;
					printMaintenancesOnDate(companyName);
                    waitToContinue();
                    break;
				case 6:
					cout << endl;
					printMaintenancesNextDays(companyName);
					break;

            }

		}
		catch (OperationCanceled &e) {
			cout << "Operation was canceled\n";
		}
	}
}

void technicianMenu (Company &companyName) {
    int choice = 0;

    while (choice != 5) {
        try {
            cout << "____________________________________________________" << endl;
            cout << "|                   MANAGE TECHNICIANS             |" << endl;
            cout << "|                                                  |" << endl;
            cout << "|        Type your option:                         |" << endl;
            cout << "|     1) Add technician                            |" << endl;
            cout << "|     2) Delete technician                         |" << endl;
            cout << "|     3) Print technician's information            |" << endl;
            cout << "|     4) Print all technicians                     |" << endl;
            cout << "|     5) Go Back to Main Menu                      |" << endl;
            cout << "|    Option: ";
            choice = checkBoundaries(1, 5);

            switch (choice) {
                case 1:
                    cout << endl;
					addTechnician(companyName);
                    waitToContinue();
                    break;

                case 2:
                    cout << endl;
					deleteTechnician(companyName);
                    waitToContinue();
                    break;

                case 3:
                    cout << endl;
					printTechnician(companyName);
                    waitToContinue();
                    break;

                case 4:
                    cout << endl;
					companyName.printAllTechnicians();
                    waitToContinue();
                    break;

            }

        }
        catch (OperationCanceled &e) {
            cout << "Operation was canceled\n";
        }
    }
}



/*             MANAGE PLANES        */

void addPlane(Company &companyName) {
    int places;
    string model;
    int maintenanceRate;
    int nextMaintenance;
    cout << "\nType 0 to cancel the operation\n";
    cout << "Nr of places (multiple of 6): ";
    places = checkBoundaries(0);

    if (places != 0) {

        if (places % 6 != 0) {
            places = places + (6 - places % 6);

            cout << "Number of places was round up to nearest multiple: " << places << endl;
        }

        cout << "Name of the model of the Plane \n";
        model = checkString(model);

        if (model == "0")
            throw OperationCanceled();

        cout << "Rate at which the plane must be inspected(in days): ";
        maintenanceRate = checkBoundaries(0);

        if (maintenanceRate == 0)
            throw OperationCanceled();
        nextMaintenance = maintenanceRate;




        Plane *adding = new Plane(places, model, maintenanceRate, Date::getNow() + nextMaintenance);
        companyName.addPlane(adding);

        cout << "\nThe plane was added successfully!\n\n";
        cout << "Plane Information\n"
             << *adding;
    } else
        throw OperationCanceled();
}

void deletePlane(Company &companyName) {
	int id;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Plane id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				Plane * deleting = companyName.deletePlane(id);
				cout << "\nThe plane was deleted successfully!\n\n";
				cout << "Plane Information\n"
					<< *deleting;

			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}
		}
		else {
			throw OperationCanceled();
		}

	} while (invalidInput);
}

void printFlights(Company &companyName) {
	int id, i;
	vector <Flight *> fls;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Plane id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {

			try {
				Plane *printing = companyName.searchPlane(id, i);
				printing->sortFlightsDate();
				fls = printing->getFlights();

				cout << "\nFlights of plane " << printing->getId() << "\n"
					<< fls << endl << endl;

			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}

		}
		else {
			throw OperationCanceled();
		}
	} while (invalidInput);

}

void printPlaneInformation(Company &companyName) {
	int id, i;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Plane id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				Plane *printing = companyName.searchPlane(id, i);
				printing->sortFlightsId();
                cout << "\nPlane Information\n"
					<< *printing << endl << endl;
			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}
		}
		else {
			throw OperationCanceled();
		}
	} while (invalidInput);
}

void printAllPlanes(Company &companyName) {
	vector <Plane *> pls = companyName.getPlanes();

    if (pls.size() == 0) {
        cout << endl << "The company doesn't have any plane\n\n";
    }

    else {

        for (unsigned int i = 0; i < pls.size(); i++) {
            cout << *pls.at(i) << endl;
        }
    }
}



/*             MANAGE FLIGHTS        */

void addFlight(Company &companyName) {
	string departAirp, arrAirp, dateStr, hourStr;
	DateFlight takeOff;
	bool invalDate;
	int duration, choice;
	float price;

	cout << "\nType 0 to cancel the operation\n";

	cin.ignore();
	cout << "Departure airport: ";
	getline(cin, departAirp);

	if (departAirp == "0")
		throw OperationCanceled();

	cout << "Arrival airport: ";
	getline(cin, arrAirp);

	if (arrAirp == "0")
		throw OperationCanceled();

	do {
		invalDate = false;

		cout << "Day of take off (year/month/day): ";
		getline(cin, dateStr);

        if (dateStr == "0")
            throw OperationCanceled();

        try {
            char aux;
            int year, month, day, hour, minutes;

            istringstream dateStream(dateStr);

            dateStream >> year >> aux >> month >> aux >> day;

            if (Date::past(year, month, day))
                throw InvalidDate (day, month, year);

            cout << "Hour of take off (hour:minutes): ";
            getline(cin, hourStr);

            if (hourStr == "0")
                throw OperationCanceled();

            istringstream hourStream(hourStr);

            hourStream >> hour >> aux >> minutes;
            takeOff.setDate(year, month, day, hour, minutes);

        }
        catch (InvalidDate &d) {
            cout << "Invalid date, " << d.getDate() << ". Try again" << endl;
            invalDate = true;
        }

	} while (invalDate);

	cout << "Duration of the flight (in min): ";
	duration = checkBoundaries(0);

	if (duration == 0)
		throw OperationCanceled();

	cout << "Type of flight: " << endl
		<< "[1] Commercial" << endl
		<< "[2] Private" << endl;

	choice = checkBoundaries(0, 2);

	if (choice == 0)
		throw OperationCanceled();

    if (choice == 1) {
        cout << "Price of one seat (euro): ";
        price = checkFloatBoundaries(0);

        if (price == 0)
            throw OperationCanceled();

        FCommercial * adding = new FCommercial (departAirp, arrAirp, takeOff, duration, price);

        companyName.addFlight(adding);

        cout << "Flight created with success!" << endl;
        cout << *adding;


    }
    else {
        cout << "Total price: ";
        price = checkFloatBoundaries(0);

        if (price == 0) {
            throw OperationCanceled();
        }

        FPrivate * adding  = new FPrivate (departAirp, arrAirp, takeOff, duration, price);

        companyName.addFlight(adding);

        cout << endl << "Flight created with success!" << endl;
        cout << *adding;

    }

}

void cancelFlight(Company &companyName) {
	int id;
	bool invalidInput;
	vector <Flight *> fls;
	vector<Plane *> pls = companyName.getPlanes();
	//Flight *printing = NULL;

	cout << "\nType 0 to cancel the operation\n"
		<< "Flight id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id == 0)
            throw OperationCanceled ();

        try {

            Flight * f = companyName.searchFlight(id);

            f->getPlane()->deleteFlight(id);

            cout << "\n\n\tFlight Information\n" << *f;

            /*bool done = false;
            unsigned int x, j;
            for (x = 0; x < pls.size(); x++) {
                for (j = 0; j < pls.at(x)->getFlights().size(); j++) {
                    if (id == pls.at(x)->getFlights().at(j)->getId()) {
                        Flight * f = pls.at(x)->deleteFlight(id);

                        done = true;
                        break;
                    }
                    if (done) break;
                }
                if (done) break;
            }
            if (!done) throw NoSuchFlight(id);*/



            cout << "\nThe flight was canceled successfully!\n\n";
        }
        catch (NoSuch &e) {
            cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
                 << "Try again: ";
            invalidInput = true;
        }

    } while (invalidInput);

}

void postponeFlight(Company &companyName) {
	int id;
	bool invalidInput, invalDate;
	int choice = 0;
	string dateStr, hourStr;
	DateFlight newDate;

	cout << "\nType 0 to cancel the operation\n"
		<< "Flight id: ";

	do {

		id = checkBoundaries(0);
		invalidInput = false;

		if (id == 0)
			throw OperationCanceled();
		
		try {
			Flight * searching = companyName.searchFlight(id);
		}
		catch (NoSuch &e) {
			cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
				<< "Try again: ";
			invalidInput = true;
		}

	} while (invalidInput);

	cout << "Postpone: " << endl
		<< "[1] Departure hour" << endl
		<< "[2] Arrival hour" << endl;

	choice = checkBoundaries(0, 2);

	if (choice == 0)
		throw OperationCanceled();

	Flight * searching = companyName.searchFlight(id);

	if (choice == 1) {

		cin.ignore();

        do {
            invalDate = false;

            cout << "Day of take off (year/month/day): ";
            getline(cin, dateStr);

            if (dateStr == "0")
                throw OperationCanceled();

            try {
                char aux;
                int year, month, day, hour, minutes;

                istringstream dateStream(dateStr);

                dateStream >> year >> aux >> month >> aux >> day;

                if (Date::past(year, month, day))
                    throw InvalidDate (day, month, year);

                cout << "Hour of take off (hour:minutes): ";
                getline(cin, hourStr);

                if (hourStr == "0")
                    throw OperationCanceled();

                istringstream hourStream(hourStr);

                hourStream >> hour >> aux >> minutes;
                newDate.setDate(year, month, day, hour, minutes);

            }
            catch (InvalidDate &d) {
                cout << "Invalid date, " << d.getDate() << ". Try again" << endl;
                invalDate = true;
            }

        } while (invalDate);

        id = searching->getPlane()->getId();

        searching->getPlane()->deleteFlight(searching->getId());
        companyName.addFlight(searching);

        if (id != searching->getPlane()->getId()) {

            cout << "\nThe plane's flight was changed due to schedule conflicts\n";
        }

		cout << "\nThe flight was postponed successfully!\n\n";
        cout << *searching << endl;

	}
	else {
		cout << "\nNr of minutes delayed: ";
		int duration = checkBoundaries(0);

		if (duration == 0)
			throw OperationCanceled();

		searching->getPlane()->postponeFlight(searching, duration);

		cout << "\nThe flight was postponed successfully!\n\n";
        cout << *searching << endl;

	}

}

void printAllFlights(Company &companyName) {
	vector <Flight *> fls;
	vector<Plane *> pls = companyName.getPlanes();

	for (unsigned int i = 0; i < pls.size(); i++) {
		Plane *printing = pls.at(i);
		printing->sortFlightsDate();
		fls = printing->getFlights();

		cout << "\nFlights of plane " << printing->getId() << "\n" << fls << endl << endl;
	}
}

void printFlightsAirport (Company &companyName) {
    string idAirport;
    vector<Flight*> airportFlights;

    cout << "\nType 0 to cancel the operation\n";

    cout << "Choose your airport: \n";
    cin.ignore();

        getline(cin, idAirport);

        if (idAirport == "0"){
            throw OperationCanceled();
        }

        airportFlights = companyName.getAirportsAllFlights(idAirport);

        if (airportFlights.size() != 0){

            cout << airportFlights << endl;
        }
        else {
            cout << "There's no flight from or to that airport. ";
        }

}



/*             MANAGE PASSENGERS        */

void addPassenger(Company &companyName) {
	string job, name;
	int day, year, month;
    cout << "\nType 0 to cancel the operation\n";
	cout << "Name of the passenger: \n";

	name = checkString(name);

    if (name == "0") {
        throw OperationCanceled ();
    }

	cout << "Day of birth \n";
	day = checkBoundaries(0, 31);

    if (day == 0)
        throw OperationCanceled ();

	cout << "Month of birth \n";
	month = checkBoundaries(0, 12);

    if (month == 0)
        throw OperationCanceled ();

	cout << "Year of birth: \n";
	year = checkBoundaries(0, 2017);

    if (year == 0) {
        throw OperationCanceled ();
    }

	Date anniversary(year, month, day);

	cout << "Job of the passenger: \n";

	job = checkString(job);

	if (job == "0")
		throw OperationCanceled();

	string phoneNumber;
	cout << "Phone Number: \n";
	cin >> phoneNumber;
	
	if (phoneNumber == "0")
		throw OperationCanceled();	

	PassengerWCard * adding = new PassengerWCard(name, job, anniversary);
	if (!adding->setPhoneNumber(phoneNumber)) {
		cout << "\nWrong phone number! \n";
		throw OperationCanceled();
	}

	companyName.addPassenger(adding);
	companyName.addToHashTable(adding);

	cout << "Passenger added sucessfully! \n"
		<< "Passenger information: \n\n"
		<< *adding;

}

void changePhoneNumber(Company & companyName) {
	int id, i;
	bool invalidInput;

	do {

		cout << "\nType 0 to cancel the operation\n"
			<< "Passenger id: ";

		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				PassengerWCard * change = companyName.searchPassenger(id, i);
				cout << endl << "Passenger Information\n"
					<< *change << endl << endl;
				cout << "\nType 0 to cancel the operation\n"
					<< "new Phone Number: ";
				string phoneNumber;
				cin >> phoneNumber;
				if (phoneNumber == "0") {
					cout << "Operation canceled\n\n\n";
					continue;
				}

				bool cONT = false;

				for (size_t i = 0; i < companyName.getRegPassengers().size(); i++) {
					if (companyName.getRegPassengers()[i]->getPhoneNumber() == phoneNumber) {
						cout << "\nSomeone already has that number! Try again: \n";
						invalidInput = true;
						cONT = true;
						break;
					}
				}
				
				if (cONT) continue;

				if (!change->setPhoneNumber(phoneNumber)) {
					cout << "\nWrong phone number! Try again: \n";
					invalidInput = true;
					continue;
				}
				cout << "\nOperation successful!\n\n";
				cout << "Passenger Information\n"
					<< *change;

			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again:\n\n ";
				invalidInput = true;
			}
		}
		else {
			cout << "Operation canceled\n\n\n";
			invalidInput = false;
		}
	} while (invalidInput);
	
}

void deletePassenger(Company &companyName) {
	int id;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Passenger id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				PassengerWCard * deleting = companyName.deletePassenger(id);
				cout << "\nThe passenger was deleted successfully!\n\n";
				cout << "Passenger Information\n"
					<< *deleting;

				PassengerWCardPtr P;
				P.PassengerWCard = deleting;
				companyName.deleteFromHashTable(P);

			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}
		}
		else {
			cout << "Operation canceled\n\n\n";
			invalidInput = false;
		}
	} while (invalidInput);

}

void printPassengerReservations(Company &companyName) {
	int id, i;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Passenger id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				PassengerWCard *printing = companyName.searchPassenger(id, i);
                vector <Reservation *> passengerReservations = printing->getReserv();

                if (passengerReservations.empty())
					cout << "This passenger has no reservations" << endl;
				else
				{
					for (unsigned int j = 0; j < passengerReservations.size(); j++)
					{
                        cout << *passengerReservations.at(j) << endl;
					}
				}

			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}
		}
		else {
			cout << "Operation canceled\n\n\n";
			invalidInput = false;
		}

	} while (invalidInput);

}

void printPassengerInformation(Company &companyName) {
	int id, i;
	bool invalidInput;

	cout << "\nType 0 to cancel the operation\n"
		<< "Passenger id: ";

	do {
		id = checkBoundaries(0);
		invalidInput = false;

		if (id != 0) {
			try {
				PassengerWCard *printing = companyName.searchPassenger(id, i);
				cout << "\nPassenger Information\n"
					<< *printing << endl << endl;
			}
			catch (NoSuch &e) {
				cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
					<< "Try again: ";
				invalidInput = true;
			}
		}
		else {
			cout << "Operation canceled\n\n\n";
			invalidInput = false;
		}
	} while (invalidInput);

}

void printAllPassengers(Company &companyName) {
	vector <PassengerWCard *> pls = companyName.getRegPassengers();

	for (unsigned int i = 0; i < pls.size(); i++) {
		cout << *pls.at(i) << endl;
	}

}



/*			MANAGE RESERVATIONS			*/

void addReservationToPass(Company &companyName) {
	bool invalPass;
	int i,i2;
	unsigned int idPass, idFlight, idAirport;
	float price;
	int nOfFlights = Flight::getLastId();
	string seat;

    cout << "\nType 0 to cancel the operation\n";

	if (companyName.getRegPassengers().size() == 0)
	{
		cout << "There aren't any registered passengers \n";
		return;
	}
	
	do {
		invalPass = false;
		cout << "ID of the registred passenger:  \n";
		idPass = checkBoundaries(0);

        if (idPass == 0)
            throw OperationCanceled ();

		try {
			companyName.searchPassenger(idPass, i2);
		}
		catch (NoSuch &e) {
			cout << "There isn't a " << e.getType() << " with that id, " << e.getId() << endl
				<< "Try again: ";
			invalPass = true;
		}

	} while (invalPass);


	vector<vector<Flight*> > airportFlights = companyName.getAirportsFlights();

	cout << "Choose your airport: \n";
	idAirport = checkBoundaries(0, airportFlights.size() - 1);

	for (unsigned int j = 0; j < airportFlights[idAirport].size(); j++)
	{
		cout << *airportFlights[idAirport][j] << endl;
	}

	cout << "ID of the flight you wish to make a reservation: \n";
	bool invalidInput;
	do {

		idFlight = checkBoundaries(0, nOfFlights);

        if (idFlight == 0)
            throw OperationCanceled ();

		invalidInput = false;
		try
		{
			bool existsInAirport = false;
			for (unsigned int j = 0; j < airportFlights[idAirport].size(); j++)
			{
				if (airportFlights[idAirport][j]->getId() == idFlight)
					existsInAirport = true;
			}
			if (!existsInAirport)
				throw(NoSuchFlight(idFlight));
		}
		catch (NoSuch &e)
		{
			cout << "Invalid input, try again: ";
			invalidInput = true;
		}
	} while (invalidInput);
	Passenger * p1 = companyName.searchPassenger(idPass, i);
	PassengerWCard * pc1 = dynamic_cast<PassengerWCard*> (p1);
	Flight * f1 = companyName.searchFlight(idFlight);
	FCommercial * fc1 = dynamic_cast<FCommercial*> (f1);
	for (unsigned int j = 0; j < p1->getReserv().size(); j++)
	{
		if (p1->getReserv()[j]->getFlight()->getId() == fc1->getId())
		{
			cout << "You already have a reservation in this flight, are you sure you want to continue? (Y/N) \n";
			string response;
			cin.ignore(1, '\n');
			getline(cin, response);
			if (response == "Y" || response == "y")
				break;
			else
				return;
		}
	}


	fc1->fixSeats();
	fc1->showAvailableSeats();
	do {
		cout << "Choose your Seat: \n";
		getline(cin, seat);

        if (seat == "0") {
            throw OperationCanceled();
        }
		if (!fc1->seatAvailable(seat))
			cout << "This is not an available seat, please try again!\n";
	} while (!fc1->seatAvailable(seat));

	price = companyName.searchFlight(idFlight)->getPrice() - pc1->getDiscount(companyName.searchFlight(idFlight)->getPrice());
	
	Reservation * adding = new Reservation(f1, p1, price, seat);
	p1->addReservation(adding);

	cout << "Reservation added sucessfully! \n"
		<< "Reservation information: \n"
		<< *adding;

	fc1->addReservation(adding);

	DateFlight nowR = DateFlight::getNow();

	Date nowRDate(nowR.getYear(), nowR.getMonth(), nowR.getDay());

	pc1->setLastTicketBought(nowRDate);

	PassengerWCardPtr tmpPtr;
	tmpPtr.PassengerWCard = pc1;

	companyName.deleteFromHashTable(tmpPtr);

}

void addReservationAndNewPass(Company &companyName) {
	string name, seat;
	int day, year, month;
	int nOfFlights = Flight::getLastId();
	float price;
	unsigned int idFlight, idAirport;

    cout << "\nType 0 to cancel the operation\n";

	cout << "Name of the passenger: \n";

	name = checkString(name);

    if (name == "0")
        throw OperationCanceled ();

	cout << "Day of birth \n";
	day = checkBoundaries(0, 31);

    if (day == 0)
        throw OperationCanceled ();

	cout << "Month of birth \n";
	month = checkBoundaries(0, 12);

    if (month == 0)
        throw OperationCanceled ();

	cout << "Year of birth: \n";
	year = checkBoundaries(0, 2017);

    if (year == 0)
        throw OperationCanceled ();

	Date anniversary(year, month, day);

	Passenger * p1 = new Passenger(name, anniversary);

	PassengerWCard * pc1 = dynamic_cast<PassengerWCard*> (p1);

	vector<vector<Flight*> > airportFlights = companyName.getAirportsFlights();

	cout << "Choose your airport: \n";
	idAirport = checkBoundaries(0, airportFlights.size() - 1);

	for (unsigned int j = 0; j < airportFlights[idAirport].size(); j++)
	{
		cout << *airportFlights[idAirport][j] << endl;
	}

	cout << "ID of the flight you wish to make a reservation: \n";
	bool invalidInput;
	do {

		idFlight = checkBoundaries(0, nOfFlights);

        if (idFlight == 0)
            throw OperationCanceled();

		invalidInput = false;
		try
		{
			bool existsInAirport = false;
			for (unsigned int j = 0; j < airportFlights[idAirport].size(); j++)
			{
				if (airportFlights[idAirport][j]->getId() == idFlight)
					existsInAirport = true;
			}
			if (!existsInAirport)
				throw(NoSuchFlight(idFlight));
		}
		catch (NoSuch &e)
		{
			cout << "Invalid input, try again: ";
			invalidInput = true;
		}
	} while (invalidInput);

	Flight * f1 = companyName.searchFlight(idFlight);
	FCommercial * fc1 = dynamic_cast<FCommercial*> (f1);

	fc1->fixSeats();
	fc1->showAvailableSeats();
	cin.ignore(1000, '\n');
	do {
		cout << "Choose your Seat: \n";
		getline(cin, seat);

        if (seat == "0")
            throw OperationCanceled ();

		if (!fc1->seatAvailable(seat))
			cout << "This is not an available seat, please try again!\n";
	} while (!fc1->seatAvailable(seat));
	price = companyName.searchFlight(idFlight)->getPrice();
	Reservation * adding = new Reservation(f1, p1, price, seat);
	p1->addReservation(adding);

	cout << "Reservation added sucessfully! \n"
		<< "Reservation information: \n"
		<< *adding;

	fc1->addReservation(adding);

}

void deleteReservation(Company &companyName) {
	string name, seat;
	unsigned int idFlight;
	int nOfFlights = companyName.numOfFlights();
	
		cout << "Name of the Passenger to cancel a reservation: \n";
		name = checkString(name);

        if (name == "0")
            throw OperationCanceled ();

		cout << "Id of the Flight: \n";
		idFlight = checkBoundaries(0, nOfFlights);

        if (idFlight == 0)
            throw OperationCanceled ();

		cout << "Seat Number: \n";
		seat = checkString(seat);

        if (seat == "0")
            throw OperationCanceled ();

		Flight * f1 = companyName.searchFlight(idFlight);
		FCommercial * fc1 = dynamic_cast<FCommercial*> (f1);
		if(!fc1->removeReservation(seat, name))
		cout << "There isn't a reservation with this data \n";
		else
		{
			cout << "Reservation removed successfully \n";
		}

		//TODO: tratar da hash table aqui (nao sei ainda o que fazer aqui...)

}

void printAllReservations (Company &companyName) {
    vector<Flight *> temp;
    map <string, Reservation> temp2;
    cout << setw(5) << "Id" << setw (25) << "Name" << setw(15) << "Flight id" << setw(10) << "Seat" << endl;

    // goes through all the planes
    for (int i = 0; i < companyName.getPlanes().size(); i++) {

        // temporary variable to save the flights of the current plane
        temp = companyName.getPlanes().at(i)->getFlights();


        // goes through all the plane's flights
        for (int j=0; j < temp.size(); j++) {



            //tests if it is a Commercial flight
            if (temp[j]->getType() == "Commercial") {

                FCommercial * fc = dynamic_cast<FCommercial*> (temp[j]);



                // temporary variable to save the flight's reservations
                temp2 = fc->getReservations();


                // goes through all the flight's reservations
                for (auto it = temp2.begin(); it != temp2.end(); ++it)

                {
                    // if it is not a registered passenger saves the reservation in the vector noCard
                    if (it->second.getPassenger()->getType() == "noCard")
                    {
                        Passenger * p1 = it->second.getPassenger();
                        cout << setw(5) << "-" << setw(25) << p1->getName() << setw(15) << fc->getId() <<setw(10) << it->second.getSeat() << endl;
                    }
                    else
                    {
                        Passenger * p1 = it->second.getPassenger();
                        PassengerWCard * pc1 = dynamic_cast<PassengerWCard*> (p1);
                        cout << setw(5) << pc1->getId() << setw(25) << pc1->getName() << setw(15) << fc->getId() << setw(10) << it->second.getSeat() << endl;
                    }
                }
            }

        }
    }
}


/*			MANAGE TECHNICIANS */

void addTechnician (Company &companyName) {
    string name, model;
    int nrOfModels;
    vector <string> models;

    cout << "\nType 0 to cancel the operation\n";
    cout << "Name: ";
    name = checkString(name);

    if (name == "0")
        throw OperationCanceled ();

    cout << "Nr of model's that is qualified to repair: ";
    nrOfModels = checkBoundaries(0);

	if (nrOfModels == 0)
		throw OperationCanceled ();


	cin.ignore();

    for (int i = 0; i < nrOfModels; i++) {
        cout << "Model: ";
		getline(cin , model);

        if (model == "0")
            throw OperationCanceled ();

        models.push_back(model);
    }

    Technician t (name, models);

    companyName.addTechnician(t);

	cout << "\nTechnician added sucessfully! \n"
		 << "Technician information: \n"
		 << t;
}

void deleteTechnician (Company &companyName) {
	int id;
	bool notfound = true;

	cout << "\nType 0 to cancel the operation\n";
	cout << "Id: ";

	while (notfound) {
		try {
			id = checkBoundaries(0);

			if (id == 0)
				throw OperationCanceled();


			Technician t = companyName.deleteTechnician(id);
			notfound = false;

			cout << "\nTechnician was deleted successfully\n"
				 << "Technician information\n"
				 << t;
		}
		catch (NoSuch &t) {
			cout << "There isn't a " << t.getType() << " with that id, " << t.getId() << endl
				 << "Try again: ";
		}
	}
}

void printTechnician (Company &companyName) {
	int id;
	bool notfound = true;

	cout << "\nType 0 to cancel the operation\n";
	cout << "Id: ";

	while (notfound) {
		try {
			id = checkBoundaries(0);

			if (id == 0)
				throw OperationCanceled();


			Technician t = companyName.searchTechnician(id);
			notfound = false;

			cout << "\nTechnician information: \n"
				 << t;
		}
		catch (NoSuch &t) {
			cout << "There isn't a " << t.getType() << " with that id, " << t.getId() << endl
				 << "Try again: ";
		}
	}
}

/*       MANAGE MAINTENANCE       */
void doMaintenance (Company &companyName) {
    int planeId, aux;
    bool thereAre = true;

    cout << "\nType 0 to cancel the operation\n";

    cout << "Today's maintenance:\n\n";

    thereAre = companyName.maintenanceList(Date::getNow(), Date::getNow());

	if (!thereAre) {
		cout << "There's no maintenance schedule for today.\n";
	}

    cout << "Id of the plane: ";
    planeId = checkBoundaries(0);

	if (planeId == 0)
		throw OperationCanceled();

    while (!companyName.doMaintenance(planeId)) {
		cout << "There isnt a Plane with that Id, try again:\n";

		planeId = checkBoundaries(0);

		if (planeId == 0)
			throw OperationCanceled();
    }

	companyName.deleteTechMaintenance(planeId);
	companyName.scheduleMaintenance(companyName.searchPlane(planeId, aux));
	cout << "Maintenance done with success\n";
}

void cancelMaintenance(Company &companyName){
	int id;

	cout << "\nType 0 to cancel the operation\n";
	cout << "Id of the plane: ";
    id = checkBoundaries(0);

    if (id == 0)
        throw OperationCanceled();


	while (! companyName.cancelMaintenance(id)) {
        cout << "There isnt a Plane with that Id, try agian:\n";
        
        id = checkBoundaries(0);

        if (id == 0)
            throw OperationCanceled();

    }
    cout << "Maintenance Canceled with sucess! \n";

}

void printMaintenancesOnDate(Company &companyName){
	int days;
	bool invalDate;
	string  dateStr;
	string date2Str;
	cout << "\nType 0 to cancel the operation\n";
	cin.ignore();
	do {
		invalDate = false;

		cout << "List maintenance to do from (Insert date year/month/day): ";
		getline(cin, dateStr);

		if (dateStr == "0")
			throw OperationCanceled();

		try {
			char aux;
			int year, month, day;

			istringstream dateStream(dateStr);

			dateStream >> year >> aux >> month >> aux >> day;
			Date start = Date(year, month, day);

			if (Date::past(year, month, day))
				throw InvalidDate(year, month, day);

			cout << "to (Insert date year/month/day): ";
			getline(cin, date2Str);

			if (date2Str == "0")
				throw OperationCanceled();

			istringstream date2Stream(date2Str);

			date2Stream >> year >> aux >> month >> aux >> day;
			if (Date::past(year, month, day))
				throw InvalidDate(day, month, year);
			Date end = Date(year, month, day);
			if (end < start)
			{
				Date temp;
				temp = start;
				start = end;
				end = temp;
			}
			companyName.maintenanceList(start, end);

		}
		catch (InvalidDate &d) {
			cout << "Invalid date, " << d.getDate() << ". Try again" << endl;
			invalDate = true;
		}

	} while (invalDate);
}

void postponeMaintenance(Company &companyName) {
	bool invalDate;
	string  dateStr;
	int id;
	bool notfound = true;

	cout << "\nType 0 to cancel the operation\n";
	cout << "Id of the plane: ";
	
	id = checkBoundaries(0);

	if (id == 0)
		throw OperationCanceled();

	cin.ignore();
	do {
		invalDate = false;

		cout << "New date for the maintenance (Insert date year/month/day): ";
		getline(cin, dateStr);

		if (dateStr == "0")
			throw OperationCanceled();

		try {
			char aux;
			int year, month, day;

			istringstream dateStream(dateStr);

			dateStream >> year >> aux >> month >> aux >> day;
			Date newDate = Date(year, month, day);

			if (Date::past(year, month, day))
				throw InvalidDate(year, month, day);

			if (companyName.postponeMaintenance(id, newDate))
				cout << "Maintenance Postponed with success! \n";
			else
				cout << "There isnt a Plane with that Id \n";

		}
		catch (InvalidDate &d) {
			cout << "Invalid date, " << d.getDate() << ". Try again" << endl;
			invalDate = true;
		}

	} while (invalDate);
}

void printMaintenancesNextDays(Company &companyName) {
	bool invalDate;
	string  dateStr;
	int days;
	bool notfound = true;

	cout << "\nType 0 to cancel the operation\n";
	cout << "List the maintenances to do in the next (Insert days): ";

	days = checkBoundaries(0);

	if (days == 0)
		throw OperationCanceled();

	companyName.maintenanceList(days);
}

/*         OPERATOR OVERLOADING       */

ostream& operator<< (ostream &os, const PassengerWCard &p) {
	os << "Id: " << p.id << endl
		<< "Name : " << p.getName() << endl
		<< "Job : " << p.job << endl
		<< "Date of Birth: " << p.getDateBirth() << endl
		<< "Phone Number: " << p.getPhoneNumber() << endl
		<< "Last Ticket Bought: " << p.getLastTicketBought().getDate() << endl
		<< "Average Flights per year: " << p.getAverageFlight() << endl;


	return os;
}


int main()
{
	Company ryanair("passengers.txt", "planes.txt","reserv.txt", "techs.txt");
	ryanair.updateHashTable();
	mainMenu(ryanair);
	return 0;
}
