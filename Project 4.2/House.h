#pragma once
#include "Shapes.h"
class House :
	public Shapes
{
public:
	House(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4);
	~House();
	virtual void printShape(sf::RenderWindow & window);
	void setColor();
	virtual float getRadius();
	virtual void setOutline() { m_hou.setOutlineColor(m_color); }
	virtual void setConquered(bool c);
	virtual sf::Vector2f getCenter();
private:
	sf::ConvexShape m_hou;
};

