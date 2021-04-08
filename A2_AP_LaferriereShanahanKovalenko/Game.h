#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Rooms.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void m_RunGame();
	bool m_buildGame();
	void m_createRooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired);
	void m_managePlayerInput(string input1);
	void m_displayGameEnding(int ending);
	void m_setRunning(bool running);
	void m_setWolf(bool wolf);
	bool m_getWolf();
	bool m_getRunning();

private:
	std::list<Rooms*>m_gameRooms;
	Rooms* m_pCurrentRoom; // To track current room

	string m_command;
	int m_ending;
	bool m_isCreated,
		m_hasWolf,
		m_gameRunning;
};


#endif // !__GAME_H__
