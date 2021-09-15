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
