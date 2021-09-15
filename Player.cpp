#include "Player.h"

Player::Player(Location* currentLocation) :
currentLocation(currentLocation)
{

}
Player::~Player() {

}

bool Player::Go(Location* location) {
	currentLocation = location;
	return true;
}
bool Player::Take(Items* item) {
	inventory.push_back(item);
	return true;
}
bool Player::Drop(Items* item) {
	inventory.remove(item);
	return true;
}
