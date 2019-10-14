#include "House.h"


House::House(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4)
{
	m_hou.setPointCount(5);
	m_hou.setPoint(0, p0);
	m_hou.setPoint(1, p1);
	m_hou.setPoint(2, p2);
	m_hou.setPoint(3, p3);
	m_hou.setPoint(4, p4);
	m_hou.setOutlineThickness(1);
	m_hou.setOutlineColor(sf::Color::Black);
	m_hou.setFillColor(sf::Color::Green);
}

House::~House()
{
}

void House::printShape(sf::RenderWindow & window)
{
	window.draw(m_hou);
}

void House::setColor()
{
	m_hou.setFillColor(m_color);
}

float House::getRadius()
{
	sf::Vector2f center = this->getCenter();
	float radius = sqrt(pow((center.x - m_hou.getPoint(1).x), 2) + pow((center.y - m_hou.getPoint(1).y), 2));
	return radius;
}

void House::setConquered(bool c)
{
	m_conquered = c;
	m_hou.setOutlineColor(sf::Color::Black);
}

sf::Vector2f House::getCenter()
{
	float x = 0;
	float y = 0;
	for (int i = 0; i < 5; ++i)
	{
		x += m_hou.getPoint(i).x;
		y += m_hou.getPoint(i).y;
	}
	x = x / 5;
	y = y / 5;
	return sf::Vector2f(x, y);
}
