#include "Tile.h"

Tile::Tile(sf::Font& t_font,sf::Vector2f t_position)
{
	m_tile.setSize(sf::Vector2f(40, 40));
	setPosition(t_position);
	setColor(sf::Color::Blue);
	setCost(0);

	m_costText.setCharacterSize(20);
	m_costText.setFont(t_font);
	m_costText.setFillColor(sf::Color::White);  
	m_wall = false;
}

void Tile::setPosition(sf::Vector2f t_position)
{
	m_tile.setPosition(t_position);
	m_costText.setPosition(t_position);
}

void Tile::setColor(sf::Color t_color)
{
	m_tile.setFillColor(t_color);
}

void Tile::setCost(int t_cost)
{
	m_cost = t_cost;
	m_costText.setString(std::to_string(t_cost));
}

void Tile::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_tile);
	t_window.draw(m_costText);
}