#pragma once
#include "User.h"
class GameController;

class Player :
	public User
{
public:
	Player();
	Player(Shapes & a, int sizeBoard) :User(a, sizeBoard) {};
	~Player();
	int getSize() { return (int)m_myShapes.size(); }
	virtual void playTurn(sf::RenderWindow & window,const vector<std::unique_ptr<sf::RectangleShape>> & buttons
		, sf::Color otherColor, int sizeBoard, GameController & game);
};

