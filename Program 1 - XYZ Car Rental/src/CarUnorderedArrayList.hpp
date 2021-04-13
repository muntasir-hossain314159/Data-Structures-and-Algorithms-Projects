#pragma once
#include <iostream>
#include <string>
#include "Car.hpp"

#define MAX_ELEMS 100

class CarUnorderedArrayList
{
private:
	int currentPos;
	int length;
	Car data[MAX_ELEMS];

public:
	CarUnorderedArrayList() : currentPos{ -1 }, length{ 0 } {};
	void makeEmpty();
	void putCar(Car car);
	Car& getCar(Car car);
	Car& getCar(string plateNumber);
	void deleteCar(Car car);
	void resetList();
	Car getNextCar();
	int getLength();
	Car& getCarAtIndex(int index);
	~CarUnorderedArrayList();
};
ostream& operator<<(ostream& os, CarUnorderedArrayList& carList);