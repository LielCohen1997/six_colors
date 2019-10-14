#include "Shapes.h"
#include <random>
#include <cstdlib>


Shapes::Shapes()
{
}


Shapes::~Shapes()
{
}

// Randomly select a color
void Shapes::chooseColor()
{
	int select = rand() % 6;
	switch (select)
	{
	case 0:
		m_color = sf::Color(10, 240, 255); // Light blue
		break;
	case 1:
		m_color = sf::Color(124, 57, 158); // Purple
		break;
	case 2:
		m_color = sf::Color(255, 154, 0); // Orange
		break;
	case 3:
		m_color = sf::Color(0, 255, 0); // Green
		break;
	case 4:
		m_color = sf::Color(255, 0, 127); // Pink
		break;
	case 5:
		m_color = sf::Color(255, 255, 0); // Yellow
		break;
	}
}

// Check if neighbors
bool Shapes::isNeighbor(Shapes & a)
{
	float myRadius = this->getRadius();
	float otherRadius = a.getRadius();

	sf::Vector2f myCenter = this->getCenter();
	sf::Vector2f otherCenter = a.getCenter();

	int distance = sqrt(pow((myCenter.x - otherCenter.x), 2) + pow((myCenter.y - otherCenter.y), 2));
	if (myRadius + otherRadius > distance)
	{
		m_neighbors.push_back(&a);
		return true;
	}
	return false;
}

void Shapes::addMe(Shapes & a)
{
	m_neighbors.push_back(&a);
}

void Shapes::conquered(vector<Shapes*>& m_myShapes, sf::Color c)
{
	for (int i = 0; i < m_neighbors.size(); ++i)
	{
		if (!m_neighbors[i]->getifConquered())
		{
			if (m_neighbors[i]->getColor() == c)
			{
				m_neighbors[i]->setColor(c);
				m_myShapes.push_back(m_neighbors[i]);
				// m_neighbors[i]->setOutline();
				m_neighbors[i]->setConquered();
			}
		}
	}
}

sf::Color Shapes::getColor()
{
	return m_color;
}



