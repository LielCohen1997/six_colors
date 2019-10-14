#pragma once
#include "Board.h"
#include "Player.h"
#include "Computer.h"
#include <SFML/Graphics.hpp>

const int SIZE = 600;

class GameController
{
public:
	GameController();
	~GameController() = default;
	void run();
	void printButtons();
	void restart();

private:
	sf::RenderWindow m_window;
	bool m_computersTurn = false;
	Board m_board;
	Player m_player;
	Computer m_computer;
	vector<std::unique_ptr<sf::RectangleShape>> m_buttons;

	sf::Font m_font;

	sf::Text m_restart;
	sf::Text m_playerT;
	sf::Text m_computerT;
	sf::Text m_restartT;

};

