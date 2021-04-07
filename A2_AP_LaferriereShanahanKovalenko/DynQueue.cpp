#include "DynQueue.h"
void DynRoomQueue::enqueue(Rooms* room)
{
	if (isEmpty())
	{
		front = new QueueNode(room);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(room);
		rear = rear->next;
	}
}

void DynRoomQueue::dequeue(Rooms& room)
{
	QueueNode* temp;
	if (isEmpty())
	{
		cout << "The queue is empty...\n";
		exit(1);
	}
	else
	{
		room = front->value;
		temp = front;
		front = front->next;
		delete temp;
		temp = nullptr;
	}
}

bool DynRoomQueue::isEmpty() const
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DynRoomQueue::clear()
{
	Rooms value; // dummies variable

	while (!isEmpty())
	{
		dequeue(value);
	}
}
