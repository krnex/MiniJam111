#include"Map.h"

Map::Map(int width, int height)
{
	blank_tile = 15;
	this->initilize_map(width, height);
}

void Map::initilize_map(int width, int height)
{
	int buffer = height * 0.1;
	this->tile_size = (height - buffer) / this->size.y;
	this->center_offset = static_cast<sf::Vector2f>(sf::Vector2i{ (width - (this->size.x * this->tile_size)) / 2, (height - (this->size.y * this->tile_size)) / 2 });

	for (int x = 0; x < this->size.x; x++)
	{
		std::vector<unsigned char> row;
		for (int y = 0; y < this->size.y; y++)
		{
			row.push_back(x % 2);
		}
		this->map.push_back(row);
	}

	this->map[1][0] = 3;
}

void Map::loadMap(std::vector<std::vector<unsigned char>> map)
{
	this->map = map;
}

void Map::setColors(std::vector<sf::Color> colors)
{
	tile_colors = colors;
}

sf::Vector2f Map::getLocationFromTile(sf::Vector2i location)
{
	return sf::Vector2f{ location.y * this->tile_size + this->center_offset.y, location.x * this->tile_size + this->center_offset.x };
}

bool Map::isValidMove(sf::Vector2i location)
{
	bool valid_move = true;
	
	if (location.x < 0 || location.x >= this->size.x)
	{
		valid_move = false;
	}
	else if (location.y < 0 || location.y >= this->size.y)
	{
		valid_move = false;
	}
	else 
	{
		valid_move = map[location.x][location.y] != this->blank_tile;
	}


	return valid_move;
}

void Map::updateTile(sf::Vector2i location)
{
	int new_value = (map[location.x][location.y] + 1) % (this->tile_colors.size()-1);
	if (map[location.x][location.y] < tile_colors.size()-1)
	{
		map[location.x][location.y] = new_value;
	}
}

void Map::draw(sf::RenderWindow& window)
{
	for (int y = 0; y < this->size.y; y++)
	{
		for (int x = 0; x < this->size.x; x++)
		{
			if (this->map[y][x] != blank_tile)
			{
				sf::RectangleShape rectangle;
				rectangle.setSize(sf::Vector2f{float(this->tile_size),float(this->tile_size)});
				rectangle.setFillColor(this->tile_colors[map[y][x]]);
				rectangle.setOutlineColor(sf::Color::Black);
				rectangle.setOutlineThickness(1);
				rectangle.setPosition(getLocationFromTile(sf::Vector2i{ y, x }));
				window.draw(rectangle);
			}
		}
	}
}

bool Map::checkWinCondition()
{
	bool wincon = true;

	for (std::vector<unsigned char> x : this->map)
	{
		for (unsigned char y : x)
		{
			if (int(y) < this->tile_colors.size()-1 &&
				int(y) != 0)
			{
				wincon = false;
				break;
			}
		}
		if (!wincon)
		{
			break;
		}
	}

	return wincon;
}
