#include "Map.h"

Map::Map(sf::Font& t_font)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			m_tiles[i][j] = new Tile(t_font,sf::Vector2f(i * 41, j * 41));
		}
	}
}

void Map::createWalls(sf::Vector2f t_mousePosition)
{
	int i = t_mousePosition.x / 41;
	int j = t_mousePosition.y / 41;

	m_tiles[i][j]->setColor(sf::Color::Black);
	m_tiles[i][j]->setCost(999);
	m_tiles[i][j]->m_wall = true;
}

void Map::createPoints(sf::Vector2f t_mousePosition)
{
	int i = t_mousePosition.x / 41;
	int j = t_mousePosition.y / 41;

	if (m_createStartPoint == true)
	{
		if (m_startPoint.x != NULL)
		{
			m_tiles[m_startPoint.x][m_startPoint.y]->setColor(sf::Color::Blue);
		}

		m_startPoint = sf::Vector2i(i, j);

		m_tiles[i][j]->setColor(sf::Color::Green);

		m_createStartPoint = false;

		createCostField();
	}
	else
	{
		if (m_endPoint.x != NULL)
		{
			m_tiles[m_endPoint.x][m_endPoint.y]->setColor(sf::Color::Blue);
		}

		m_endPoint = sf::Vector2i(i, j);

		m_tiles[i][j]->setColor(sf::Color::Red);

		m_createStartPoint = true;
	}
}

void Map::createCostField()
{
	//for (int i = 0; i < 50; i++)
	//{
	//	for (int j = 0; j < 50; j++)
	//	{
	//		if (m_tiles[i][j]->m_wall == false)
	//		{
//
	//			m_tiles[i][j]->setCost(
	//				sqrt(pow(i - m_startPoint.x, 2) +
	//					pow(j - m_startPoint.y, 2)));
	//			std::cout << "X: " << i << " Y: " << j << " Cost: " << sqrt(pow(i - m_startPoint.x, 2) + pow(j - m_startPoint.y, 2)) << std::endl;
	//		}
	//	}
	//}
	
}

void Map::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			m_tiles[i][j]->render(t_window);
		}
	}
}