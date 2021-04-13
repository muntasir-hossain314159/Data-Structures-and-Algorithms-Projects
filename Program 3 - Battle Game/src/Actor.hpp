#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MoveType.hpp"

using namespace std;

class Actor {
private:
    string type;
protected:
    int health;
    vector<MoveType> moves; 

public:
    Actor(int health, string type) :
        health{ health },
        type{ type }
    {}

    int getHealth() { return health; } //returns the health of the actor

    virtual void Hit(int damage)
    {
        health -= damage;
    }

    virtual void Heal(int amount)
    {
        health += amount;
    }

    vector<MoveType>& GetMoves() {
        return moves;
    }

    bool IsDead() { return health <= 0; }

    friend ostream& operator<<(ostream& out, const Actor& actor); 
};

