#include "Computer.h"
#include "GameController.h"


Computer::Computer()
{
}

Computer::Computer(Shapes & a, int sizeBoard) :User(a, sizeBoard)
{
	m_colorOptions.push_back(sf::Color(10, 240, 255)); // Light blue
	m_colorOptions.push_back(sf::Color(124, 57, 158)); // Purple
	m_colorOptions.push_back(sf::Color(255, 154, 0)); // Orange
	m_colorOptions.push_back(sf::Color(0, 255, 0)); // Green
	m_colorOptions.push_back(sf::Color(255, 0, 127)); //  Pink
	m_colorOptions.push_back(sf::Color(255, 255, 0)); // Yellow
}


Computer::~Computer()
{
}

// Computer chooses a color
void Computer::playTurn(sf::RenderWindow & window
	, const vector<std::unique_ptr<sf::RectangleShape>> & buttons
	, sf::Color otherColor, int sizeBoard, GameController & game)
{
	float maxScore = 0;
	int shapesSize = m_myShapes.size();
	sf::Color colorChoice;
	for (int i = 0; i < m_colorOptions.size(); ++i)
	{
		// If it's not my color and not my opponents color
		if (m_colorOptions[i] != m_myColor && m_colorOptions[i] != otherColor)
		{
			m_myColor = m_colorOptions[i];
			takeOverTheWorld();
			setScore(sizeBoard);
			if (maxScore < getScore())
			{
				maxScore = getScore();
				colorChoice = m_colorOptions[i];
			}
			for (int i = m_myShapes.size() - 1; i >= shapesSize; --i)
			{
				m_myShapes[i]->setConquered(false);
				m_myShapes.pop_back();
			}
		}
	}
	m_myColor = colorChoice;
	takeOverTheWorld();
}

