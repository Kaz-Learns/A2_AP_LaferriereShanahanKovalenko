#include "Game.h"

Game::Game()
{
    m_pCurrentRoom = nullptr;
    m_isCreated = false;

    bool created = m_buildRooms();
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
        m_pCurrentRoom->m_displayRoom();
    }
}

bool Game::m_buildRooms()
{
	// Used to skip unused text in text file
	string word;

	ifstream dataFile("Game.txt", ios::in);

	if (!dataFile)
	{
		cout << "Error opening file.";
		return false;
	}

	// Local variables used to store info from the text file that will be used to create room objects & puzzles
	string key, name, story1, story2, story3, story4, description, back, right, left, item, puzzle, death;
	
	while (dataFile >> word)
	{
		if (word == "ROOMSTART")
		{
			dataFile >> key;
			dataFile.ignore();
			getline(dataFile, name);
			getline(dataFile, story1);
			getline(dataFile, story2);
			getline(dataFile, story3);
			getline(dataFile, description);
			dataFile >> word;
			dataFile >> back;
			dataFile >> word;
			dataFile >> right;
			dataFile >> word;
			dataFile >> left;
			dataFile >> word;
			dataFile >> item;
			dataFile >> word;
			dataFile >> puzzle;
			dataFile >> word;
			dataFile >> death;

			// Creates a room with the information from the text file
			m_createRooms(key, name, story1, story2, story3, description, back, right, left, item, puzzle, death);
		}

		if (word == "PUZZLESTART")
		{
			dataFile >> key;
			dataFile.ignore();
			getline(dataFile, story1);
			getline(dataFile, story2);
			getline(dataFile, story3);
			getline(dataFile, story4);
			dataFile >> word;
			dataFile >> puzzle;

			// Creates a puzzle with the information from the text file
			m_createPuzzle(key, story1, story2, story3, story4, puzzle);
		}

		// Cout the ending based on whether the player has the dog or not - this will be read from the file during the run function of the game
		
	}

	//Close the file
	dataFile.close();

	return true;
}

void Game::m_createRooms(string key, string name, string story1, string story2, string story3, 
	string description, string back, string right, string left, string item, string puzzle, string death)
{
	m_rooms[key] = new Rooms(key, name, story1, story2, story3, description, item, puzzle, death);
	m_rooms[key]->m_setNeighbours(back, right, left);
}

void Game::m_createPuzzle(string key, string info1, string info2, string info3, string info4, string solution)
{
	m_puzzles[key] = new Puzzle(key, info1, info2, info3, info4, solution);
}

string Game::m_managePlayerInput()
{
    return string();
}
