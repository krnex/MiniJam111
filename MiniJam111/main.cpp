#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector.h"
#include "Map.h"
#include "Player.h"
#include "LevelManager.h"
#include "Keyboard.h"

// TODO:
// Player Spawn done with level load
// Art
// Menu


int main()
{
    static int WINDOW_WIDTH = 800;
    static int WINDOW_HEIGHT = 800;

    Map test(WINDOW_WIDTH, WINDOW_HEIGHT);
    Player test_player(sf::Vector2i{ 0,0 }, &test);
    Player test_player2(sf::Vector2i{ 9,9 }, &test);
    std::vector<Player*> test_players;
    test_players.push_back(&test_player);
    test_players.push_back(&test_player2);
    LevelManager lm;

    lm.loadLevel(1, &test);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bingo Bongo you're a pongo");

    while (window.isOpen())
    {
        Keyboard::GetInstance().update();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (test.checkWinCondition())
        {
            std::cout << "WE HAVE A WINNER" << std::endl;
            lm.loadLevel(0, &test, &test_players);
        }

        window.clear();
        test.draw(window);
        for (Player* p : test_players)
        {
            p->update();
            p->draw(window);
        }
        window.display();
    }

    return 0;
}
