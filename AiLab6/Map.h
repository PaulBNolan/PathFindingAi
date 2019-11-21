#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include "Tile.h"
class Map
{
public:
	Map(sf::Font& t_font);
	Tile *m_tiles[50][50];
	sf::Vector2f m_tilePos[50][50];


	bool m_createStartPoint = true;
	sf::Vector2i m_startPoint;
	sf::Vector2i m_endPoint;

	std::map<int,int> m_map;
	void createWalls(sf::Vector2f t_mousePosition);
	void createPoints(sf::Vector2f t_mousePosition);
	void createCostField();

	void render(sf::RenderWindow &t_window);
};

