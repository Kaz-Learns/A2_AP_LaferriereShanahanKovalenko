#include "Game.h"
#include <algorithm>

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
	m_setRunning(true);
	m_setWolf(false);
	
	cin.ignore();
	
	while (Game::m_getRunning())
	{
		if (!m_gameRooms.empty())
		{
			system("CLS");
					 
			cout << " --------------------------------------------------------------------------------------------------------------";
			cout << "\n                                Use the following keywords while inputting commands:";
			cout << "\n 'GO FORWARD' to advance, 'OPEN DOOR' to open door and 'INTERACT (INSERT PUZZLE NAME)' to interact with puzzles";
			cout << "\n                       Input is NOT case sensitive. Make sure to remember any important NUMBERS...";
			cout << "\n --------------------------------------------------------------------------------------------------------------\n\n";
			m_pCurrentRoom = m_gameRooms.front();
			m_pCurrentRoom->m_displayRoom();
			cout << "\n ";
			getline(cin, m_command);
			transform(m_command.begin(), m_command.end(), m_command.begin(), toupper);
			cout << "\n";
			m_managePlayerInput(m_command);
		}
		if (m_gameRooms.empty() && m_hasWolf == true)
		{
			m_ending = 1;
			m_displayGameEnding(m_ending);
			m_setRunning(false);
		}
		else if (m_gameRooms.empty() && m_hasWolf == false)
		{
			m_ending = 2;
			m_displayGameEnding(m_ending);
			m_setRunning(false);
		}
	}
}

bool Game::m_buildGame()
{
	ifstream dataFile("NewGame.txt", ios::in);

	if (!dataFile)
	{
		cout << " Error opening file.";
		return false;
	}

	// Local variables used to store info from the text file that will be used to create room objects
	string word, name, underline, story1, story2, story3, story4, inputRequired;
	
	while (dataFile >> word)
	{
		if (word == "ROOMSTART")
		{
			dataFile.ignore();
			getline(dataFile, name);
			getline(dataFile, underline);
			getline(dataFile, story1);
			getline(dataFile, story2);
			getline(dataFile, story3);
			getline(dataFile, story4);
			getline(dataFile, inputRequired);

			// Creates a room with the information from the text file
			m_createRooms(name, underline, story1, story2, story3, story4, inputRequired);
		}
	}
	//Close the file
	dataFile.close();

	return true;
}

void Game::m_createRooms(string name, string underline, string story1, string story2, string story3, string story4, string inputRequired)
{
	m_gameRooms.push_back(new Rooms(name, underline, story1, story2, story3, story4, inputRequired));
}

void Game::m_managePlayerInput(string input1)
{
	if (input1 == m_pCurrentRoom->m_getRequiredInput())
	{
		m_gameRooms.remove(m_pCurrentRoom);
	}
	else if (input1 == "GO RIGHT")
	{
		m_gameRooms.remove(m_pCurrentRoom);

		string word, line1, line2, line3, line4, line5;

		ifstream dataFile("NewGame.txt", ios::in);

		if (!dataFile)
		{
			cout << " Error opening file.";
		}

		while (dataFile >> word)
		{
			if (word == "WOLF")
			{
				dataFile.ignore();
				getline(dataFile, line1);
				getline(dataFile, line2);
				getline(dataFile, line3);
				getline(dataFile, line4);
				getline(dataFile, line5);

				m_setWolf(true);
				cout << " " << line1 << "\n " << line2 << "\n " << line3 << "\n " << line4 << " " << line5 << "\n\n";

				system("PAUSE");
			}	
		}

		dataFile.close();
	}
	else
	{
		cout << " Invalid command. Please try again...\n" << endl;
		system("PAUSE");
	}
}

void Game::m_displayGameEnding(int ending)
{
	// Used to skip unused text in text file
	string word;

	ifstream dataFile("NewGame.txt", ios::in);

	if (!dataFile)
	{
		cout << " Error opening file.";
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

				cout << " " << line1 << "\n " << line2 << "\n " << line3 << "\n " << line4 << "\n " << line5 <<
					"\n " << line6 << "\n " << line7 << "\n " << line8 << "\n " << line9 <<"\n";
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

				cout << " " << line1 << "\n " << line2 << "\n " << line3 << "\n " << line4 << "\n " << line5 <<
					"\n " << line6 << "\n " << line7 << "\n " << line8 << "\n " << line9 << "\n\n";
			}
		}
		break;
	}
	//Close the file
	dataFile.close();
}

void Game::m_setRunning(bool running)
{
	m_gameRunning = running;
}

bool Game::m_getRunning()
{
	return m_gameRunning;
}

void Game::m_setWolf(bool wolf)
{
	m_hasWolf = wolf;
}

bool Game::m_getWolf()
{
	return m_hasWolf;
}
