#include "Game.hpp"
#include "Utils.hpp"

void Game::Menu()
{
	cout << "------------------------------------------- Battle Game -------------------------------------------" << endl << endl;

	int optionNumber;
	int input;
	ActorType player1{}; 
	ActorType player2{};

	do
	{
		cout << "Menu:\n" 
			 << "------------" <<endl;
		cout << "1. Play Game\n" 
			 << "2. Exit Game" << endl << endl;

		cout << "Please choose the number of the option you want: ";
		cin >> optionNumber;

		if (optionNumber == 1)										//Play Game							
		{
			do
			{
				//Display Characters' Names
				cout << "\n1. " << Utils::actorDisplayName[ActorType::Knight] << endl;
				cout << "2. "	<< Utils::actorDisplayName[ActorType::Ghost] << endl;

				//Choose Player 1's character
				cout << "Please choose Player 1's character: ";
				cin >> input;

				switch (input)
				{
				case 1:
					player1 = ActorType::Knight;
					break;
				case 2:
					player1 = ActorType::Ghost;
					break;
				default:
					cout << "Invalid Character for Player 1" << endl;
				}
			}
			while (input != 1 && input != 2);

			do
			{
				//Display Characters' Names
				cout << "\n1. " << Utils::actorDisplayName[ActorType::Knight] << endl;
				cout << "2. " << Utils::actorDisplayName[ActorType::Ghost] << endl;

				//Choose Player 2's character
				cout << "Please choose Player 2's character: ";
				cin >> input;

				switch (input)
				{
				case 1:
					player2 = ActorType::Knight;
					break;
				case 2:
					player2 = ActorType::Ghost;
					break;
				default:
					cout << "Invalid Character for Player 2" << endl;
				}
			} 			
			while (input != 1 && input != 2);
			
			cout << "\n------------------------------------------" << endl;
			cout << "Let the Battle begin" << endl;
			cout << "------------------------------------------" << endl << endl;

			//Begin Battle
			Battle battle(player1, player2);
			battle.Start();
		}

		else if (optionNumber == 2)									//Exit Game
		{
			cout << "Thank you for playing!" << endl;
			exit(-1);
		}

		else														//Invalid Input
		{
			cout << "Invalid Input!" << endl << endl;
		}
	}
	while (optionNumber != 1 && optionNumber != 2);
}



