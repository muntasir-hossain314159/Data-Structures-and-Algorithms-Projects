#pragma once
#include "CommandManager.hpp"
#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"
#include <vector>

using namespace std;

class Battle
{
private:
    CommandManager undoManager;
    Actor* player1;
    Actor* player2;

public:
    Battle(ActorType actor1, ActorType actor2) {

        player1 = ActorFactory::CreateActor(actor1);
        player2 = ActorFactory::CreateActor(actor2);

        //depending on player 1's type, particular moves are pushed to the vector "moves"
        switch (actor1)
        {
        case ActorType::Knight:
            player1->GetMoves().push_back(MoveType::Sword);
            player1->GetMoves().push_back(MoveType::Melee);
            break;
        case ActorType::Ghost:
            player1->GetMoves().push_back(MoveType::Curse);
            player1->GetMoves().push_back(MoveType::Spell);
            break;
        }

        //depending on player 2's type, particular moves are pushed to the vector "moves"
        switch (actor2)
        {
        case ActorType::Knight:
            player2->GetMoves().push_back(MoveType::Sword);
            player2->GetMoves().push_back(MoveType::Melee);
            break;
        case ActorType::Ghost:
            player2->GetMoves().push_back(MoveType::Curse);
            player2->GetMoves().push_back(MoveType::Spell);
            break;
        }
    }

    void Start();           //starts the battle
    void PlayerTurn();      //controls the player's moves    
    void NpcTurn();         //controls the computer's moves
};

