#include"Player.h"

Player::Player(sf::Vector2i location, Map* current, bool inverse)
{	
	this->currentLevel = current;
	this->location = location;
	this->inverse = inverse;
}

sf::Vector2i Player::getCurrentTile()
{
	return this->location;
}

void Player::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(30);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(1);
	circle.setPosition(currentLevel->getLocationFromTile(this->getCurrentTile()));

	window.draw(circle);
}

void Player::update()
{
	if (clock() >= waitTime + timeToWait)
	{
		waitingForMove = false;
	}


	move_vector = sf::Vector2i{ 0, 0 };

	sf::Keyboard::Key currentKey = Keyboard::GetInstance().getCurrentPressed();

	if(currentKey == sf::Keyboard::W)
	{
		move_vector = sf::Vector2i{ -1, 0 };
	}
	else if(currentKey == sf::Keyboard::A)
	{
		move_vector = sf::Vector2i{ 0, -1 };
	}
	else if (currentKey == sf::Keyboard::S)
	{
		move_vector = sf::Vector2i{ 1, 0 };
	}
	else if (currentKey == sf::Keyboard::D)
	{
		move_vector = sf::Vector2i{ 0, 1 };
	}

	if (inverse)
	{
		move_vector *= -1;
	}


	if (this->location + move_vector != this->location && 
		this->currentLevel->isValidMove(this->location + move_vector) && 
		!waitingForMove)
	{
		this->location += move_vector;
		currentLevel->updateTile(this->location);
		waitingForMove = true;
		waitTime = clock();
	}

} 

void Player::setPosition(sf::Vector2i location)
{
	this->location = location;
}