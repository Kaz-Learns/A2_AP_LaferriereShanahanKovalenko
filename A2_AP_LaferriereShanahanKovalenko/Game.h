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

private:
	bool m_buildRooms();
	void m_createRooms(string key, string name, string story1, string story2, string story3, 
		string description, string back, string right, string left, string item, string puzzle, string death);
	void m_createPuzzle(string key, string info1, string info2, string info3, string info4, string solution);
	void m_managePlayerInput(string input1, string input2); 

	map<string, Rooms*> m_rooms; // To store all existing rooms
	Rooms* m_pCurrentRoom; // To track current room
	string m_lastRoom; // To track last visited room

	map<string, Puzzle*> m_puzzles; // To story all the puzzles
	Puzzle* m_pCurrentPuzzle; // To track current puzzle

	bool m_isCreated;
};


#endif // !__GAME_H__
