#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Map.h"
#include "Keyboard.h"

class Player
{
private:
	Map* currentLevel;

	sf::Vector2i location;
	sf::Vector2i move_vector;

	clock_t waitTime = 0;
	bool waitingForMove = true;
	float timeToWait = 180;
	sf::Color color;
	sf::Color outline;

	bool inverse = false;

	sf::SoundBuffer buffer;
	sf::Sound soundPlayer;

	float enlarge = 0.0f;
	float shrinkRate = 0.1f;
	float enlargeMax = 5.0f;

public:
	Player(sf::Vector2i location, Map* currentLevel, bool inverse);
	void draw(sf::RenderWindow& window);
	void update();
	void setPosition(sf::Vector2i location);

	sf::Vector2i getCurrentTile();

};