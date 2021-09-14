#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game
{
public:
	Game();
	~Game();

	bool ParseCommand(vector<string>& args);

private:


};

