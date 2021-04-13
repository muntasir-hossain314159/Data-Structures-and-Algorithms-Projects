#pragma once
#include <iostream>
#include <string>
#include "Reservation.hpp"

#define MAX_ELEMS 100

class ReservationUnorderedArrayList
{
private:
	int currentPos;
	int length;
	Reservation data[MAX_ELEMS];

public:
	ReservationUnorderedArrayList() : currentPos{ -1 }, length{ 0 } {};
	void makeEmpty();
	void putReservation(Reservation reservation);
	Reservation getReservation(Reservation reservation);
	Reservation getReservation(string name);
	void deleteReservation(Reservation reservation);
	void resetList();
	Reservation getNextReservation();
	int getLength();
	~ReservationUnorderedArrayList();
};
ostream& operator<<(ostream& os, ReservationUnorderedArrayList& reservationList);