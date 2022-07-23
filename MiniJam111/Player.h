#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Map.h"
#include "Keyboard.h"

class Player
{
private:
	Map* currentLevel;

	sf::Vector2i location;
	sf::Vector2i move_vector;

	clock_t waitTime;
	bool waitingForMove = false;
	float timeToWait = 200;

public:
	Player(sf::Vector2i location, Map* currentLevel);
	void draw(sf::RenderWindow& window);
	void update();
	void setPosition(sf::Vector2i location);

	sf::Vector2i getCurrentTile();

};