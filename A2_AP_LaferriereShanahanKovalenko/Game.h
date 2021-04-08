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

	void setRunning(bool running)
	{
		m_gameRunning = running;
	}
	bool getRunning()
	{
		return m_gameRunning;
	}

	void setEnding(int ending)
	{
		m_ending = ending;
	}

	int getEnding()
	{
		return m_ending;
	}

	void setDog(bool dog)
	{
		m_hasDog = dog;
	}

	bool getDog()
	{
		return m_hasDog;
	}

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
	int m_ending;
	bool m_isCreated;
	bool m_hasDog;
	bool m_gameRunning;
};


#endif // !__GAME_H__
