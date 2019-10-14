#pragma once
#include "Shapes.h"
class Rectangle : public Shapes
{
public:
	Rectangle(sf::Vector2f c);
	~Rectangle();
	virtual void printShape(sf::RenderWindow & window);
	void setColor();
	virtual float getRadius();
	virtual void setOutline() { m_rect.setOutlineColor(m_color); }
	virtual void setConquered(bool c);
	virtual sf::Vector2f getCenter();
private:
	sf::CircleShape m_rect;
};

