#pragma once
#include "Actor.hpp"
#include "BattleMove.hpp"
#include "CurseAttack.hpp"
#include "SwordAttack.hpp"
#include "SpellAttack.hpp"
#include "MeleeAttack.hpp"
#include "MoveType.hpp"

class BattleMoveFactory
{
public:
    static BattleMove* BuildMove(MoveType moveType, Actor* attacker, Actor* target) {
        BattleMove* battleMove = nullptr; 
        switch (moveType) {
        case MoveType::Curse:
            battleMove = new CurseAttack(attacker, target); 
            break;
        case MoveType::Sword:
            battleMove = new SwordAttack(attacker, target);
            break;
        case MoveType::Spell:
            battleMove = new SpellAttack(attacker, target);
            break;
        case MoveType::Melee:
            battleMove = new MeleeAttack(attacker, target);
            break;
        }
        return battleMove;
    }
};
