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
	setRunning(true);
	setDog(false);
	
	cin.ignore();

	while (Game::getRunning())
	{
		if (!m_gameRooms.empty())
		{
			m_pCurrentRoom = m_gameRooms.front();
			m_pCurrentRoom->m_displayRoom();
			m_pCurrentRoom->GetCommand();
			cout << "\n";
			m_managePlayerInput(m_pCurrentRoom->GetReturnCommand());
		}
		if (m_gameRooms.empty() && m_hasDog == true)
		{
			m_ending = 1;
			m_displayGameEnding(m_ending);
			setRunning(false);
		}
		else if (m_gameRooms.empty() && m_hasDog == false)
		{
			m_ending = 2;
			m_displayGameEnding(m_ending);
			setRunning(false);
		}
	}
}

bool Game::m_buildGame()
{
	// Used to skip unused text in text file
	/*string word;*/

	ifstream dataFile("NewGame.txt", ios::in);

	if (!dataFile)
	{
		cout << "Error opening file.";
		return false;
	}

	// Local variables used to store info from the text file that will be used to create room objects & puzzles
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
	//string answer;
	
	if (input1 == m_pCurrentRoom->m_getRequiredInput())
	{
		m_gameRooms.remove(m_pCurrentRoom);
	}
	else if (input1 == "CALL DOG")
	{
		cout << "Seems the dog you heard has taken a liking to you! He is following you around... \n" << endl;
		setDog(true);
	}
	else
	{
		cout << "Incorrect input try again...\n" << endl;
	} 
}

void Game::m_displayGameEnding(int ending)
{
	// Used to skip unused text in text file
	string word;

	ifstream dataFile("NewGame.txt", ios::in);

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
					endl << line6 << endl << line7 << endl << line8 << endl << line9 <<"\n";
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
					endl << line6 << endl << line7 << endl << line8 << endl << line9 << "\n\n";
			}
		}
		break;
	}
	//Close the file
	dataFile.close();
}
