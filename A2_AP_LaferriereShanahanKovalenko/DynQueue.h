#pragma once
#include "Rooms.h"

class DynIntQueue
{
private:
	class QueueNode
	{
		friend class DynIntQueue;
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

public:
	DynIntQueue()
	{
		front = nullptr;
		rear = nullptr;
	}
	~DynIntQueue()
	{
		clear();
	}

	void enqueue(Rooms);
	void dequeue(Rooms&);
	bool isEmpty() const;
	void clear();

};