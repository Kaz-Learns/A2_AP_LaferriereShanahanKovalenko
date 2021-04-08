#include "Rooms.h"

Rooms::Rooms()
{
  
}

Rooms::Rooms(string name, string story1, string story2, string story3, string description, string item, string puzzle, string death)
{
    m_setUpRoom(name, story1, story2, story3, description, item, puzzle, death);
 
}

Rooms::~Rooms()
{
    
}

void Rooms::m_setUpRoom(string name, string story1, string story2, string story3, string description, string item, string puzzle, string death)
{
    m_roomName = name;
    m_storyLine1 = story1;
    m_storyLine2 = story2;
    m_storyLine3 = story3;
    m_roomDescription = description;
    m_roomItem = item;
    m_roomPuzzle = puzzle;
    m_roomDeath = death;
}

void Rooms::m_displayRoom()
{
    cout << "-----------------\n" << m_roomName << endl << "-----------------\n";
    cout << m_storyLine1 << endl;
    cout << m_storyLine2 << endl;
    cout << m_storyLine3 << endl;
    cout << m_roomDescription << endl;
}




