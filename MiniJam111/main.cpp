#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector.h"
#include "Map.h"
#include "Player.h"
#include "LevelManager.h"
#include "Keyboard.h"
#include "Menu.h"
#include "Menu.h"

// TODO:
// Menu
// Art
// Sound


int main()
{
    static int WINDOW_WIDTH = 800;
    static int WINDOW_HEIGHT = 800;

    // Initilizing.
    Map gameMaps(WINDOW_HEIGHT, WINDOW_HEIGHT);
    std::vector<Player*> setOfPlayers;
    LevelManager lm;
    Menu menu;

    lm.loadLevel(0, &gameMaps, &setOfPlayers);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bingo Bongo you're a pongo");

    while (window.isOpen())
    {
        Keyboard::GetInstance().update();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            menu.setPause(true);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (gameMaps.checkWinCondition())
        {
            std::cout << "WE HAVE A WINNER" << std::endl;
            lm.loadLevel(1, &gameMaps, &setOfPlayers);
        }

        window.clear();

        if (menu.isPaused())
        {
            menu.checkPressed(window);
            menu.draw(window);
        }
        else
        {
            gameMaps.draw(window);
            for (Player* player : setOfPlayers)
            {
                player->update();
                player->draw(window);
            }
        }
        window.display();
    }

    return 0;
}
