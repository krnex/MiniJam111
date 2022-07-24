#include"Menu.h"

int closeMenu(Menu* menu, int value)
{
    menu->setOpen(false);

    return 0;
}

int setLevel(Menu* menu, int value)
{
    menu->nextLevel = value;

    return 0;
}

int changeMenu(Menu* menu, int value)
{
    menu->backToMainMenu = true;
    menu->nextLevel = -1;
    menu->setWindow("MainMenu");

    return 0;
}

int exit(Menu* menu, int value)
{
    menu->closeGame = true;

    return 0;
}

int resartLevel(Menu* menu, int value)
{
    menu->restartLevel = true;

    return 0;
}

Menu::Menu()
{
    sf::Image buttonImage;
    buttonImage.loadFromFile("./images/button.png");
    sf::Texture* buttonNotClicked = new sf::Texture;
    buttonNotClicked->loadFromImage(buttonImage);

    buttonImage.loadFromFile("./images/button.png");
    sf::Texture* buttonClicked = new sf::Texture;
    buttonClicked->loadFromImage(buttonImage);

    this->font = new sf::Font;
    sf::Font newFont;
    if (!newFont.loadFromFile("./font/TropicalPartyDemoRegular.ttf"))
    {
        std::cout << "Font cant be loaded." << std::endl;
    }
    *this->font = newFont;

    /*
    /////////////////////////////////////////////////////////////////
    //////////			Main Menu        				/////////////
    /////////////////////////////////////////////////////////////////
    */
    menuSet* mainMenu = new menuSet;
    mainMenu->name = "MainMenu";

    mainMenu->buttons.push_back(*(new Button(buttonClicked,
                                            buttonNotClicked,
                                            "Start Game",
                                            sf::Vector2f{ 300,300 },
                                            &setLevel,
                                            0,
                                            this->font)));

    mainMenu->buttons.push_back(*(new Button(buttonClicked,
                                            buttonNotClicked,
                                            "Exit Game",
                                            sf::Vector2f{ 300,400 },
                                            &exit,
                                            0,
                                            this->font)));


    mainMenu->strings.push_back(*this->createText("Bing Bong", 100, sf::Color::Cyan, sf::Text::Underlined, sf::Vector2f{ 400,200 }));

    allMenus.push_back(mainMenu);

    /*
    /////////////////////////////////////////////////////////////////
    //////////			Pause Menu       				/////////////
    /////////////////////////////////////////////////////////////////
    */
    menuSet* pauseMenu = new menuSet;
    pauseMenu->name = "PauseMenu";

    pauseMenu->buttons.push_back(*(new Button(buttonClicked,
                                             buttonNotClicked,
                                             "Resume",
                                             sf::Vector2f{ 300,300 },
                                             & closeMenu,
                                             0,
                                             this->font)));

    pauseMenu->buttons.push_back(*(new Button(buttonNotClicked,
                                             buttonClicked,
                                             "Restart",
                                             sf::Vector2f{ 300,400 },
                                             &resartLevel,
                                             0,
                                             this->font)));

    pauseMenu->buttons.push_back(*(new Button(buttonNotClicked,
                                             buttonClicked,
                                              "Main menu",
                                              sf::Vector2f{ 300,500 },
                                              & changeMenu,
                                              0,
                                              this->font)));

    pauseMenu->strings.push_back(*this->createText("Paused", 50, sf::Color::Cyan, sf::Text::Underlined, sf::Vector2f{ 400,200 }));

    allMenus.push_back(pauseMenu);

    /*
    /////////////////////////////////////////////////////////////////
    //////////			End Screen      				/////////////
    /////////////////////////////////////////////////////////////////
    */

    menuSet* endScreen = new menuSet;
    endScreen->name = "EndScreen";

    endScreen->buttons.push_back(*(new Button(buttonNotClicked,
        buttonClicked,
        "Exit",
        sf::Vector2f{ 300,300 },
        &exit,
        0,
        this->font)));

    endScreen->strings.push_back(*this->createText("Thanks for playing", 35, sf::Color::Cyan, sf::Text::Underlined, sf::Vector2f{ 400,200 }));

    allMenus.push_back(endScreen);


    this->currentMenu = mainMenu;


}

sf::Text* Menu::createText(std::string words, int size, sf::Color color, sf::Uint32 style, sf::Vector2f position)
{
    sf::Text* text = new sf::Text;
    text->setFont(*this->font);
    text->setString(words);
    text->setCharacterSize(size);
    text->setFillColor(color);
    text->setStyle(style);
    text->setOutlineColor(sf::Color::Black);
    text->setOutlineThickness(0.5);
    text->setPosition(position - sf::Vector2f(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2));

    return text;
}

bool Menu::isOpen()
{
	return this->open;
}

void Menu::setOpen(bool open)
{
	this->open = open;
}

void Menu::checkPressed(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    bool didButtonGetPressed = false;
    for (Button button : this->currentMenu->buttons)
    {
        //button.setToDefaultSprite();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            didButtonGetPressed = true;
            if(this->lastButtonPress == false)
                button.checkIfPressed(mousePos, this);
        } 
    }

    if (didButtonGetPressed)
    {
        this->lastButtonPress = true;
    } else
    {
        this->lastButtonPress = false;
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    for (sf::Text text : this->currentMenu->strings)
    {
        window.draw(text);
    }

    for (Button button : this->currentMenu->buttons)
    {
        button.draw(window);
    }
}

void Menu::setWindow(std::string windowName)
{
    for (menuSet* menu : allMenus)
    {
        if (menu->name == windowName)
        {
            this->currentMenu = menu;
            break;
        }
    }
}



Button::Button(sf::Texture* normal, sf::Texture* clicked, std::string words, sf::Vector2f location, int (*func)(Menu*, int), int value, sf::Font* buttonFont)
{
    this->defaultState.setTexture(*normal);
    this->clickedState.setTexture(*clicked);
    this->currentSprite = &this->defaultState;
    this->defaultState.setPosition(location);
    this->clickedState.setPosition(location);

    this->setButtonAction(func);

    this->value = value;

    this->text.setFont(*buttonFont);
    this->text.setString(words);
    this->text.setCharacterSize(24);
    this->text.setFillColor(sf::Color::Cyan);
    this->text.setOutlineColor(sf::Color::Black);
    this->text.setOutlineThickness(0.5);
    sf::Vector2f size{ currentSprite->getTexture()->getSize() };
    this->text.setPosition(location + sf::Vector2f{size.x /2, size.y/2} - sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
}


void Button::setButtonAction(int(*func)(Menu*, int))
{
	this->function = func;
}

void Button::callButtonAction(Menu* menu)
{
    this->currentSprite = &this->clickedState;
	this->function(menu, this->value);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(*this->currentSprite);
    window.draw(this->text);
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