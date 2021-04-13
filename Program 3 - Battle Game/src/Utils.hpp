#pragma once
#include <random>
#include <string>
#include <map>
#include "ActorType.hpp"
#include "MoveType.hpp"

using namespace std;

class Utils
{
public:
	static int randInt(int min, int max);				//returns a random integer between minimum and maximum
	static map<ActorType, string> actorDisplayName;		//maps ActorType to a string 
	static map<MoveType, string> moveDisplayName;		//maps MoveType to a string
	

};