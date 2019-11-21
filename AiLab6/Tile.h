#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Tile
{
public:
	Tile(sf::Font& t_font, sf::Vector2f t_position);

	void setPosition(sf::Vector2f t_position);
	void setColor(sf::Color t_color);
	void setCost(int t_cost);

	void render(sf::RenderWindow& t_window);

	sf::RectangleShape m_tile;
	sf::Text m_costText;
	int m_cost;

	bool m_wall;
};

