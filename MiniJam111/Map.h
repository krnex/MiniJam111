#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector.h"

class Map
{

private:
	const sf::Vector2i size{ 10, 10 };
	int tile_size;
	int blank_tile;
	sf::Vector2f center_offset;

	std::vector<std::vector<unsigned char>> map;
	std::vector<sf::Color> tile_colors{sf::Color::Red, sf::Color::Blue, sf::Color::Yellow};

	void initilize_map(int width, int height);

public:
	Map(int width, int height);

	void loadMap(std::vector<std::vector<unsigned char>> map);

	void draw(sf::RenderWindow& window);
	void updateTile(sf::Vector2i location);
	void setColors(std::vector<sf::Color> colors);

	sf::Vector2f getLocationFromTile(sf::Vector2i location);
	bool isValidMove(sf::Vector2i location);
	bool checkWinCondition();
};