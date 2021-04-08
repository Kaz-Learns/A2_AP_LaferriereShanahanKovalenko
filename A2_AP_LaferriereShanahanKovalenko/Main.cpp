#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string playerName;

	//Welcome the user to the game.
	cout << "Welcome to Asylum Adventure. \n" << endl;
	cout << "Use the keywords:'GO FORWARD' to advance, 'OPEN DOOR' to open door and 'INTERACT (PUZZLE)' to interact with puzzles" << endl;
	
	cout << "Please enter your name: " << endl;
	cin >> playerName;
	cout << "\n" << endl;

	Game theGame;
	theGame.m_RunGame();

	cout << endl;
	cout << "Thanks for playing " << playerName << endl;
	cout << "We hope you enjoyed your Asylum Adventure.";

	return 0;
}

