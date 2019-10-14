#include "Diamond.h"



Diamond::Diamond(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4)
{
	m_dia.setPointCount(5);
	m_dia.setPoint(0, p0);
	m_dia.setPoint(1, p1);
	m_dia.setPoint(2, p2);
	m_dia.setPoint(3, p3);
	m_dia.setPoint(4, p4);
	m_dia.setOutlineThickness(1);
	m_dia.setOutlineColor(sf::Color::Black);
	m_dia.setFillColor(sf::Color::Red);

}

Diamond::~Diamond()
{
}

void Diamond::printShape(sf::RenderWindow & window)
{
	window.draw(m_dia);
}

void Diamond::setColor()
{
	m_dia.setFillColor(m_color);
}

float Diamond::getRadius()
{
	sf::Vector2f center = this->getCenter();

	float radius = sqrt(pow((center.x - m_dia.getPoint(1).x), 2) + pow((center.y - m_dia.getPoint(1).y), 2));
	return radius;
}

void Diamond::setConquered(bool c)
{
	m_conquered = c; 
	m_dia.setOutlineColor(sf::Color::Black);
}

sf::Vector2f Diamond::getCenter()
{
	float x = 0;
	float y = 0;
	for (int i = 0; i < 5; ++i)
	{
		x += m_dia.getPoint(i).x;
		y += m_dia.getPoint(i).y;
	}
	x = x / 5;
	y = y / 5;
	return sf::Vector2f(x, y);
}
