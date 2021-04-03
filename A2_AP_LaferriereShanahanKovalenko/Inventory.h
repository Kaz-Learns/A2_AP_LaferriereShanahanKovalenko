#pragma once
#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <iostream>
#include <string>
using namespace std;

class Inventory
{
protected:
	struct ListNode
	{
		string m_item;
		ListNode* m_pNextItem;

		ListNode(string item, ListNode* nextItem = nullptr)
		{
			m_item = item;
			m_pNextItem = nextItem;
		}
	};
	ListNode* m_head;

public:
	Inventory()
	{
		m_head = nullptr;
	}
	~Inventory();
	void add(string item);
	void displayInventory() const;
};
#endif // !__INVENTORY_H__
