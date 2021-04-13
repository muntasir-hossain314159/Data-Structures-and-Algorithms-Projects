#pragma once
#include "BattleMove.hpp"
#include "Utils.hpp"

class CurseAttack: public BattleMove
{
private:
	int damage = Utils::randInt(5, 15);
public:
	CurseAttack(Actor* self, Actor* other) : BattleMove(self, other) {}; 
	void Execute(); 
	void Undo();
};

