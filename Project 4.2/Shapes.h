#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;

class Shapes
{
public:
	Shapes();
	virtual ~Shapes() = 0;
	virtual void printShape(sf::RenderWindow & window) = 0;
	void chooseColor();
	virtual void setColor() = 0;
	void setColor(sf::Color c) { m_color = c; setColor(); }
	virtual bool isNeighbor(Shapes & a);
	virtual float getRadius() = 0;
	virtual void addMe(Shapes & a);
	bool getifConquered() { return m_conquered; }
	void setConquered() { m_conquered = true; }
	virtual void setConquered(bool c) = 0;
	virtual void setOutline() = 0;
	void conquered(vector<Shapes*> & m_myShapes, sf::Color C);
	sf::Color getColor();
	virtual sf::Vector2f getCenter() = 0;

protected:
	sf::Color m_color;
	vector<Shapes*> m_neighbors;
	bool m_conquered = false;
};

