#pragma once
#ifndef __MAP_H__
#define __MAP_H__
#include <iostream>
using namespace std;

//Using Template beacuse we havent finalized the setup of our map, this will take strings or ints
template <class T>
class GameMap
{
protected:
	struct ListNode
	{
		T value;
		ListNode* next;
		ListNode* previous;
		ListNode(T value1, ListNode* next1 = nullptr, ListNode* previous1 = nullptr)
		{
			value = value1;
			next = next1;
			previous = previous1;
		}
		
	};
	ListNode* m_front;
	ListNode* m_back;
	

public:
	GameMap()
	{
		m_front = nullptr;
		m_back = nullptr;

	}
	~GameMap();
	void add(T value);
	void remove(T value);
	void display() const;
};



#endif // !__MAP_H__
