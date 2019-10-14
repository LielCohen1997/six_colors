#include "Player.h"
#include "GameController.h"

using sf::Event;
using sf::Vector2f;

Player::Player()
{
}


Player::~Player()
{
}

void Player::playTurn(sf::RenderWindow & window
	, const vector<std::unique_ptr<sf::RectangleShape>> & buttons
	, sf::Color otherColor, int sizeBoard, GameController & game)
{
	sf::Event event;
	bool madeChoice = false;
	while (!madeChoice)
	{

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				exit(EXIT_SUCCESS);
				break;
			case Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Button::Left) // User clicked on the Mouse on left
				{
					const Vector2f mousePosition = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
					if (buttons[6]->getGlobalBounds().contains(mousePosition)) // Player clicked restart
					{
						game.restart();
						madeChoice = true;
						break;
					}
					for (int i = 0; i < 6 ; i++)
					{
						if (buttons[i]->getGlobalBounds().contains(mousePosition))
						{
							if (m_myColor == buttons[i]->getFillColor() || otherColor == buttons[i]->getFillColor())
								break;
							m_myColor = buttons[i]->getFillColor();
							takeOverTheWorld();
							madeChoice = true;
							break;
						}
					}
				}
				break;
			}
			if (madeChoice)
				break;
		}
	}
}
