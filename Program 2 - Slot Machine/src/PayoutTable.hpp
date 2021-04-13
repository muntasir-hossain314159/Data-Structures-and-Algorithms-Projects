#pragma once
#include "SlotMachine.hpp"

class PayoutTable
{
private:
	int payout;
	
public:
	int calculatePayout(SlotMachine slotMachine);
};

