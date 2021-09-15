#pragma once
#include <string>
#include <list>

class Items
{
public:
	Items(const char* name, const char* description, bool isContainer);
	~Items();

	bool Store(Items* item);


	//vars
	std::string name;
	std::string description;
	bool isContainer;

	std::list<Items*> storage;
};

