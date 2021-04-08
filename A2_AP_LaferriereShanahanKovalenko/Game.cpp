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
	string name, story1, story2, story3, story4, description, item, puzzle, death;
	
	while (dataFile >> word)
	{
		if (word == "ROOMSTART")
		{
			getline(dataFile, name);
			getline(dataFile, story1);
			getline(dataFile, story2);
			getline(dataFile, story3);
			getline(dataFile, description);
			dataFile >> word;
			dataFile >> word;
			dataFile >> word;
			dataFile >> word;
			dataFile >> item;
			dataFile >> word;
			dataFile >> puzzle;
			dataFile >> word;
			dataFile >> death;

			// Creates a room with the information from the text file
			m_createRooms(name, story1, story2, story3, story4, description, item, puzzle, death);
		}

		if (word == "PUZZLESTART")
		{
			getline(dataFile, story1);
			getline(dataFile, story2);
			getline(dataFile, story3);
			getline(dataFile, story4);
			dataFile >> word;
			dataFile >> puzzle;

			// Creates a puzzle with the information from the text file
			m_createPuzzle(story1, story2, story3, story4, puzzle);
		}

		// Cout the ending based on whether the player has the dog or not - this will be read from the file during the run function of the game
	}

	//Close the file
	dataFile.close();

	return true;
}

void Game::m_createRooms(string name, string story1, string story2, string story3, string story4,
	string description, string item, string puzzle, string death)
{
	m_gameRooms.add(new Rooms(name, story1, story2, story3, description, item, puzzle, death));
	//m_gameRooms.getObject()->m_setNeighbours(right, left, back);
	//m_rooms[key] = new Rooms(key, name, story1, story2, story3, description, item, puzzle, death);
	//m_gameRooms.add(m_rooms[key]);
}

void Game::m_createPuzzle(string info1, string info2, string info3, string info4, string solution)
{
	m_gamePuzzles.add(new Puzzle(info1, info2, info3, info4, solution));
	//m_gamePuzzles = new Puzzle(info1, info2, info3, info4, solution);
	//m_gamePuzzles.add(m_gamePuzzles);
}

void Game::m_managePlayerInput(string input1, string input2)
{
	string answer;

	if (input1 == "GO")
	{
		
	}

	if (input1 == "INTERACT")
	{
		if (input2 == "WIRES")
		{
			//m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
			m_pCurrentPuzzle->m_displayPuzzle();

			while (answer != m_pCurrentPuzzle->getSolution())
			{
				cin >> answer;
			}
			m_inventory.add("FIRST DIGIT: 1");
			}
		}
		if (input2 == "RADIO")
		{
			//m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
			m_pCurrentPuzzle->m_displayPuzzle();

			while (answer != m_pCurrentPuzzle->getSolution())
			{
				cin >> answer;
			}
			m_inventory.add("SECOND DIGIT: 0");
			
		}
		if (input2 == "COMPUTER")
		{
			//m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
			m_pCurrentPuzzle->m_displayPuzzle();

			while (answer != m_pCurrentPuzzle->getSolution())
			{
				cin >> answer;
			}
			m_inventory.add("THIRD DIGIT: 1");
			
		}
		if (input2 == "SAFE")
		{
			//m_pCurrentPuzzle = m_gamePuzzles.search(m_puzzles[input2]);
			m_pCurrentPuzzle->m_displayPuzzle();

			while (answer != m_pCurrentPuzzle->getSolution())
			{
				cin >> answer;
			}
			m_inventory.add("FOURTH DIGIT: 1");
			
		}
		if (input2 == "KEYPAD")
		{
			if (m_hasDog == true)
			{
				m_displayGameEnding(2);
			}
			else
			{
				m_displayGameEnding(1);
			}

			/*if ((m_inventory.find("FIRST DIGIT: 1") == true) && (m_inventory.find("SECOND DIGIT: 0") == true)
				&& (m_inventory.find("THIRD DIGIT: 1") == true) && (m_inventory.find("FOURTH DIGIT: 1") == true))
			{
				if (m_hasDog == true)
				{
					m_displayGameEnding(2);
				}
				else
				{
					m_displayGameEnding(1);
				}
			}*/
			
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
