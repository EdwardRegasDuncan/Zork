#pragma once
#include <list>
#include <string>

using namespace std;

class Location
{
public:
	Location(const char* name, const char* description);
	~Location();

	void AddConnection(Location* target);

	list<Location> connections;
	std::string name;
	std::string description;
};

