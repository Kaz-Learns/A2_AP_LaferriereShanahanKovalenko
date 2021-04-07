#include "Rooms.h"

Rooms::Rooms()
{
  
}

Rooms::Rooms(string key, string name, string story1, string story2, string story3, string description, string item, string puzzle, string death)
{
    m_setUpRoom(key, name, story1, story2, story3, description, item, puzzle, death);
 
}

Rooms::~Rooms()
{
    
}

void Rooms::m_setUpRoom(string key, string name, string story1, string story2, string story3, string description, string item, string puzzle, string death)
{
    m_roomKey = key;
    m_roomName = name;
    m_storyLine1 = story1;
    m_storyLine2 = story2;
    m_storyLine3 = story3;
    m_roomDescription = description;
    m_roomItem = item;
    m_roomPuzzle = puzzle;
    m_roomDeath = death;

    for (int i = 0; i < 3; i++)
    {
        m_neighbourKeys[i] = "NULL";
    }
}

void Rooms::m_setNeighbours(string back, string right, string left)
{
    m_neighbourKeys[BACK] = back;
    m_neighbourKeys[RIGHT] = right;
    m_neighbourKeys[LEFT] = left;
}

bool Rooms::m_canUsePath(ChoicePath direction)
{
    for (int i = 0; i < 3; i++)
    {
        if (direction == ChoicePath(i) && m_neighbourKeys[i] != "NULL")
        {
            return true;
        }
    }
    return false;
}

string Rooms::m_getNeighbours(ChoicePath direction)
{
    return m_neighbourKeys[direction];
}

string Rooms::m_getKey()
{
    return m_roomKey;
}

void Rooms::m_displayRoom()
{
    cout << "-----------------\n" << m_roomName << endl << "-----------------\n";
    cout << m_storyLine1 << endl;
    cout << m_storyLine2 << endl;
    cout << m_storyLine3 << endl;
    cout << m_roomDescription << endl;
}




