#pragma once
#include <string>
#include <list>
#include <vector>
#include "Location.h"
using namespace std;

class Player
{
public:
	Player(Location* currentLocation);
	~Player();

	//functions
	bool Go(Location* location);

	
public:
	Location* currentLocation;

};

