#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player;

class Game
{
public:
	Game();
	~Game();

	bool ParseCommand(vector<string>& args);

	Player* player;
};

