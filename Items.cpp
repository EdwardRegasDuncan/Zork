#include "Items.h"

Items::Items(const char* name, const char* description, bool isContainer) :
name(name), description(description), isContainer(isContainer)
{

}
Items::~Items() {}

bool Items::Store(Items* item) {
	if (isContainer) {
		storage.push_back(item);
		return true;
	}
	return false;
}