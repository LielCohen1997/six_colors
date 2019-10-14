#include "Triangle.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

void Triangle::printShape(sf::RenderWindow & window)
{
	window.draw(m_tri);
}

void Triangle::setColor()
{
	m_tri.setFillColor(m_color);
}

float Triangle::getRadius()
{
	return m_tri.getRadius();
}

void Triangle::setConquered(bool c)
{
	m_conquered = c;
	m_tri.setOutlineColor(sf::Color::Black);
}

sf::Vector2f Triangle::getCenter()
{
	float rad = (float)this->getRadius();
	return sf::Vector2f(m_tri.getPosition().x + rad, m_tri.getPosition().y + rad);
}
