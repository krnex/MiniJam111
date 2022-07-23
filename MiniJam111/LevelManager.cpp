#include"LevelManager.h"

LevelManager::LevelManager()
{
	level levelOne;
	levelOne.map =
	{
		{ 1, 0, 2, 2,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelOne.playerPosiitons.push_back(sf::Vector2i{ 0,0 });
	levelOne.playerPosiitons.push_back(sf::Vector2i{ 9,9 });
	levelOne.colorSet = std::vector<sf::Color>{ sf::Color::Red, sf::Color::Green, sf::Color::Blue };

	level levelTwo;
	levelTwo.map =
	{
		{ 1, 0, 2, 2,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15, 0, 0, 2, 2},
		{15,15,15,15,15,15, 0, 0, 0, 0},
		{15,15,15,15,15,15, 0, 0, 0, 0},
		{15,15,15,15,15,15, 0, 0, 0, 0}
	};
	levelTwo.playerPosiitons.push_back(sf::Vector2i{ 0,0 });
	levelTwo.playerPosiitons.push_back(sf::Vector2i{ 9,9 });
	levelTwo.colorSet = std::vector<sf::Color>{ sf::Color::Red, sf::Color::Green, sf::Color::Blue };

	this->levels.push_back(levelOne);
	this->levels.push_back(levelTwo);
}

void LevelManager::loadLevel(int levelNumber, Map* currentMap)
{
	currentMap->loadMap(this->levels[levelNumber].map);
	currentMap->setColors(this->levels[levelNumber].colorSet);
}

void LevelManager::loadLevel(int levelNumber, Map* currentMap, std::vector<Player*>* players)
{
	currentMap->loadMap(this->levels[levelNumber].map);

	for (int i = 0; i < players->size(); i++)
	{
		(*players)[i]->setPosition(this->levels[levelNumber].playerPosiitons[i]);
	}
	currentMap->loadMap(this->levels[levelNumber].map);
	currentMap->setColors(this->levels[levelNumber].colorSet);

	std::cout << "Level Loaded." << std::endl;
}