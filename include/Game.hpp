#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"
#include "Keypad.hpp"

// Difficulty settings for the guessing game
class GameParameters
{
public:
    int startoctave;
    int numoctaves;
    bool chromatic;

    GameParameters(int startoctave = 2, int numoctaves = 3, bool chromatic = true)
        : startoctave(startoctave), numoctaves(numoctaves), chromatic(chromatic)
    {
    }
};

class Game
{
public:
    Game(const GameParameters &settings = GameParameters());
    ~Game();

    void play();

private:
    void init();
    void draw();
    void handleevents();

    // Resources
    sf::RenderWindow window;
    sf::View view;
    sf::Font font;
    GameParameters gameparameters;
    NotePlayer noteplayer;

    // Game objects
    Keypad pad;
    sf::Text notedisplay;
};
