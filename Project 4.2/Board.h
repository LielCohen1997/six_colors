#pragma once

#include <vector>
#include "Shapes.h"

using std::vector;

class Board
{
public:
	Board();
	~Board();
	void printBoard(sf::RenderWindow & window);
	int getSize() { return (int)m_board.size(); }
	void restartColors();

	std::unique_ptr<Shapes>& operator[](int x) { return m_board[x]; };
private:
	vector<std::unique_ptr<Shapes>> m_board;
};

