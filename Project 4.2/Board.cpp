#include "Board.h"
#include "Rectangle.h"
#include "Diamond.h"
#include "House.h"

const int BOARDSIZE = 30;

Board::Board()
{
	// Creates the diamonds for the corners
	m_board.push_back(std::make_unique<Diamond>(sf::Vector2f(20, 20), sf::Vector2f(20, 40),
		sf::Vector2f(30, 40), sf::Vector2f(40, 30), sf::Vector2f(40, 20)));
	m_board.push_back(std::make_unique<Diamond>(sf::Vector2f(20, 500), sf::Vector2f(20, 520),
		sf::Vector2f(40, 520), sf::Vector2f(40, 510), sf::Vector2f(30, 500)));
	m_board.push_back(std::make_unique<Diamond>(sf::Vector2f(500, 20), sf::Vector2f(520, 20),
		sf::Vector2f(520, 40), sf::Vector2f(510, 40), sf::Vector2f(500, 30)));
	m_board.push_back(std::make_unique<Diamond>(sf::Vector2f(500, 510), sf::Vector2f(500, 520),
		sf::Vector2f(520, 520), sf::Vector2f(520, 500), sf::Vector2f(510, 500)));

	// Creates top houses
	for(int i = 0; i < 23; ++i)
		m_board.push_back(std::make_unique<House>(sf::Vector2f(40 + i * 20, 20), sf::Vector2f(40 + i * 20, 30),
			sf::Vector2f(50 + i * 20, 40), sf::Vector2f(60 + i * 20, 30), sf::Vector2f(60 + i * 20, 20)));
	// Creates left Houses
	for (int i = 0; i < 23; ++i)
		m_board.push_back(std::make_unique<House>(sf::Vector2f(20, 40 + i * 20), sf::Vector2f(30,40 + i * 20),
			sf::Vector2f(40, 50 + i * 20), sf::Vector2f(30, 60 + i * 20), sf::Vector2f(20, 60 + i * 20)));

	// Creates bottom houses
	for (int i = 0; i < 23; ++i)
		m_board.push_back(std::make_unique<House>(sf::Vector2f(40 + i * 20, 520), sf::Vector2f(40 + i * 20, 510),
			sf::Vector2f(50 + i * 20, 500), sf::Vector2f(60 + i * 20, 510), sf::Vector2f(60 + i * 20, 520)));

	// Creates right houses
	for (int i = 0; i < 23; ++i)
		m_board.push_back(std::make_unique<House>(sf::Vector2f(510, 40 + i * 20), sf::Vector2f(520, 40 + i * 20),
			sf::Vector2f(520, 60 + i * 20), sf::Vector2f(510, 60 + i * 20), sf::Vector2f(500, 50 + i * 20)));

	// Creates rectangles 1
	for (int i = 0; i < 24; ++i)
		for (int j = 0; j < 24; j++)
			m_board.push_back(std::make_unique<Rectangle>(sf::Vector2f(30 + j * 20, 30 + i * 20)));

	// Creates rectangles 2
	for (float i = 0; i < 23; ++i)
		for (float j = 0; j < 23; j++)
			m_board.push_back(std::make_unique<Rectangle>(sf::Vector2f(40 + j * 20, 40 + i * 20)));
	
	// Sets colors for the shapes 
	for (int i = 0; i < (int)m_board.size(); ++i)
	{
		m_board[i]->chooseColor();
		m_board[i]->setColor();
	}

	for (int i = 0; i < (int)m_board.size(); ++i)
	{
		for (int j = i; j < (int)m_board.size(); ++j)
			if (m_board[i] != m_board[j])
			{
				if (m_board[i]->isNeighbor(*m_board[j]))
					m_board[j]->addMe(*m_board[i]);
			}
	}
}


Board::~Board()
{
}

void Board::printBoard(sf::RenderWindow & window)
{
	for (int i = 0; i < m_board.size(); i++)
		m_board[i]->printShape(window);
}

// Select new colors randomly
void Board::restartColors()
{
	for (int i = 0; i < (int)m_board.size(); ++i)
	{
		m_board[i]->chooseColor();
		m_board[i]->setColor();
		m_board[i]->setConquered(false);
	}
}
