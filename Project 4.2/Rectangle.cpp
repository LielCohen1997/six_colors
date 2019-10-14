#include "Rectangle.h"
#include <random>


Rectangle::Rectangle(sf::Vector2f c)
{
	m_rect.setRadius(9);
	m_rect.setPosition(c);
	m_rect.setPointCount(4);
	m_rect.setOutlineThickness(1);
	m_rect.setOutlineColor(sf::Color::Black);
}

Rectangle::~Rectangle()
{
}

void Rectangle::printShape(sf::RenderWindow & window)
{
	window.draw(m_rect);
}

void Rectangle::setColor()
{
	m_rect.setFillColor(m_color);
}

float Rectangle::getRadius()
{
	return m_rect.getRadius();
}

void Rectangle::setConquered(bool c)
{
	m_conquered = c;
	m_rect.setOutlineColor(sf::Color::Black);
}

sf::Vector2f Rectangle::getCenter()
{
	float rad = (float)this->getRadius();
	return sf::Vector2f(m_rect.getPosition().x + rad, m_rect.getPosition().y + rad);
}

