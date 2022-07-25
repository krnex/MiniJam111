#include"Player.h"

Player::Player(sf::Vector2i location, Map* current, bool inverse)
{	
	this->currentLevel = current;
	this->location = location;
	this->inverse = inverse;
	this->waitTime = clock();

	if (inverse)
	{
		this->color = sf::Color::White;
		this->outline = sf::Color::Black;
		this->buffer.loadFromFile("./audio/move.wav");
	}
	else
	{
		this->color = sf::Color::Black;
		this->outline = sf::Color::White;
		this->buffer.loadFromFile("./audio/move.wav");
	}

	this->soundPlayer.setVolume(50);
}

sf::Vector2i Player::getCurrentTile()
{
	return this->location;
}

void Player::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(30+this->enlarge);
	circle.setFillColor(this->color);
	circle.setOutlineColor(this->outline);
	circle.setOutlineThickness(1);
	circle.setPosition(currentLevel->getLocationFromTile(this->getCurrentTile()) + sf::Vector2f{5-(this->enlarge/2),5 - (this->enlarge / 2) });

	window.draw(circle);
}

void Player::update()
{

	if (this->enlarge > 0)
	{
		this->enlarge -= this->shrinkRate;
	}

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
		this->soundPlayer.setBuffer(this->buffer);
		this->soundPlayer.play();

		this->enlarge = this->enlargeMax;

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