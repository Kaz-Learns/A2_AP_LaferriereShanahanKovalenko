#pragma once
#ifndef __ROOMS_H__
#define __ROOMS_H__
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum ChoicePath  { LEFT, RIGHT, BACK };

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

class Rooms
{
public:

	Rooms();
	Rooms(string key, string name, string story1, string story2, string story3, string description, string item, string puzzle, string death);
	~Rooms();

	void m_setNeighbours(string right, string left, string back);
	void m_setUpRoom(string key, string name, string story1, string story2, string story3, string description, string item, string puzzle, string death);

	bool m_canUsePath(ChoicePath direction);
	string m_getNeighbours(ChoicePath direction);
	string m_getKey();
	void m_displayRoom();


private:

	string m_roomKey,
		m_roomName,
		m_storyLine1,
		m_storyLine2,
		m_storyLine3,
		m_roomDescription,
		m_roomItem,
		m_roomPuzzle,
		m_roomDeath,
		m_neighbourKeys[3];
};

#endif // !__ROOMS_H__
