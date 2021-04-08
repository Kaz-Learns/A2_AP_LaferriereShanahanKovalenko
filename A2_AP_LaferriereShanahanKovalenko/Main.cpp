#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string playerName;

	//Welcome the user to the game.
	cout << "Welcome to Asylum Adventure. Please enter your name: " << endl;
	cin >> playerName;
	cout << endl;

	Game theGame;
	theGame.m_RunGame();

	cout << endl;
	cout << "Thanks for playing " << playerName << endl;
	cout << "We hope you enjoyed you Asylum Adventure.";

	return 0;
}

