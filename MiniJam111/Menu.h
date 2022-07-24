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
	sf::Text text;
	int value = 0;

	int (*function)(Menu*, int);

public:
	Button(sf::Texture* defaultState, sf::Texture* clickedState, std::string string, sf::Vector2f location, int (*func)(Menu*, int), int value, sf::Font* buttonFont);
	void draw(sf::RenderWindow& window);
	void setButtonAction(int (*func)(Menu*, int));
	void callButtonAction(Menu* menu);
	bool checkIfPressed(sf::Vector2i mousePos, Menu* menu);
	void setToDefaultSprite();
};

struct menuSet
{
	std::vector<Button> buttons;
	std::vector<sf::Text> strings;
	std::string name;
};

class Menu
{
private:
	bool open = true;
	menuSet* currentMenu;
	std::vector<menuSet*> allMenus;
	sf::Font* font;
	sf::Text* createText(std::string words, int size, sf::Color color, sf::Uint32 style, sf::Vector2f position);

	bool lastButtonPress = false;

public:
	Menu();
	bool isOpen();
	void setOpen(bool paused);
	void checkPressed(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void setWindow(std::string windowName);
	int nextLevel = -1;
	bool closeGame = false;
	bool backToMainMenu = false;
	bool gameOver = false;
	bool restartLevel = false;
};