#include "Rooms.h"

Rooms::Rooms()
{
  
}

Rooms::Rooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired)
{
    m_setUpRoom(name, underline, story1, story2, story3, story4, inputRequired);
}

Rooms::~Rooms()
{
    
}

void Rooms::m_setUpRoom(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired)
{
    m_roomName = name;
    m_roomUnderline = underline;
    m_storyLine1 = story1;
    m_storyLine2 = story2;
    m_storyLine3 = story3;
    m_storyLine4 = story4;
    m_inputRequired = inputRequired;
}

void Rooms::m_displayRoom()
{
    cout << m_roomName << endl;
    cout << m_roomUnderline << endl;
    cout << m_storyLine1 << endl;
    cout << m_storyLine2 << endl;
    cout << m_storyLine3 << endl;
    cout << m_storyLine4 << endl;
}

string Rooms::m_getRequiredInput()
{
    return m_inputRequired;
}




