#include"Menu.h"

int test_function()
{
    std::cout << "TEST ASJKDJLAKSD" << std::endl;
    return 0;
}

int unpause(Menu* menu)
{
    menu->setPause(false);

    return 0;
}

Menu::Menu()
{
    sf::Image buttonImage;
    buttonImage.loadFromFile("./button_1.png");
    sf::Texture* buttonNotClicked = new sf::Texture;
    buttonNotClicked->loadFromImage(buttonImage);

    buttonImage.loadFromFile("./button_2.png");
    sf::Texture* buttonClicked = new sf::Texture;
    buttonClicked->loadFromImage(buttonImage);

    // Main Menu
    menuSet* mainMenu = new menuSet;

    mainMenu->buttons.push_back(*(new Button(buttonClicked,
                                             buttonNotClicked,
                                             "test",
                                             sf::Vector2f{ 100,100 },
                                             & unpause)));

    mainMenu->buttons.push_back(*(new Button(buttonNotClicked,
                                             buttonClicked,
                                              "secondTest",
                                              sf::Vector2f{ 200,200 },
                                              & unpause)));
    
    this->currentMenu = mainMenu;
}

bool Menu::isPaused()
{
	return this->paused;
}

void Menu::setPause(bool paused)
{
	this->paused = paused;
}

void Menu::checkPressed(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (Button button : this->currentMenu->buttons)
    {
        //button.setToDefaultSprite();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            button.checkIfPressed(mousePos, this);
        }
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    for (Button button : this->currentMenu->buttons)
    {
        button.draw(window);
    }
}


Button::Button(sf::Texture* normal, sf::Texture* clicked, std::string words, sf::Vector2f location, int (*func)(Menu*))
{
    this->defaultState.setTexture(*normal);
    this->clickedState.setTexture(*clicked);
    this->currentSprite = &this->defaultState;
    this->defaultState.setPosition(location);
    this->clickedState.setPosition(location);
    this->setButtonAction(func);
    this->string = words;
    //string.setPosition(location.x + 3, location.y + 3);
    //string.setSize(14);
}


void Button::setButtonAction(int(*func)(Menu*))
{
	this->function = func;
}

void Button::callButtonAction(Menu* menu)
{
    this->currentSprite = &this->clickedState;
	this->function(menu);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(*this->currentSprite);
}

bool Button::checkIfPressed(sf::Vector2i mousePos, Menu* menu)
{
    bool pressed = false;
    sf::Vector2u size = currentSprite->getTexture()->getSize();
    if (mousePos.x > currentSprite->getPosition().x && mousePos.x < (currentSprite->getPosition().x + size.x)) {
        if (mousePos.y > currentSprite->getPosition().y && mousePos.y < (currentSprite->getPosition().y + size.y)) {
            pressed = true;
            this->callButtonAction(menu);
        }
    }

    return pressed;
}

void Button::setToDefaultSprite()
{
    this->currentSprite = &this->defaultState;
}