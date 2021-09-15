#pragma once
#include <string>
#include <list>
#include <vector>
#include "Location.h"
#include "Items.h"
using namespace std;

class Player
{
public:
	Player(Location* currentLocation);
	~Player();

	//functions
	bool Go(Location* location);
	bool Take(Items* item);
	bool Drop(Items* item);

	
public:
	Location* currentLocation;
	list<Items*> inventory;

};

