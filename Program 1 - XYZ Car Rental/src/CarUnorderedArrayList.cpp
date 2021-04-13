#include <string>
#include "CarUnorderedArrayList.hpp"

void CarUnorderedArrayList::makeEmpty()
{
	length = 0;
}

void CarUnorderedArrayList::putCar(Car car)
{
	data[length++] = car;
}

Car& CarUnorderedArrayList::getCar(Car car)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == car)
			return data[i];
	}
	throw "\nCar not found";										//throw error message if car is not found in the data[] array
}

Car& CarUnorderedArrayList::getCar(string plateNumber)
{
	return getCar(Car(plateNumber, "", "", sedan, 0.0, true));		//arbitrary values for make, model, vehicleType, pricePerDay, isAvailable
}																	
																	
void CarUnorderedArrayList::deleteCar(Car car)						
{																	
	for (int i = 0; i < length; i++)								
	{																
		if (data[i] == car)											
		{															
			data[i] = data[--length];								
			return;													
		}															
	}																
	throw "\nCar not found - cannot be deleted";					//throw error message if car is not found in the data[] array
}																	
																	
void CarUnorderedArrayList::resetList()								
{																	
	currentPos = 0;													
}																	
																	
Car CarUnorderedArrayList::getNextCar()								
{																	
	if (currentPos < length)											
	{																					
		return data[currentPos++];													
	}																		
	throw "\nOut of range";											//throw error message if the current position is outside the data[] array
}

int CarUnorderedArrayList::getLength()
{
	return length;
}

Car& CarUnorderedArrayList::getCarAtIndex(int index)
{
	return data[index];
}

CarUnorderedArrayList::~CarUnorderedArrayList()
{
}

ostream& operator<<(ostream& os, CarUnorderedArrayList& carList)
{
	carList.resetList();
	os << "Car List: [";
	for (int i = 0; i < carList.getLength(); i++)
	{
		os << "(" << carList.getNextCar() << ")";
		if (i < carList.getLength() - 1) os << "," << "\n           ";
	}
	os << "]";
		return os;
}
