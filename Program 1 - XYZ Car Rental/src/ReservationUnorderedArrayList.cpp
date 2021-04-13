#include "ReservationUnorderedArrayList.hpp"

void ReservationUnorderedArrayList::makeEmpty()
{
	length = 0;
}

void ReservationUnorderedArrayList::putReservation(Reservation reservation)
{
	data[length++] = reservation;
}

Reservation ReservationUnorderedArrayList::getReservation(Reservation reservation)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == reservation)
			return data[i];
	}
	throw "\nReservation not found";															//throw error message if reservation is not found in the data[] array
}																								
																																	
Reservation ReservationUnorderedArrayList::getReservation(string name)																			
{																															
	return getReservation(Reservation(name, ""));												//arbitrary value for vehicleRented
}																																			
																														
void ReservationUnorderedArrayList::deleteReservation(Reservation reservation)												
{																																	
	for (int i = 0; i < length; i++)																			
	{																												
		if (data[i] == reservation)																									
		{																																						
			data[i] = data[--length];																								
			return;																												
		}																																
	}																													
	throw "\nReservation not found - cannot be deleted";										//throw error message if reservation is not found in the data[] array
}

void ReservationUnorderedArrayList::resetList()
{
	currentPos = 0;
}

Reservation ReservationUnorderedArrayList::getNextReservation()
{
	if (currentPos < length)
		return data[currentPos++];
	throw "\nOut of Range";																		//throw error message if the current position is outside the data[] array
}


int ReservationUnorderedArrayList::getLength()
{
	return length;
}

ReservationUnorderedArrayList::~ReservationUnorderedArrayList()
{
}

ostream& operator<<(ostream& os, ReservationUnorderedArrayList& reservationList)
{
	reservationList.resetList();
	os << "Reservation List: [";
	for (int i = 0; i < reservationList.getLength(); i++)
	{
		os << "(" << reservationList.getNextReservation() << ")";
		if (i < reservationList.getLength() - 1) os << ", " << "\n                   ";
	}
	os << "]";
	return os;
}

