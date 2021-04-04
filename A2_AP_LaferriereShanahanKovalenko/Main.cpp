#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Variable to store data
	string input;

	//Open the file
	fstream dataFile("Game.txt", ios::in);
	if (!dataFile)
	{
		cout << "Error opening file.";
		return 0;
	}

	//Read in lines of data seperated by '$' sign and output (this will change bc of choices but just testing out ideas)
	getline(dataFile, input, '$');
	while (!dataFile.fail())
	{
		cout << input << endl;
		getline(dataFile, input, '$');
	}

	//Close the file
	dataFile.close();
	return 0;
}

