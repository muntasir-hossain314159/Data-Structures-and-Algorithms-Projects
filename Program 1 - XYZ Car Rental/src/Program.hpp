#pragma once
#include "Car.hpp"
#include "CarUnorderedArrayList.hpp"
#include "Reservation.hpp"
#include "ReservationUnorderedArrayList.hpp"

class Program
{
private:
	int optionNumber;																		//menu option number selected by the user
	CarUnorderedArrayList* carList = new CarUnorderedArrayList();							
	ReservationUnorderedArrayList* reservationList = new ReservationUnorderedArrayList();	
																							
public:																						
	void menu();																			//displays menu and prompts the user to select an option
	void outcome();																			//provides an outcome based on the option selected by the user
};

