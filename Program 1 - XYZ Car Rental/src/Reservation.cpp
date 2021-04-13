#include "Reservation.hpp"
#include "CarUnorderedArrayList.hpp"

Reservation::Reservation() {}

Reservation::Reservation(string name, string vehicleRented):
	name{name},
	vehicleRented{vehicleRented}
{}

string Reservation::getName() const { return name; }

string Reservation::getVehicleRented() const { return vehicleRented; }

bool Reservation::operator<(const Reservation& other)
{
	return name < other.name;
}

bool Reservation::operator==(const Reservation& other)
{
	return name == other.name;
}

ostream& operator<<(ostream& os, const Reservation& reservation)
{	
	os << "Renter Details: [Name: " << reservation.getName() << "]"; 
	return os;
}
