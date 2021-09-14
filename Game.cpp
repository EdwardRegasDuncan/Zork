#include "Game.h"
#include "globals.h"


Game::Game() {

}
Game::~Game(){

}

bool Game::ParseCommand(std::vector<std::string>& args) {

	if (Same(args[0], "go")) {
		if (args.size() < 2) {
			cout << "Where do you want to go?\n";
			//list possible locations
			return false;
		}
		else {
			cout << "you go " << (string)args[1];
			return true;
			//move to location
		}
	}
	/*if (Same(args[0], "look")) {
		return 0;
	}*/
}