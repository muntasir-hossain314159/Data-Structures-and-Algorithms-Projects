#pragma once
#include "Reel.hpp"
#include <iostream>

using namespace std;

class SlotMachine
{
private:
	Reel<char>* reel1 = new Reel<char>();
	Reel<char>* reel2 = new Reel<char>();
	Reel<char>* reel3 = new Reel<char>();

	//current pointers to point to a particular node in the reel
	ReelNode<char>* pointer1 = nullptr; 
	ReelNode<char>* pointer2 = nullptr; 
	ReelNode<char>* pointer3 = nullptr;

public:
	SlotMachine()  
	{ 
		putSymbols(); 
		pointer1 = reel1->getReelNode();
		pointer2 = reel2->getReelNode();
		pointer3 = reel3->getReelNode();
		
		/*	Developer use:
		cout << *reel1 << endl;
		cout << *reel2 << endl;
		cout << *reel3 << endl;
		*/
	}
	void putSymbols();			//puts data values in the reel 
	void spin();				//generates 3 random numbers between 1 and 100, and increments the respective current pointers by the numbers  
	char currentPtr1();			//returns the value of pointer1
	char currentPtr2();			//returns the value of pointer2
	char currentPtr3();         //returns the value of pointer3
};



