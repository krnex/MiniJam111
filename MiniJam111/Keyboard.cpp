#include"Keyboard.h"

void Keyboard::update()
{

	for (sf::Keyboard::Key key : toCheck)
	{
		bool inStack = this->keyInStack(key);

		if (sf::Keyboard::isKeyPressed(key) && !inStack)
		{
			keyStack.push_back(key);
		} 
		else if (!sf::Keyboard::isKeyPressed(key) && inStack)
		{
			keyStack.erase(std::remove(keyStack.begin(), keyStack.end(), key), keyStack.end());
		}
	}

}

bool Keyboard::keyInStack(sf::Keyboard::Key checkKey)
{
	for (sf::Keyboard::Key key : keyStack)
	{
		if (key == checkKey)
		{
			return true;
		}
	}

	return false;
}

sf::Keyboard::Key Keyboard::getCurrentPressed()
{
	return this->keyStack.back();
}