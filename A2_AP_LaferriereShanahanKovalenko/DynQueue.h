#pragma once
#include "Rooms.h"

class DynRoomQueue
{
private:
	class QueueNode
	{
		friend class DynRoomQueue;
		Rooms* value;
		QueueNode* next;

		//Constructor
		QueueNode(Rooms* value1, QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	QueueNode* front;
	QueueNode* rear;

	Rooms* aPtr;
	int roomsSize;

public:
	DynRoomQueue()
	{
		front = nullptr;
		rear = nullptr;
	}
	~DynRoomQueue()
	{
		clear();
	}

	void enqueue(Rooms*);
	void dequeue(Rooms&);
	bool isEmpty() const;
	void clear();

	void operator=(const Rooms &right);

};