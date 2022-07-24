#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include"Map.h"
#include"Player.h"

struct level
{
	std::vector<std::vector<unsigned char>> map;
	std::vector<sf::Vector2i> playerPosiitons;
	std::vector<sf::Color> colorSet;
	std::vector<bool> playerInverse;
};

class LevelManager
{
private:
	bool init = false;
	std::vector<level> levels;

public:
	LevelManager();

	bool isInit() { return this->init; }
	void loadLevel(int levelNumber, Map* currentMap);
	void loadLevel(int levelNumber, Map* currentMap, std::vector<Player*>* players);
};

