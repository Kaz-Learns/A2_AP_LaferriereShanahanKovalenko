#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Rooms.h"
#include "Puzzle.h"
#include "Inventory.h"
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void m_RunGame();

	void NextRoom()
	{
		m_gameRooms.pop_front();
	}
	void setRunning(bool running)
	{
		running = m_gameRunning;
	}
	bool getRunning()
	{
		return m_gameRunning;
	}

	void setEnding(string ending)
	{
		ending = m_ending;
	}

	string getEnding()
	{
		return m_ending;
	}

private:
	bool m_buildGame();
	void m_createRooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired);
	void m_managePlayerInput(string input1);
	void m_displayGameEnding(int ending);
	bool m_gameRunning = true;
	
	string m_lastRoom; // To track last visited room
	std::list<Rooms*>m_gameRooms;

	map<string, Rooms*> m_rooms; // To store all existing rooms
	Rooms* m_pCurrentRoom; // To track current room
	string m_lastRoom; // To track last visited room

	

	string m_ending;

	string m_command;
	bool m_isCreated;
};


#endif // !__GAME_H__
