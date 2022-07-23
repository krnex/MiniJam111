#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

class Keyboard
{
private:
	std::vector<sf::Keyboard::Key> keyStack{sf::Keyboard::Unknown};
	std::vector<sf::Keyboard::Key> toCheck{ sf::Keyboard::W,
											sf::Keyboard::A,	
											sf::Keyboard::S,
											sf::Keyboard::D,
											sf::Keyboard::P};
	bool keyInStack(sf::Keyboard::Key checkKey);
 public:
	 static Keyboard& GetInstance() {
		 static Keyboard* keyboard = new Keyboard();
		 return *keyboard;
	 }

	 sf::Keyboard::Key getCurrentPressed();
	 void update();
};