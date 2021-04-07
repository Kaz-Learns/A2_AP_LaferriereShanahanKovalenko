#pragma once
#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
using namespace std;

template <class T>
class List
{
public:
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
	List()
	{
		m_front = nullptr;
		m_back = nullptr;

	}
	~List();
	void add(T value);
	T search(T value);
	bool find(T key);
	void remove(T value);

	ListNode* nodePtr, startPtr, nodePtr;
};

template<class T>
List<T>::~List()
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
void List<T>::add(T value)
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
void List<T>::remove(T value)
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
		while (nodePtr != nullptr && nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		//Link previous node to the node after nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template <class T>
T List<T>::search(T key)
{
	
	bool found = false;

	nodePtr = startPtr;

	while (!found && nodePtr != NULL)
	{
		if (nodePtr->data == key)
			found = true;
		else
			nodePtr = nodePtr->nextPtr;
	}
	return nodePtr;
}

template<class T>
bool List<T>::find(T key)
{
	bool found = false;

	nodePtr = startPtr;

	while (!found && nodePtr != NULL)
	{
		if (nodePtr->data == key)
			found = true;
		else
			nodePtr = nodePtr->nextPtr;
	}
	return found;
}

#endif // !__LIST_H__
