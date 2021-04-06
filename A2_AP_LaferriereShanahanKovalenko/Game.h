#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

#include "Rooms.h"

class Game
{
public:
	Game();
	~Game();

	void m_RunGame();

private:
	bool m_buildRooms();
	void m_createRooms(string key, string name, string story1, string story2, string story3, 
		string description, string back, string right, string left, string item, string puzzle, string death);
	bool m_isCreated;
	
	string m_managePlayerInput(); 

	map<string, Rooms*> m_rooms; //to store all existing rooms
	Rooms* m_pCurrentRoom; // to track current room
	string m_lastRoom; // to track last visited room

};


#endif // !__GAME_H__
