#include "Game.hpp"

#include <random>

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

    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100,100);
    
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
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}