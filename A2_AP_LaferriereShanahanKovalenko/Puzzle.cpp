#include "Puzzle.h"

Puzzle::Puzzle()
{

}

Puzzle::Puzzle(string info1, string info2, string info3, string info4, string solution)
{
	m_setUpPuzzle(info1, info2, info3, info4, solution);
}

Puzzle::~Puzzle()
{

}

void Puzzle::m_setUpPuzzle(string info1, string info2, string info3, string info4, string solution)
{
	m_puzzleInfo1 = info1;
	m_puzzleInfo2 = info2;
	m_puzzleInfo3 = info3;
	m_puzzleInfo4 = info4;
	m_solution = solution;
}

string Puzzle::getSolution()
{
	return m_solution;
}

void Puzzle::m_displayPuzzle()
{
	cout << endl << m_puzzleInfo1 << endl;
	cout << m_puzzleInfo2 << endl;
	cout << m_puzzleInfo3 << endl;
	cout << m_puzzleInfo4 << endl;
}