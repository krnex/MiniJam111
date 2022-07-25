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
		{0,15,15,15,15,15,15,15,15,15},
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
		{ 0,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15, 2, 1, 1,15,15, 1, 1, 1,15},
		{15, 1, 1, 1,15,15, 1, 1, 1,15},
		{15, 1, 1, 1,15,15, 1, 1, 1,15},
		{15, 1, 1, 1,15,15, 1, 1, 2,15},
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
		{ 0,15,15,15,15,15,15,15,15,15},
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
		{0 ,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{ 3, 0, 0, 0, 1, 1, 0, 0, 0, 3},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelFour.playerPosiitons.push_back(sf::Vector2i{ 4,0 });
	levelFour.playerPosiitons.push_back(sf::Vector2i{ 4,9 });
	levelFour.playerInverse.push_back(false);
	levelFour.playerInverse.push_back(true);
	levelFour.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Blue, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL FOUR        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelFive;
	levelFive.map =
	{
		{0 ,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15, 1,15,15},
		{15,15,15,15,15,15,15, 1,15,15},
		{15,15, 2, 1, 3, 1,15, 1,15,15},
		{15,15, 1, 3, 3, 1,15, 1,15,15},
		{15,15, 1, 3, 3, 1,15, 1,15,15},
		{15,15, 1, 3, 1, 1,15, 1,15,15},
		{15,15,15,15,15,15,15, 1,15,15},
		{15,15,15,15,15,15,15, 2,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelFive.playerPosiitons.push_back(sf::Vector2i{ 3,2 });
	levelFive.playerPosiitons.push_back(sf::Vector2i{ 8,7 });
	levelFive.playerInverse.push_back(false);
	levelFive.playerInverse.push_back(true);
	levelFive.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Blue, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL SIX        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelSix;
	levelSix.map =
	{
		{0 ,15,15,15,15,15,15,15,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1,15, 1,15, 1,15, 1,15,15},
		{15, 1, 1, 1, 2, 1, 1, 1,15,15},
		{15, 1,15, 1,15, 1,15, 1,15,15},
		{15, 1, 1, 1, 2, 1, 1, 1,15,15},
		{15, 1,15, 1,15, 1,15, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelSix.playerPosiitons.push_back(sf::Vector2i{ 1,1 });
	levelSix.playerPosiitons.push_back(sf::Vector2i{ 7,7 });
	levelSix.playerInverse.push_back(false);
	levelSix.playerInverse.push_back(true);
	levelSix.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Blue, sf::Color::Red };

	/*
	/////////////////////////////////////////////////////////////////
	//////////			LEVEL SEVEN        				/////////////
	/////////////////////////////////////////////////////////////////
	*/

	level levelSeven;
	levelSeven.map =
	{
		{0 ,15,15,15,15,15,15,15,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1, 1, 1, 2, 1, 1, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15, 1, 1, 1, 1, 1, 1, 1,15,15},
		{15,15,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15}
	};
	levelSeven.playerPosiitons.push_back(sf::Vector2i{ 1,1 });
	levelSeven.playerPosiitons.push_back(sf::Vector2i{ 7,7 });
	levelSeven.playerInverse.push_back(false);
	levelSeven.playerInverse.push_back(true);
	levelSeven.colorSet = std::vector<sf::Color>{ sf::Color::Cyan, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Red };


	this->levels.push_back(levelOne);
	this->levels.push_back(levelTwo);
	this->levels.push_back(levelThree);
	this->levels.push_back(levelFour);
	this->levels.push_back(levelFive);
	this->levels.push_back(levelSix);
	this->levels.push_back(levelSeven);

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