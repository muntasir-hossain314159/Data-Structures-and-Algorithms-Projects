#include "SlotMachine.hpp"
#include <time.h>

void SlotMachine::putSymbols()
{
	reel1->putItem('A');
	reel1->putItem('A');
	reel1->putItem('A');
	reel1->putItem('A');
	reel1->putItem('B');
	reel1->putItem('B');
	reel1->putItem('B');
	reel1->putItem('C');
	reel1->putItem('C');
	reel1->putItem('7');

	reel2->putItem('A');
	reel2->putItem('A');
	reel2->putItem('A');
	reel2->putItem('A');
	reel2->putItem('B');
	reel2->putItem('B');
	reel2->putItem('B');
	reel2->putItem('C');
	reel2->putItem('C');
	reel2->putItem('7');
	
	reel3->putItem('A');
	reel3->putItem('A');
	reel3->putItem('A');
	reel3->putItem('A');
	reel3->putItem('B');
	reel3->putItem('B');
	reel3->putItem('B');
	reel3->putItem('C');
	reel3->putItem('C');
	reel3->putItem('7');
}

void SlotMachine::spin()
{
	srand(time(NULL));

	int randomNumber1 = rand() % 100 + 1;
	int randomNumber2 = rand() % 100 + 1;
	int randomNumber3 = rand() % 100 + 1;

	//if any of the reels are empty, then throw an error message
	if (pointer1 == nullptr || pointer2 == nullptr || pointer3 == nullptr) 
		throw "No symbols inputted in Reel";

	for (int i = 0; i < randomNumber1; i++)
	{
		pointer1 = pointer1->next;
	}

	for (int i = 0; i < randomNumber2; i++)
	{
		pointer2 = pointer2->next;
	}

	for (int i = 0; i < randomNumber3; i++)
	{
		pointer3 = pointer3->next;
	}
}

char SlotMachine::currentPtr1()
{
	//if reel1 is empty, then throw an error message
	if (pointer1 == nullptr)
		throw "No symbols inputted in Reel 1";
	return pointer1->data;
}

char SlotMachine::currentPtr2()
{
	//if reel2 is empty, then throw an error message
	if (pointer2 == nullptr)
		throw "No symbols inputted in Reel 2";
	return pointer2->data;
}

char SlotMachine::currentPtr3()
{
	//if reel3 is empty, then throw an error message
	if (pointer3 == nullptr)
		throw "No symbols inputted in Reel 3";
	return pointer3->data;
}
