#pragma once
#ifndef __ROOMS_H__
#define __ROOMS_H__
#include <iostream>
#include <string>
using namespace std;

enum ChoicePath { LEFT, RIGHT, BACK };

string getChoicePath(ChoicePath direction)
{
	switch (direction)
	{
	case LEFT: 
		return "LEFT";
		break;
	case RIGHT:
		return "RIGHT";
		break;
	case BACK:
		return "BACK";
		break;
	}
}

struct Rooms
{
	Rooms();
	Rooms(string key, string name, string item, string puzzle, string death);

	void m_setNeighbours(string right, string left, string back);
	void m_setUpRoom(string key = "", string name = "", string item = "", string puzzle = "", string death = "");

	bool m_canUsePath(ChoicePath direction);
	string m_getNeighbours(ChoicePath direction);
	string m_getKey();
	void m_displayRoom();

	string m_roomKey,
		m_roomName,
		m_roomItem,
		m_roomPuzzle,
		m_roomDeath,
		m_neighbourKeys[3];
};

#endif // !__ROOMS_H__
