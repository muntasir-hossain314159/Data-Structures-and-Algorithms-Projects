#pragma once
#include <iostream>
#include <string>
#include "enums.hpp"

using namespace std;

class Car
{
private:
	string plateNumber; //key
	string make;
	string model;
	VehicleType type;
	double pricePerDay;
	bool isAvailable = true;

public:
	Car();

	Car(string plateNumber, string make, string model, VehicleType type, double pricePerDay, bool isAvailable);

	string getPlateNumber() const;

	string getMake() const;

	string getModel() const;

	VehicleType getType() const;

	double getPricePerDay() const;

	bool getIsAvailable() const;

	void setAvailable(bool available);

	bool operator<(const Car& other);

	bool operator==(const Car& other);
};
ostream& operator<<(ostream& os, const Car& car);
