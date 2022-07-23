#include"LevelManager.h"

LevelManager::LevelManager()
{

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL ONE        				/////////////
	/////////////////////////////////////////////////////////////////
	*/
	level levelOne;
	levelOne.map =
	{
		{ 1, 0, 2, 2,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{15,15,15, 0,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelOne.playerPosiitons.push_back(sf::Vector2i{ 0,0 });
	levelOne.playerPosiitons.push_back(sf::Vector2i{ 9,9 });
	levelOne.colorSet = std::vector<sf::Color>{ sf::Color::Red, sf::Color::Green, sf::Color::Blue };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL TWO        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelTwo;
	levelTwo.map =
	{
		{ 1, 0, 2, 2,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{ 0, 0, 0, 0,15,15,15,15,15,15},
		{15,15,15, 0,15,15,15,15,15,15},
		{15,15,15, 0,15,15,15,15,15,15},
		{15,15,15, 0, 0, 0, 0, 0, 2, 2},
		{15,15,15,15,15,15, 0, 0, 0, 0},
		{15,15,15,15,15,15, 0, 0, 0, 0},
		{15,15,15,15,15,15, 0, 0, 0, 0}
	};
	levelTwo.playerPosiitons.push_back(sf::Vector2i{ 0,0 });
	//levelTwo.playerPosiitons.push_back(sf::Vector2i{ 1,1 });
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

	// Cleaning up the players.
	for (int i = players->size()-1; i >= 0; i--)
	{
		delete (*players)[i];
	}
	players->clear();

	// Adding new players.
	for (int i = 0; i < this->levels[levelNumber].playerPosiitons.size(); i++)
	{
		Player* player = new Player(this->levels[levelNumber].playerPosiitons[i], currentMap);
		players->push_back(player);
	}
	// Adding the levels and colors.
	currentMap->loadMap(this->levels[levelNumber].map);
	currentMap->setColors(this->levels[levelNumber].colorSet);

	std::cout << "Level Loaded." << std::endl;
}