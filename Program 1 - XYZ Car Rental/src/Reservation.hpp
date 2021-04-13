#pragma once
#include <iostream>
#include <string>

using namespace std;

class Reservation
{
private:
	string name;				//key
	string vehicleRented;		//plate number of the vehicle rented

public:
	Reservation();

	Reservation(string name, string vehicleRented);

	string getName() const;

	string getVehicleRented() const;

	bool operator<(const Reservation& other);

	bool operator==(const Reservation& other);
};
ostream& operator<<(ostream& os, const Reservation& reservation);






