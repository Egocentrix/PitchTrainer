#include "Game.hpp"

#include <random>
#include <iostream>

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

    Keypad pad(2, 4, true);
    pad.setPosition(50, 100);

    sf::Text notedisplay;
    sf::Font font;
    font.loadFromFile("./resources/NotoMono-Regular.ttf");
    notedisplay.setFont(font);

    notedisplay.setString("Hallo!");
    notedisplay.setPosition(50,50);

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
                    sf::Vector2i pos(sf::Mouse::getPosition(window));
                    if (pad.getBounds().contains(sf::Vector2f(pos)))
                    {
                        Note note = pad.catchclick(pos);
                        noteplayer.play(note);
                        notedisplay.setString(Note::noteIDToName(note.noteID));
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(pad);
        window.draw(notedisplay);
        window.display();
    }
}