#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "globals.h"

using namespace std;

bool running = true;

int main() {

	cout << "Welcome to Text Adventure\n";
	string input;
	vector<string> args;
	Game game;
	


	while (running) {
		
		getline(cin, input);

		if (Same(input, "quit")) { running = false; }

		if (input.length() > 0) {
			Tokenize(input, args);
			game.ParseCommand(args);
		}
		input == "";
		
	}

	cout << "Thanks for playing";
}