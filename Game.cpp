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

	Items* FireWood = new Items("Log", "A cut piece of fire wood", false);
	Items* WoodenBox = new Items("Box", "A Wooden box with a lid", true);
	
	
	Forest->AddItem(FireWood);
	House->AddItem(WoodenBox);

	player = new Player(Forest);

}
Game::~Game(){

}

bool Game::ParseCommand(std::vector<std::string>& args) {

	Location* currentLocation = player->currentLocation;

	if (Same(args[0], "Help")) {
		cout << "To play enter an action such as: \n";
		cout << "Quit\n";
		cout << "Go\n";
		cout << "Look\n";
		cout << "Take\n";
		cout << "Drop\n";
		cout << "Inventory / Inv / I\n";
		cout << "Put [x] in [y]\n";
		cout << "Some commands need context, for example: Take Stick or Go House\n";
		return true;
	}
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
			
			list<Location*> connections = currentLocation->connections;
			for (Location* location : connections) {
				if (Same(location->name, args[1])) {
					player->Go(location);
					cout << "you go to the " << location->name << "\n";
					return true;
				}
			}
			cout << "You can't go there\n";
			return false;
		}
	}
	if (Same(args[0], "look")) {
		if (args.size() < 2) {
			list<Items*> itemsInLocation = currentLocation->items;
			cout << "You look around and see: \n";
			for (Items* item : itemsInLocation) {
				cout << item->name << "\n";
			}
		}
		return false;
	}
	if (Same(args[0], "Take")) {
		if (args.size() < 2) {
			cout << "What do you want to take?\n";
			return false;
		}
		else if (args.size() < 3) {
			list<Items*> itemsInLocation = currentLocation->items;
			for (Items* item : itemsInLocation) {
				if (Same(args[1], item->name)) {
					player->Take(item);
					currentLocation->RemoveItem(item);
					cout << "You take the " << item->name << "\n";
					return true;
				}
			}
			cout << "You can't take that\n";
			return false;
			
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
	if (Same(args[0], "Drop")) {
		if (args.size() < 2) {
			cout << "What do you want to drop?\n";
			return false;
		}
		if (args.size() < 3) {
			list<Items*> itemsInLocation = player->inventory;
			for (Items* item : itemsInLocation) {
				if (Same(args[1], item->name)) {
					player->Drop(item);
					currentLocation->AddItem(item);
					cout << "You Drop the " << item->name << "\n";
					return true;
				}
			}
			cout << "You dont have this\n";
			return false;
		}
	}
	if (Same(args[0], "Put")) {
		for (int i = 0; i < args.size(); i++) {
			if (Same(args[i], "in")) {
				args.erase(args.begin()+i--);
			}
		}

		if (args.size() < 2) {
			cout << "Put what where?\n";
			return false;
		}
		if (args.size() < 4) {
			list<Items*> inventory = player->inventory;
			Items* container = NULL;
			Items* containee = NULL;
			for (Items* item : inventory) {
				if (Same(args[2], item->name)) {
					if (!item->isContainer) {
						cout << item->name << " is not a container for anything\n";
						return false;
					}
					container = item;
				}
				else if (Same(args[1], item->name)) {
					if (item->isContainer) {
						cout << "You cannot put a container inside something else\n";
						return false;
					}
					containee = item;
				}
			}
			if (!container || !containee) {
				cout << "You dont have these items\n";
				return false;
			}
			container->Store(containee);
			player->Drop(containee);
			cout << "You put the " << containee->name << " into the " << container->name << "\n";
			return true;
		}
	
	}

	if (Same(args[0], "Quit")) {
		quick_exit(0);
	}


	cout << "Sorry I didn't understand that, do you need 'help' ?";
	return false;
}