#pragma once
#include"Shapes.h"
#include "Board.h"
class GameController;

class User
{
public:
	User();
	User(Shapes & a, int sizeBoard);
	~User();
	void addShape(Shapes & a);
	void setScore(int sizeBoard);
	float getScore() const { return m_score; }
	virtual void playTurn(sf::RenderWindow & window, const vector<std::unique_ptr<sf::RectangleShape>> & buttons,
		sf::Color otherColor, int sizeBoard, GameController & game) = 0;
	sf::Color getColor() { return m_myColor; }
	void changeColor();
	void takeOverTheWorld();
	void restart( int boardSize);
protected:
	vector<Shapes*> m_myShapes;
	float m_score;
	sf::Color m_myColor;
};

