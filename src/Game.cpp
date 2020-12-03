#include "Game.hpp"

#include <random>
#include <iostream>

#include "Keypad.hpp"

Game::Game(const GameParameters &settings)
    : gameparameters(settings)
{
}

Game::~Game()
{
}

void Game::play()
{
    init();

    while (window.isOpen())
    {
        handleevents();
        draw();
    }
}

void Game::init()
{
    srand(time(0));

    window.create(sf::VideoMode(400, 300), "Musical Battleship");

    pad = Keypad(gameparameters.startoctave, gameparameters.numoctaves, gameparameters.chromatic);
    pad.setPosition(50, 100);

    font.loadFromFile("./resources/NotoMono-Regular.ttf");
    notedisplay.setFont(font);
    notedisplay.setString("Hallo!");
    notedisplay.setPosition(50, 50);
}

void Game::draw()
{
    window.clear(sf::Color::Black);
    window.draw(pad);
    window.draw(notedisplay);
    window.display();
}

void Game::handleevents()
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
                    // The keypad is clicked
                    Note note = pad.catchclick(pos);
                    noteplayer.play(note);
                    notedisplay.setString(Note::noteIDToName(note.noteID));
                }
            }
        }
    }
}