#include <iostream>
#include <string>
#include "Program.hpp"

using namespace std;

void Program::menu()
{
	cout << "------------------------------------------- XYZ Car Rental -------------------------------------------" << endl;
	cout << "1. List all cars\n" <<
			"2. Add car to inventory\n" <<
			"3. Remove car from inventory\n" <<
			"4. List all reservations\n" << 
			"5. Add a reservations\n" <<
			"6. Cancel reservation\n" <<
			"7. Exit" << endl << endl;
	
	int optionNumber;
	cout << "Please choose the number of the option you want: ";
	cin >> optionNumber;
	cout << endl;

	this->optionNumber = optionNumber;
	outcome();
}

void Program::outcome()
{
	string plateNumber; 
	string make;
	string model;
	string type;
	VehicleType vehicleType; 
	double pricePerDay;
	bool isAvailable;

	string name;

	switch (optionNumber)
	{
	case 1:
	{
		cout << *carList << endl << endl;
		break;
	}
	case 2:
	{
		cout << "Please enter the following information:" << endl << endl;

		cout << "Plate Number: ";
		cin >> plateNumber;

		cout << "Make: ";
		cin >> make;

		cout << "Model: ";
		cin >> model;

		//checks that the user inputs a valid vehicle type
		do
		{
			cout << "Vehicle Type (sedan, suv, exotic): ";
			cin >> type;

			if (type == "sedan")
				vehicleType = sedan;
			else if (type == "suv")
				vehicleType = suv;
			else if (type == "exotic")
				vehicleType = exotic;
		} while (type != "sedan" && type != "suv" && type != "exotic");

		//checks that the user inputs a valid price
		do
		{
			cout << "Price per day: $";
			cin >> pricePerDay;
		} while (pricePerDay < 0);


		cout << "Is car available (1 for Yes, 0 for No): ";
		cin >> isAvailable;

		carList->putCar(Car(plateNumber, make, model, vehicleType, pricePerDay, isAvailable));

		cout << "\nCar added to the inventory successfully" << endl << endl;
		break;
	}
	case 3:
	{
		cout << "Please enter the plate number of the car: ";
		cin >> plateNumber;

		//try catch block: if the user tries to delete a car that is not in the list
		try
		{
			Car tempCar = carList->getCar(plateNumber);
			if (tempCar.getIsAvailable())
			{
				carList->deleteCar(tempCar);
				cout << "\nCar removed from inventory successfully" << endl << endl;
			}
			else
				cout << "\nCar is not available - cannot be deleted" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
		break;
	}
	case 4: 
	{
		//prints the entire reservation list with each renter's name and car details
		reservationList->resetList();

		cout << "Reservation List: [";
		for (int i = 0; i < reservationList->getLength(); i++)
		{
			Reservation tempReservation = reservationList->getNextReservation();
			Car tempCar = carList->getCar(tempReservation.getVehicleRented());

			cout << "(" << tempReservation << ", " << tempCar << ")";
			if (i < (reservationList->getLength() - 1)) cout << "," << "\n                   ";
		}
		cout << "]" << endl << endl;
		break;
	}
	case 5:
	{
		int counter = 1;							//represents the option number of the cars that are available
		int count[100] = {};						//stores the counter of the available cars

		int option;									//option number of the car that the user would want to reserve

		bool flag = true;							//flag is set to true

		cout << "Please enter your name: ";
		cin >> name;

		cout << "\nCars available to rent: " << endl;

		carList->resetList();

		for (int i = 0; i < carList->getLength(); i++)
		{
			Car tempCar = carList->getNextCar(); 

			if (tempCar.getIsAvailable())
			{
				cout << counter << ". " << tempCar.getMake() << " " << tempCar.getModel();
				if (tempCar.getType() == 0)
					cout << " (sedan) ";
				else if (tempCar.getType() == 1)
					cout << " (suv) ";
				else if (tempCar.getType() == 2)
					cout << " (exotic) ";
				cout << "$" << tempCar.getPricePerDay() << "/day" << endl;
				count[i] = counter++;				//stores the counter (option number) in the same index corresponding to the car in the array list
			}
		}
		cout << counter << ". Cancel" << endl << endl;

		cout << "Please select an option: ";
		cin >> option;
		
		if (option == counter)						//counter is equal to the last option which is Cancel so it returns to the main menu
			cout << "\nReturning to menu" << endl << endl;
		else
		{
			for (int j = 0; j < carList->getLength(); j++)
			{
				if (count[j] == option)				//index j where the counter/option is stored is the same index where the corresponding car is stored in the array list
				{
					Car& tempCar = carList->getCarAtIndex(j);
					reservationList->putReservation(Reservation(name, tempCar.getPlateNumber()));
					tempCar.setAvailable(false);
					cout << "\nReservation added successfully" << endl << endl;
					flag = false;					//flag is set to false if the user select a valid option
					break;
				}
			}
			if (flag)								//prints error message if the user does not select a valid option
				cout << "Invalid option" << endl << endl;
		}
		break;
	}
	case 6:
	{
		cout << "Please enter your name: ";
		cin >> name;

		//try catch block: if the user tries to delete a reservation that is not in the list
		try
		{
			Reservation tempReservation = reservationList->getReservation(name);
			reservationList->deleteReservation(tempReservation);

			Car& tempCar = carList->getCar(tempReservation.getVehicleRented());
			tempCar.setAvailable(true);

			cout << "\nReservation removed successfully" << endl << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl << endl;
		}
		break;
	}
	case 7:
	{
		cout << "Thank you for using XYZ Car Rental" << endl;
		exit(0);
	}
	}
	menu();
}
