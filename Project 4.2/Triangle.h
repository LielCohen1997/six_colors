#pragma once
#include "Shapes.h"
class Triangle : public Shapes
{
public:
	Triangle();
	~Triangle();
	virtual void printShape(sf::RenderWindow & window);
	void setColor();
	virtual float getRadius();
	virtual void setOutline() { m_tri.setOutlineColor(m_color); }
	virtual void setConquered(bool c);
	virtual sf::Vector2f getCenter();
private:
	sf::CircleShape m_tri;
};
