#include"LevelManager.h"

LevelManager::LevelManager()
{

	/*
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	 15,15,15,15,15,15,15,15,15,15
	
	
	*/

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL ONE        				/////////////
	/////////////////////////////////////////////////////////////////
	*/
	level levelOne;
	levelOne.map =
	{
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15, 2,15,15,15,15,15,15,15},
		{15,15, 1,15, 1, 1, 1, 1,15,15},
		{15,15, 1,15, 1,15,15, 1,15,15},
		{15,15, 1,15,15,15,15, 1,15,15},
		{15,15, 1, 1, 1, 1, 1, 1,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelOne.playerPosiitons.push_back(sf::Vector2i{ 2,2 });
	levelOne.playerInverse.push_back(false);
	levelOne.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL TWO        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelTwo;
	levelTwo.map =
	{
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15, 2,15, 1,15,15, 1, 1, 1,15},
		{15, 1,15, 1,15,15, 1,15, 1,15},
		{15, 1,15, 1,15,15, 1,15, 1,15},
		{15, 1, 1, 1,15,15, 1,15, 2,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelTwo.playerPosiitons.push_back(sf::Vector2i{ 3,1 });
	levelTwo.playerPosiitons.push_back(sf::Vector2i{ 6,8 });
	levelTwo.playerInverse.push_back(false);
	levelTwo.playerInverse.push_back(true);
	levelTwo.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL THREE        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelThree;
	levelThree.map =
	{
		{15,15,15,15,15,15,15,15,15,15},
		{15, 1, 2, 1,15,15, 1, 1, 1,15},
		{15,15, 1,15,15,15,15, 1,15,15},
		{15, 1, 1, 1,15,15, 1, 1, 1,15},
		{15,15, 1,15,15,15,15, 1,15,15},
		{15, 1, 1, 1,15,15, 1, 1, 1,15},
		{15,15, 1,15,15,15,15, 1,15,15},
		{15, 1, 1, 1,15,15, 1, 1, 1,15},
		{15,15, 1,15,15,15,15, 2,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelThree.playerPosiitons.push_back(sf::Vector2i{ 1,2 });
	levelThree.playerPosiitons.push_back(sf::Vector2i{ 8,7 });
	levelThree.playerInverse.push_back(false);
	levelThree.playerInverse.push_back(true);
	levelThree.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL FOUR        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelFour;
	levelFour.map =
	{
		{15,15,15,15,15,15,15,15,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1,15,15,15,15,15,15, 1,15},
		{15, 1, 1, 1, 1, 1, 1, 1, 1,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelFour.playerPosiitons.push_back(sf::Vector2i{ 1,2 });
	levelFour.playerPosiitons.push_back(sf::Vector2i{ 8,7 });
	levelFour.playerInverse.push_back(false);
	levelFour.playerInverse.push_back(true);
	levelFour.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Red };

	this->levels.push_back(levelOne);
	this->levels.push_back(levelTwo);
	this->levels.push_back(levelThree);
	this->levels.push_back(levelFour);

	this->totalLevels = this->levels.size();
}

void LevelManager::loadLevel(int levelNumber, Map* currentMap, std::vector<Player*>* players)
{

	this->currentLevel = levelNumber;
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
		Player* player = new Player(this->levels[levelNumber].playerPosiitons[i], currentMap, this->levels[levelNumber].playerInverse[i]);
		players->push_back(player);
	}
	// Adding the levels and colors.
	currentMap->loadMap(this->levels[levelNumber].map);
	currentMap->setColors(this->levels[levelNumber].colorSet);

	std::cout << "Level Loaded." << std::endl;
}