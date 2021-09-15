#include "Location.h"
#include <string>
#include <vector>

using namespace std;

Location::Location(const char* name, const char* description) :
name(name), description(description)
{

}
Location::~Location() {

}

void Location::AddConnection(Location* target) {
	connections.push_back(target);
}
