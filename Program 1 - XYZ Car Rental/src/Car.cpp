#include <string>
#include "Car.hpp"

Car::Car() {};

Car::Car(string plateNumber, string make, string model, VehicleType type, double pricePerDay, bool isAvailable): 
	plateNumber{plateNumber},
	make{make},
	model{model},
	pricePerDay{pricePerDay},
	type{type},
	isAvailable{isAvailable} 
{}

string Car::getPlateNumber() const { return plateNumber; }

string Car::getMake() const { return make; }

string Car::getModel() const { return model; }

VehicleType Car::getType() const { return type; }

double Car::getPricePerDay() const { return pricePerDay; }

bool Car:: getIsAvailable() const { return isAvailable; }

void Car::setAvailable(bool available) { isAvailable = available; }

bool Car::operator<(const Car& other)
{
	return plateNumber < other.plateNumber;
}

bool Car::operator==(const Car& other)
{
	return plateNumber == other.plateNumber;
}

ostream& operator<<(ostream& os, const Car& car)
{
	os << "Car Details: [Plate Number: " << car.getPlateNumber() << ", Make: " << car.getMake() << ", Model: " << car.getModel()
		<< ", Vehicle Type: ";
	if (car.getType() == 0)
		os << "Sedan";
	else if (car.getType() == 1)
		os << "SUV";
	else if (car.getType() == 2)
		os << "Exotic";
		os << ", Price per Day: $" << car.getPricePerDay() << ", Available: ";
	if (car.getIsAvailable()) os << "Yes";
	else os << "No";
		os << "]";
	return os;
}