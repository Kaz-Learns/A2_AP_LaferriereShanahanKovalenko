#include "Rooms.h"

Rooms::Rooms()
{
    m_setUpRoom();
}

Rooms::Rooms(string key, string name, string description)
{
    m_setUpRoom(key, name, description);
}

void Rooms::m_setUpRoom(string key, string name, string description)
{
    m_roomKey = key;
    m_roomName = name;
    m_roomDescripton = description;
    //Will need item as well


    for (int i = 0; i < 3; i++)
    {
        m_neighbourKeys[i] = "NULL";
    }
}

void Rooms::m_setNeighbours(string right, string left, string back)
{
    m_neighbourKeys[RIGHT] = right;
    m_neighbourKeys[LEFT] = left;
    m_neighbourKeys[BACK] = back;
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
    cout << m_roomName << endl;
    cout << m_roomDescripton << endl;
}
