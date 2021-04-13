#include "Battle.hpp"
#include "Utils.hpp"
#include "Game.hpp"
#include <string>

void Battle::Start()
{
	while (!player1->IsDead() && !player2->IsDead())
	{
		PlayerTurn();
		if (player2->IsDead())
		{
			cout << *player1 << " (Player 1) is the Winner!\n" << *player2 << " (Player 2) is Dead!" << endl << endl;
			break;
		}
		cout << "------------------------------------------" << endl << endl;

		NpcTurn();
		if (player1->IsDead())
		{
			cout << *player2 << " (Player 2) is the Winner!\n" << *player1 << " (Player 1) is Dead!" << endl << endl;
			break;
		}
		cout << "------------------------------------------" << endl << endl;
	}

	Game::Menu(); 
}

void Battle::PlayerTurn()
{
	int play; 
	
	cout << *player1 << "'s (Player 1) Turn to Play!" << endl << endl;

	cout << "1. Attack\n"
		 << "2. Undo Move" << endl;
	cout << "Choose your play: ";
	cin >> play;

	if (play == 1)
	{
		int inputMove;
		vector<MoveType> moves = player1->GetMoves();
		
		do
		{
			cout << "\n1. " << Utils::moveDisplayName[moves[0]] << "\n" <<
					"2. "	<< Utils::moveDisplayName[moves[1]] << endl;

			cout << "Choose your move: ";
			cin >> inputMove;
			
			if (inputMove != 1 && inputMove != 2)
				cout << "Invalid Move" << endl;
		} 		
		while (inputMove != 1 && inputMove != 2);
			
		BattleMove* battleMove = BattleMoveFactory::BuildMove(moves[inputMove-1], player1, player2);

		cout << "\nResult:";
		undoManager.ExecuteCommand(battleMove);
		cout << " to " << *player2 << " (Player 2)" << endl;
		cout << *player1 << "'s (Player 1) health is " << player1->getHealth() << endl;
		cout << *player2 << "'s (Player 2) health is " << player2->getHealth() << endl << endl;
	}

	else if (play == 2)
	{
		cout << "\nMove Undone!" << endl << endl;
		cout << "Result:";
		undoManager.UndoCommand();
		cout << " for " << *player1 << " (Player 1)";
		undoManager.UndoCommand();
		cout << " for " << *player2 << " (Player 2)" << endl;
		cout << *player1 << "'s (Player 1) health is " << player1->getHealth() << endl;
		cout << *player2 << "'s (Player 2) health is " << player2->getHealth() << endl << endl;
		cout << "------------------------------------------" << endl << endl;
		PlayerTurn();
	}

	else
	{
		cout << "Invalid Input" << endl << endl;
		PlayerTurn();
	}
}

void Battle::NpcTurn()
{
	int randomMoveType = Utils::randInt(0, 1);
	vector<MoveType> moves = player2->GetMoves();

	cout << *player2 << "'s (Player 2) Turn to Play!" << endl << endl;
	
	cout << "1. " << Utils::moveDisplayName[moves[0]] << "\n"
		 <<	"2. " << Utils::moveDisplayName[moves[1]] << endl;
	cout << *player2 << "'s (Player 2) Move: " << Utils::moveDisplayName[moves[randomMoveType]] << endl;

	BattleMove* battleMove = BattleMoveFactory::BuildMove(moves[randomMoveType], player2, player1);

	cout << "\nResult:";
	undoManager.ExecuteCommand(battleMove);
	cout << " to " << *player1 << " (Player 1)" << endl;
	cout << *player1 << "'s (Player 1) health is " << player1->getHealth() << endl;
	cout << *player2 << "'s (Player 2) health is " << player2->getHealth() << endl << endl;
}
