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
	void m_buildRooms(string key, string description, string left, string right, string back);
	bool m_createRooms();
	bool m_isCreated;
	
	string m_managePlayerInput(); 

	map<string, Rooms*> m_rooms; //to store all existing rooms
	Rooms* m_pCurrentRoom; // to track current room
	string m_lastRoom; // to track last visited room

};


#endif // !__GAME_H__
