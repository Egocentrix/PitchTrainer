#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"

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
    Game();
    Game(const GameParameters &settings);
    ~Game();

    void play();

private:
    void init();

    GameParameters gameparameters;
    NotePlayer noteplayer;
};
