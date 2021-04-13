#include "PayoutTable.hpp"
#include <iostream>

using namespace std;

int PayoutTable::calculatePayout(SlotMachine slotMachine)
{
	//returns the current value of the pointer
	char firstReel = slotMachine.currentPtr1();
	char secondReel = slotMachine.currentPtr2();
	char thirdReel = slotMachine.currentPtr3();

	if (firstReel == 'A' && secondReel == 'A' && thirdReel == 'A')
	{
		payout = 6;
		cout << "You won 6 dollars!" << endl;
	}
	else if (firstReel == 'B' && secondReel == 'B' && thirdReel == 'B')
	{
		payout = 15;
		cout << "You won 15 dollars!" << endl;
	}
	else if (firstReel == 'C' && secondReel == 'C' && thirdReel == 'C')
	{
		payout = 50;
		cout << "You won 50 dollars!" << endl;
	}
	else if (firstReel == '7' && secondReel == '7' && thirdReel == '7')
	{
		payout = 500;
		cout << "JACKPOT!" << endl;
	}
	else
	{
		payout = 0;
		cout << "No Winnings!" << endl;
	}

	return payout;
}