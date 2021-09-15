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

	Items* Stick = new Items("stick", "A sturdy looking stick", false);
	Forest->AddItem(Stick);

	player = new Player(Forest);

}
Game::~Game(){

}

bool Game::ParseCommand(std::vector<std::string>& args) {

	Location* currentLocation = player->currentLocation;

	if (Same(args[0], "go")) {
		if (args.size() < 2) {
			cout << "Where do you want to go?\n";
			cout << "You are currently at: " << currentLocation->name << "\n";
			list<Location*> connections = currentLocation->connections;
			for (Location* location : connections)
			{
				cout << location->name << "\n";
			}
			return false;
		}
		else {
			cout << "you go to the " << (string)args[1] << "\n";
			list<Location*> connections = currentLocation->connections;
			for (Location* location : connections) {
				if (Same(location->name, args[1])) {
					player->Go(location);
				}
			}
			return true;
		}
	}
	if (Same(args[0], "look")) {
		if (args.size() < 2) {
			list<Items*> itemsInLocation = currentLocation->items;
			cout << "You look around the room and see: \n";
			for (Items* item : itemsInLocation) {
				cout << item->name << "\n";
			}
		}
		return false;
	}
	if (Same(args[0], "Take")) {
		if (args.size() < 2) {
			cout << "What do you want to take?\n";
		}
		else if (args.size() < 3) {
			list<Items*> itemsInLocation = currentLocation->items;
			for (Items* item : itemsInLocation) {
				if (Same(args[1], item->name)) {
					player->Take(item);
					currentLocation->RemoveItem(item);
					cout << "You take the " << item->name << "\n";
				}
			}
		}
	}
	if (Same(args[0], "Inventory") || Same(args[0], "inv") || Same(args[0], "i")) {
		list<Items*> itemsInInv = player->inventory;
		if (itemsInInv.size() < 1) {
			cout << "You currently have nothing\n";
			return false;
		}
		cout << "You check your inventory, you have: \n";
		for (Items* item : itemsInInv) {
			cout << item->name << "\n";
		}
		return true;
	}
}