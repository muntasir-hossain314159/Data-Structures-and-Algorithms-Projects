#pragma once
#include "BattleMove.hpp"
#include "Utils.hpp"

class SpellAttack: public BattleMove
{
private:
	int damage = Utils::randInt(0, 20);
public:
	SpellAttack(Actor* self, Actor* other) : BattleMove(self, other) {};
	void Execute();
	void Undo();
};

