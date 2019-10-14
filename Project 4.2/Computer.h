#pragma once
#include "User.h"
class GameController;

class Computer :
	public User
{
public:
	Computer();
	Computer(Shapes & a, int sizeBoard);
	~Computer();
	virtual void playTurn(sf::RenderWindow & window,const vector<std::unique_ptr<sf::RectangleShape>> & buttons
		, sf::Color otherColor, int sizeBoard, GameController & game);
private:
	vector<sf::Color> m_colorOptions;
};

