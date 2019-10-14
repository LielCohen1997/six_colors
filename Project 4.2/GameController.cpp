#include "GameController.h"

using sf::Event;
using sf::Vector2f;

GameController::GameController()
{
	m_window.create(sf::VideoMode(SIZE - 60, SIZE + 40), "SixColors", sf::Style::Close | sf::Style::Titlebar);
	// Create button 
	m_buttons.resize(7);
	for (int i = 0; i < 6; ++i)
	{
		m_buttons[i] = std::make_unique<sf::RectangleShape>(sf::Vector2f(40, 40));
		m_buttons[i]->setPosition(sf::Vector2f(50 + ((float)i * 80), 540));
		m_buttons[i]->setOutlineThickness(4);
	}

	// Color selection
	m_buttons[0]->setFillColor(sf::Color(10, 240, 255)); // Light blue
	m_buttons[1]->setFillColor(sf::Color(124, 57, 158)); // Purple
	m_buttons[2]->setFillColor(sf::Color(255, 154, 0)); // Orange
	m_buttons[3]->setFillColor(sf::Color(0, 255, 0)); // Green
	m_buttons[4]->setFillColor(sf::Color(255, 0, 127)); // Pink
	m_buttons[5]->setFillColor(sf::Color(255, 255, 0)); // Yellow

	// Restart button
	m_buttons[6] = std::make_unique<sf::RectangleShape>(sf::Vector2f(60, 20));
	m_buttons[6]->setPosition(sf::Vector2f(20, 605));
	m_buttons[6]->setFillColor(sf::Color::Transparent);

	m_restartT.setFont(m_font);
	m_restartT.setCharacterSize(15);
	m_restartT.setPosition(sf::Vector2f(20, 600));
	m_restartT.setFillColor(sf::Color::White);
	m_restartT.setString("Restart");

	m_player = Player(*m_board[1], m_board.getSize());
	m_computer = Computer(*m_board[2], m_board.getSize());

	m_font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
	m_playerT.setFont(m_font);
	m_playerT.setCharacterSize(15);
	m_playerT.setPosition(sf::Vector2f(110, 600));
	m_playerT.setFillColor(sf::Color::White);

	m_computerT.setFont(m_font);
	m_computerT.setCharacterSize(15);
	m_computerT.setPosition(sf::Vector2f(300, 600));
	m_computerT.setFillColor(sf::Color::White);
}

void GameController::run()
{
	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(500, 500));
	rectangle.setPosition(20, 20);*/
	sf::Event event;

	m_window.clear(sf::Color(0, 51, 0));
	m_board.printBoard(m_window);
	printButtons();
	m_window.display();

	while (m_window.isOpen())
	{
		// While no one conquered half the board: 
		while (m_player.getScore() < 0.5 && m_computer.getScore() < 0.5)
		{

			m_player.playTurn(m_window, m_buttons, m_computer.getColor(), m_board.getSize(), *this);
			m_player.changeColor();
			m_player.setScore(m_board.getSize());
			
			m_window.clear(sf::Color(0, 51, 0));
			m_board.printBoard(m_window);
			printButtons();
			m_window.display();

			if (m_player.getSize() == 1)
				continue;

			m_computer.playTurn(m_window, m_buttons, m_player.getColor(), m_board.getSize(), *this);
			m_computer.changeColor();
			m_computer.setScore(m_board.getSize());


			m_window.clear(sf::Color(0, 51, 0));
			m_board.printBoard(m_window);
			printButtons();
			m_window.display();

			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					m_window.close();
					exit(EXIT_SUCCESS);
					break;
				case Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Button::Left) // User clicked on the Mouse on left
					{
						const Vector2f mousePosition = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
						if (m_buttons[6]->getGlobalBounds().contains(mousePosition))
							restart();
					}
				}
			}


		}

		if (m_player.getScore() >= 0.5)
			m_playerT.setString("You won!");
		else
			m_playerT.setString("You lose!");
		m_playerT.setPosition(sf::Vector2f(50, 100));
		m_playerT.setCharacterSize(60);
		m_playerT.setFillColor(sf::Color::Black);

		m_window.draw(m_playerT);
		m_window.display();

		m_playerT.setFont(m_font);
		m_playerT.setCharacterSize(15);
		m_playerT.setPosition(sf::Vector2f(110, 600));
		m_playerT.setFillColor(sf::Color::White);

		bool n = true;
		while (n)
		{
			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					m_window.close();
					exit(EXIT_SUCCESS);
					break;
				case Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Button::Left) // User clicked on the Mouse on left
					{
						const Vector2f mousePosition = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
						if (m_buttons[6]->getGlobalBounds().contains(mousePosition))
						{
							restart();
							m_window.clear(sf::Color(0, 51, 0));
							m_board.printBoard(m_window);
							printButtons();
							m_window.display();
							n = false;
						}
						break;
					}
				}
				if (!n)
				{
					break;
				}
			}
		}

	}
}

void GameController::printButtons()
{
	for (int i = 0; i < 7; ++i)
		m_window.draw(*m_buttons[i]);

	m_playerT.setString("Player: " + std::to_string(m_player.getScore()));
	m_computerT.setString("Computer: " + std::to_string(m_computer.getScore()));

	m_window.draw(m_restartT);
	m_window.draw(m_playerT);
	m_window.draw(m_computerT);
}

void GameController::restart()
{
	m_board.restartColors();
	m_player.restart(m_board.getSize());
	m_computer.restart(m_board.getSize());
}
