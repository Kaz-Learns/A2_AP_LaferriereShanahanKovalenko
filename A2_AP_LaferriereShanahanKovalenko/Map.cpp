#include "Map.h"

template<class T>
GameMap<T>::~GameMap()
{
	ListNode* nodePtr = m_front;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

//Add new element to end of list
template<class T>
void GameMap<T>::add(T value)
{
	if (m_front == nullptr)
		m_front = new ListNode(value);
	else
	{
		//List is not empty, use nodePtr to traverse the list
		ListNode* nodePtr = m_front;
		while (nodePtr->next != nullptr)
			nodePtr = nodePtr->next;

		//nodePtr is nullptr so nodePtr points to last node
		//Create new node and put it after the last node
		nodePtr->next = new ListNode(value);
	}
}

//Removes an element from a list, function does not assume that list is sorted (when using nums)
template<class T>
void GameMap<T>::remove(T value)
{
	ListNode* nodePtr, * previousNodePtr;

	//If list is empty, do nothing
	if (!m_front) return;

	//Determine if first node is the one to delete
	if (m_front->value == value)
	{
		nodePtr = m_front;
		m_front = m_front->next;
		delete nodePtr;
	}
	else
	{
		//Init nodePtr to the head of the list
		nodePtr = m_front;

		//Skip nodes whose value is not the one we're looking for
		while(nodePtr != nullptr && nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr-> next;
		}

		//Link previous node to the node after nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
void GameMap<T>::display() const
{
	ListNode* nodePtr = m_front; //Start at head of list

	while (nodePtr)
	{
		//Print the values in the current node
		cout << nodePtr->value << "    ";
		//Move to the next node
		nodePtr = nodePtr->next;
	}
}


