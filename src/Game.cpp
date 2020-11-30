#include "Game.hpp"

#include <random>

#include "Keypad.hpp"

Game::Game()
{
    srand(time(0));
}

Game::~Game()
{
}

void Game::play()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "Musical Battleship");
    sf::View view;

    Keypad pad(2, 3, false);
    pad.setPosition(100, 100);

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (e.type == sf::Event::Resized)
            {
                view.setSize(e.size.width, e.size.height);
                view.setCenter(e.size.width / 2, e.size.height / 2);
                window.setView(view);
            }
            else if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(pad);
        window.display();
    }
}