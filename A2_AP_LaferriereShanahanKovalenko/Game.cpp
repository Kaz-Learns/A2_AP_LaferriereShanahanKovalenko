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
	setRunning(true);

	while (Game::getRunning())
	{
		m_pCurrentRoom = m_gameRooms.front();
		m_pCurrentRoom->m_displayRoom();

		m_pCurrentRoom->GetCommand();

		
		m_managePlayerInput(m_pCurrentRoom->GetReturnCommand());

		

		/*if (m_pCurrentRoom->GetReturnCommand() == m_pCurrentRoom->GetInputRequired())
		{
			NextRoom();
		}*/
	}

	

	// Need to set up proper user command getline
	/*getline(cin, m_command);
	m_managePlayerInput(m_command);*/

	// Just a test to ensure all rooms were added to the list from the text file
	/*m_pCurrentRoom = m_gameRooms.back();
	m_pCurrentRoom->m_displayRoom();*/
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
	//string answer;
	
	if (input1 == m_pCurrentRoom->m_getRequiredInput())
	{
		m_gameRooms.remove(m_pCurrentRoom);
	}
}

void Game::m_managePlayerInput(string input1, string input2)
{
	if (input1 == "GO")
	{
		if(input2 == "RIGHT")
		{
			if (m_pCurrentRoom->m_canUsePath(RIGHT))
			{
				// Move to that room
			}
		}
		if (input2 == "LEFT")
		{
			if (m_pCurrentRoom->m_canUsePath(LEFT))
			{
				// Move to that room
			}
		}
		if (input2 == "BACK")
		{
			if (m_pCurrentRoom->m_canUsePath(BACK))
			{
				// Move to that room
			}
		}
	}
	if (input1 == "INTERACT")
	{
		if (input2 == "WIRES")
		{
			if (m_pCurrentRoom->m_getKey() == "ASYLUM")
			{
				// Use the puzzle
			}
		}
		if (input2 == "RADIO")
		{
			if (m_pCurrentRoom->m_getKey() == "KITCHEN")
			{
				// Use the puzzle
			}
		}
		if (input2 == "COMPUTER")
		{
			if (m_pCurrentRoom->m_getKey() == "OFFICE")
			{
				// Use the puzzle
			}
		}
		if (input2 == "SAFE")
		{
			if (m_pCurrentRoom->m_getKey() == "SECURITY")
			{
				// Use the puzzle
			}
		}
		if (input2 == "KEYPAD")
		{
			if (m_pCurrentRoom->m_getKey() == "NURSE")
			{
				/*if (Player has all the code)
				{
					Use the puzzle
				}*/
			}
		}
	}

    return string();
}
