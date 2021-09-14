#include "Game.h"
#include "globals.h"
#include "Location.h"
#include "Player.h"
#include <list>


Game::Game() {

	Location* Forest = new Location("forrest", "A Sparse Forrest");
	Location* House = new Location("house", "A Wooden house");
	Location* Lake = new Location("lake", "A calm lake of blue water");

	Forest->AddConnection(House);
	Forest->AddConnection(Lake);

	House->AddConnection(Forest);

	Lake->AddConnection(Forest);

	player = new Player(Forest);

}
Game::~Game(){

}

bool Game::ParseCommand(std::vector<std::string>& args) {

	if (Same(args[0], "go")) {
		if (args.size() < 2) {
			cout << "Where do you want to go?\n";
			Location currentLocation = player->GetCurrentLocation();
			cout << "You are currently at: " << currentLocation.name << "\n";
			list<Location> connections = currentLocation.connections;
			for (Location location : connections)
			{
				cout << location.name << "\n";
			}
			return false;
		}
		else {
			cout << "you go to the " << (string)args[1] << "\n";
			Location currentLocation = player->GetCurrentLocation();
			list<Location> connections = currentLocation.connections;
			for (Location location : connections) {
				if (Same(location.name, args[1])) {
					player->Go(location);
				}
			}
			return true;
			//move to location
		}
	}
	/*if (Same(args[0], "look")) {
		return 0;
	}*/
}