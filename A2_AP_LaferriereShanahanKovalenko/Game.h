#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "Rooms.h"
#include "Puzzle.h"
#include "Inventory.h"
#include "List.h"
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void m_RunGame();

private:
	bool m_buildGame();
	void m_createRooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired);
	void m_managePlayerInput(string input1);
	void m_displayGameEnding(int ending);
	
	string m_lastRoom; // To track last visited room
	std::list<Rooms*>m_gameRooms;

	/*List<Rooms*> m_gameRooms;*/
	Rooms* m_pCurrentRoom; // To track current room

	string m_command;
	bool m_isCreated;
	bool m_hasDog;
};


#endif // !__GAME_H__
