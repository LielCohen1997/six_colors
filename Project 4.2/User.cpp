#include "User.h"
#include "GameController.h"


User::User()
{
}

User::User(Shapes & a, int sizeBoard)
{
	addShape(a);
	setScore(sizeBoard);
	m_myColor = a.getColor();
	a.setConquered();
	a.setOutline();
	
}

User::~User()
{
}

void User::addShape(Shapes & a)
{
	m_myShapes.push_back(&a);
}

void User::setScore(int sizeBoard)
{
	m_score = (float)m_myShapes.size() / sizeBoard;
}

void User::changeColor()
{
	for (int i = 0; i < (int)m_myShapes.size(); ++i)
	{
		m_myShapes[i]->setColor(m_myColor);
		m_myShapes[i]->setOutline();
	}
		
}

void User::takeOverTheWorld()
{
	for (int i = 0; i < (int)m_myShapes.size(); ++i)
	{
		m_myShapes[i]->conquered(m_myShapes, m_myColor);
	}
}

void User::restart(int boardSize)
{
	m_myShapes.resize(1);
	setScore(boardSize);
}
