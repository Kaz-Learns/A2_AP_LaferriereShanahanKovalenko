#include "Inventory.h"

Inventory::~Inventory()
{
	ListNode* nodePtr = m_head;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->m_pNextItem;
		delete garbage;
	}
}

void Inventory::add(string item)
{
	if (m_head == nullptr)
	{
		m_head = new ListNode(item);
	}
	else
	{
		ListNode* nodePtr = m_head;

		while (nodePtr->m_pNextItem != nullptr)
		{
			nodePtr = nodePtr->m_pNextItem;
		}
		nodePtr->m_pNextItem = new ListNode(item);
	}
}

void Inventory::displayInventory() const
{
	ListNode* nodePtr = m_head;
	int slot = 1;

	cout << "\nYou have the folling items in your Inventory:\n";

	while (nodePtr)
	{
		cout << "[" << slot << "] - " << nodePtr->m_item << endl;
		slot++;
		nodePtr = nodePtr->m_pNextItem;
	}
}