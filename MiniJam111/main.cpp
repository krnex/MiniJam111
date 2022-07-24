#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Vector.h"
#include "Map.h"
#include "Player.h"
#include "LevelManager.h"
#include "Keyboard.h"
#include "Menu.h"
#include "Menu.h"

// TODO:
// Main Menu
// Art
// Sound

sf::Color getBlueGreenGradient(int* seed)
{
    (*seed) = (*seed) + (clock()%10==0);
    int g = *seed % 512;
    int b = (*seed * 2) % 512;

    if (g > 255)
    {
        g = 255 - (g % 256);
    }
    if (b > 255)
    {
        b = 255 - (b % 256);
    }

    std::cout << g << " " << b << std::endl;

    return sf::Color{ 0,sf::Uint8(g),sf::Uint8(b) };
}



int main()
{
    static int WINDOW_WIDTH = 800;
    static int WINDOW_HEIGHT = 800;

    // Initilizing.
    Map gameMaps(WINDOW_HEIGHT, WINDOW_HEIGHT);
    std::vector<Player*> setOfPlayers;
    LevelManager lm;
    Menu menu;

    //lm.loadLevel(0, &gameMaps, &setOfPlayers);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bing Bong");

    int gradientSeed = 0;
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./images/background.png");
    sf::Sprite background(backgroundTexture);

    while (window.isOpen())
    {

        Keyboard::GetInstance().update();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (menu.closeGame)
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            menu.setWindow("PauseMenu");
            menu.setOpen(true);
        }

        window.clear(getBlueGreenGradient(&gradientSeed));
        window.draw(background);

        if (menu.isOpen())
        {
            menu.checkPressed(window);
            menu.draw(window);

            if (menu.restartLevel)
            {
                menu.restartLevel = false;
                lm.loadLevel(menu.nextLevel, &gameMaps, &setOfPlayers);
                menu.setOpen(false);
            }

            if (menu.nextLevel != lm.currentLevel && menu.gameOver == false)
            {
                if (menu.backToMainMenu == false)
                {
                    std::cout << "Load Level" << std::endl;
                    lm.loadLevel(menu.nextLevel, &gameMaps, &setOfPlayers);
                    menu.setOpen(false);
                }
                else
                {
                    menu.backToMainMenu = false;
                    lm.currentLevel = -1;
                }
            }
        }
        else
        {
            gameMaps.draw(window);
            for (Player* player : setOfPlayers)
            {
                player->update();
                player->draw(window);
            }
            if (gameMaps.checkWinCondition())
            {
                std::cout << "WE HAVE A WINNER" << std::endl;
                if (lm.currentLevel + 1 < lm.totalLevels)
                {
                    lm.loadLevel(++lm.currentLevel, &gameMaps, &setOfPlayers);
                    menu.nextLevel = lm.currentLevel;
                }
                else
                {
                    menu.setWindow("EndScreen");
                    menu.setOpen(true);
                    menu.gameOver = true;
                }
            }
        }
        window.display();
    }

    return 0;
}