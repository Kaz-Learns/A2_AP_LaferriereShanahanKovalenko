#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string playerName;

	//Welcome the user to the game.
	cout << " WELCOME TO ASYLUM ADVENTURE\n ---------------------------\n";
	
	cout << " Please enter your first name: ";
	cin >> playerName;

	Game theGame;
	theGame.m_RunGame();

	cout << endl;
	cout << " Thank you for playing " << playerName << endl;
	cout << " We hope you enjoyed your Asylum Adventure...\n\n";

	return 0;
}

