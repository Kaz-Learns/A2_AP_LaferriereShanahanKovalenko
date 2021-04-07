#include "Game.h"

Game::Game()
{
    m_pCurrentRoom = nullptr;
    m_isCreated = false;

    bool created = m_buildGame();
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
		if (m_pCurrentRoom == m_rooms["BUSH"])
		{
			m_inventory.add("Dog");
		}
    }
}

bool Game::m_buildGame()
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
	//m_gameRooms.add(new Rooms(key, name, story1, story2, story3, description, item, puzzle, death));
	//m_gameRooms.getObject()->m_setNeighbours(right, left, back);
	m_rooms[key] = new Rooms(key, name, story1, story2, story3, description, item, puzzle, death);
	m_rooms[key]->m_setNeighbours(back, right, left);
	m_gameRooms.add(m_rooms[key]);
}

void Game::m_createPuzzle(string key, string info1, string info2, string info3, string info4, string solution)
{
	/*m_gamePuzzles.add(new Puzzle(key, info1, info2, info3, info4, solution));*/
	m_puzzles[key] = new Puzzle(key, info1, info2, info3, info4, solution);
	m_gamePuzzles.add(m_puzzles[key]);
}

void Game::m_managePlayerInput(string input1, string input2)
{
	string answer;

	if (input1 == "GO")
	{
		if(input2 == "RIGHT")
		{
			if (m_pCurrentRoom->m_canUsePath(RIGHT))
			{
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(RIGHT)]);
			}
		}
		if (input2 == "LEFT")
		{
			if (m_pCurrentRoom->m_canUsePath(LEFT))
			{
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(LEFT)]);
			}
		}
		if (input2 == "BACK")
		{
			if (m_pCurrentRoom->m_canUsePath(BACK))
			{
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(BACK)]);
			}
		}
	}
	if (input1 == "INTERACT")
	{
		if (input2 == "WIRES")
		{
			if (m_pCurrentRoom->m_getKey() == "ASYLUM")
			{
				m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
				m_pCurrentPuzzle->m_displayPuzzle();

				while (answer != m_pCurrentPuzzle->getSolution())
				{
					cin >> answer;
				}
				m_inventory.add("FIRST DIGIT: 1");
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(RIGHT)]);
			}
		}
		if (input2 == "RADIO")
		{
			if (m_pCurrentRoom->m_getKey() == "KITCHEN")
			{
				m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
				m_pCurrentPuzzle->m_displayPuzzle();

				while (answer != m_pCurrentPuzzle->getSolution())
				{
					cin >> answer;
				}
				m_inventory.add("SECOND DIGIT: 0");
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(RIGHT)]);
			}
		}
		if (input2 == "COMPUTER")
		{
			if (m_pCurrentRoom->m_getKey() == "OFFICE")
			{
				m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
				m_pCurrentPuzzle->m_displayPuzzle();

				while (answer != m_pCurrentPuzzle->getSolution())
				{
					cin >> answer;
				}
				m_inventory.add("THIRD DIGIT: 1");
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(RIGHT)]);
			}
		}
		if (input2 == "SAFE")
		{
			if (m_pCurrentRoom->m_getKey() == "SECURITY")
			{
				m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
				m_pCurrentPuzzle->m_displayPuzzle();

				while (answer != m_pCurrentPuzzle->getSolution())
				{
					cin >> answer;
				}
				m_inventory.add("FOURTH DIGIT: 1");
				m_pCurrentRoom = m_gameRooms.search(m_rooms[m_pCurrentRoom->m_getNeighbours(RIGHT)]);
			}
		}
		if (input2 == "KEYPAD")
		{
			if (m_pCurrentRoom->m_getKey() == "NURSE")
			{
				if ((m_inventory.find("FIRST DIGIT: 1") == true) && (m_inventory.find("SECOND DIGIT: 0") == true)
					&& (m_inventory.find("THIRD DIGIT: 1") == true) && (m_inventory.find("FOURTH DIGIT: 1") == true))
				{
					if (m_inventory.find("Dog") == true)
					{
						m_displayGameEnding(2);
					}
					else
					{
						m_displayGameEnding(1);
					}
				}
			}
		}
	}
}

void Game::m_displayGameEnding(int ending)
{
	// Used to skip unused text in text file
	string word;

	ifstream dataFile("Game.txt", ios::in);

	if (!dataFile)
	{
		cout << "Error opening file.";
	}

	// Local variables used to store info from the text file that will be used to output the ending
	string line1, line2, line3, line4, line5, line6, line7, line8, line9;

	// Cout the ending based on whether the player has the dog or not
	switch (ending)
	{
	case 1:
		while (dataFile >> word)
		{
			if (word == "WRONG")
			{
				dataFile.ignore();
				getline(dataFile, line1);
				getline(dataFile, line2);
				getline(dataFile, line3);
				getline(dataFile, line4);
				getline(dataFile, line5);
				getline(dataFile, line6);
				getline(dataFile, line7);
				getline(dataFile, line8);
				getline(dataFile, line9);

				cout << line1 << endl << line2 << endl << line3 << endl << line4 << endl << line5 <<
					endl << line6 << endl << line7 << endl << line8 << endl << line9;
			}
		}
		break;
	case 2:
		while (dataFile >> word)
		{
			if (word == "RIGHT")
			{
				dataFile.ignore();
				getline(dataFile, line1);
				getline(dataFile, line2);
				getline(dataFile, line3);
				getline(dataFile, line4);
				getline(dataFile, line5);
				getline(dataFile, line6);
				getline(dataFile, line7);
				getline(dataFile, line8);
				getline(dataFile, line9);

				cout << line1 << endl << line2 << endl << line3 << endl << line4 << endl << line5 <<
					endl << line6 << endl << line7 << endl << line8 << endl << line9;
			}
		}
		break;
	}
	//Close the file
	dataFile.close();
}
