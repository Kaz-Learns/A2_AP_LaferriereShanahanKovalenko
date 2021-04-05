#include "Game.h"

Game::Game()
{
    m_pCurrentRoom = nullptr;
    m_isCreated = false;

    bool created = m_createRooms();
    if (!created)
    {
        m_isCreated = true;
    }
}

Game::~Game()
= default;

void Game::m_RunGame()
{
    while (!m_isCreated)
    {

    }
}

void Game::m_buildRooms(string key, string description, string left, string right, string back)
{
}

bool Game::m_createRooms()
{
    return false;
}

string Game::m_managePlayerInput()
{
    return string();
}
