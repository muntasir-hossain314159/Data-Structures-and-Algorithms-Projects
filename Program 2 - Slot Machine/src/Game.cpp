#include "SlotMachine.hpp"
#include "PayoutTable.hpp"

#include <iostream>
#include <string>

using namespace std;

void playSlots(int* balance, SlotMachine slotMachine, PayoutTable payoutTable)
{
	*balance -= 1;
	try
	{
		slotMachine.spin();
		cout << "[" << slotMachine.currentPtr1() << " " << slotMachine.currentPtr2() << " " << slotMachine.currentPtr3() << "]" << endl;
		int payout = payoutTable.calculatePayout(slotMachine);
		*balance += payout;
	}
	catch (const char* msg)
	{
		cout << "\n" << msg << endl;
		exit(0);
	}
	
}

void menu()
{
	int balance = 100;
	char response;

	SlotMachine slotMachine{};
	PayoutTable payoutTable{};

	cout << "------------------------------------------- Welcome to Virtual Slot Machine! -------------------------------------------" << endl;

	cout << "Spin or Quit (S for Spin/Q for Quit): ";
	cin >> response;
	response = toupper(response);

	while (response == 'S')
	{
		playSlots(&balance, slotMachine, payoutTable);
		cout << "Your current balance is $" << balance << endl << endl;

		if (balance <= 0)
		{
			cout << "You do not have sufficient funds to continue playing." << endl;
			break;
		}

		cout << "Spin or Quit (S for Spin/Q for Quit): ";
		cin >> response;
		response = toupper(response);
	}

	cout << "\n------ Game Over ------" << endl << endl;
	cout << "Your final balance is $" << balance << endl << endl;
	cout << "Thank you for playing!" << endl;
}

int main()
{
	menu();

	return 0;
}