#pragma once
#ifndef __ROOMS_H__
#define __ROOMS_H__
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rooms
{
public:

	Rooms();
	Rooms(string name, string story1, string story2, string story3, string description, string item, string puzzle, string death);
	~Rooms();

	//void m_setNeighbours(string right, string left, string back);
	void m_setUpRoom(string name, string story1, string story2, string story3, string description, string item, string puzzle, string death);

	void m_displayRoom();


private:

	string
		m_roomName,
		m_storyLine1,
		m_storyLine2,
		m_storyLine3,
		m_roomDescription,
		m_roomItem,
		m_roomPuzzle,
		m_roomDeath;
};

#endif // !__ROOMS_H__
