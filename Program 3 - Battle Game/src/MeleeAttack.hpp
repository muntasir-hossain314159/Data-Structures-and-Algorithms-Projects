#pragma once
#include "BattleMove.hpp"
#include "Utils.hpp"

class MeleeAttack: public BattleMove
{
private:
	int damage = Utils::randInt(5, 15);
public:
	MeleeAttack(Actor* self, Actor* other) : BattleMove(self, other) {};
	void Execute();
	void Undo();
};

