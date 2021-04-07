#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string playerName;

	//Welcome the user to the game.
	cout << "Welcome to Asylum Adventure. Please enter your name: " << endl;
	cin >> playerName;

	Game theGame;
	theGame.m_RunGame();

	cout << "Thanks for playing " << playerName << endl;
	cout << "We hope you enjoyed you Asylum Adventure.";

	return 0;
}

