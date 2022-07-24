#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
//#include <Mouse.hpp>

class Menu;

class Button
{
private:
	sf::Sprite defaultState;
	sf::Sprite clickedState;
	sf::Sprite* currentSprite;
	sf::String string;

	int (*function)(Menu*);

public:
	Button(sf::Texture* defaultState, sf::Texture* clickedState, std::string string, sf::Vector2f location, int (*func)(Menu*));
	void draw(sf::RenderWindow& window);
	void setButtonAction(int (*func)(Menu*));
	void callButtonAction(Menu* menu);
	bool checkIfPressed(sf::Vector2i mousePos, Menu* menu);
	void setToDefaultSprite();
};

struct menuSet
{
	std::vector<Button> buttons;
	std::vector<sf::String> strings;
};

class Menu
{
private:
	bool paused = false;
	menuSet* currentMenu;

public:
	Menu();
	bool isPaused();
	void setPause(bool paused);
	void checkPressed(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};