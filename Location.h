#pragma once
#include <list>
#include <string>
#include "Items.h"

using namespace std;

class Location
{
public:
	Location(const char* name, const char* description);
	~Location();

	void AddConnection(Location* target);
	void AddItem(Items* item);
	void RemoveItem(Items* item);

	list<Location*> connections;
	std::string name;
	std::string description;

	list<Items*> items;
};

