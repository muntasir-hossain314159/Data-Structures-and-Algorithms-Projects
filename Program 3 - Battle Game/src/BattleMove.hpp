#pragma once
#include "UndoableCommand.hpp"

class BattleMove : public UndoableCommand {
public:
    BattleMove(Actor* self, Actor* other): self{ self }, other{ other }
    {}

protected:
    Actor* self;
    Actor* other;
};


