#pragma once
#ifndef __PUZZLE_H__
#define __PUZZLE_H__
#include <string>
#include <iostream>
using namespace std;

struct Puzzle
{
	Puzzle();
	Puzzle(string info1, string info2, string info3, string info4, string solution);
	~Puzzle();

	void m_setUpPuzzle(string info1, string info2, string info3, string info4, string solution);
	string getSolution();
	void m_displayPuzzle();

	string 
		m_puzzleInfo1,
		m_puzzleInfo2,
		m_puzzleInfo3,
		m_puzzleInfo4,
		m_solution;
};
#endif // !__PUZZLE_H__
