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
	Rooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired);
	~Rooms();

	void m_setUpRoom(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired);
	void m_displayRoom();
	string m_getRequiredInput();

private:

	string m_roomName,
		m_roomUnderline,
		m_storyLine1,
		m_storyLine2,
		m_storyLine3,
		m_storyLine4,
		m_inputRequired;
};

#endif // !__ROOMS_H__
