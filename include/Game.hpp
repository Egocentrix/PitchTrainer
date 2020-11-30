#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"

class Game
{
public:
    Game(/* args */);
    ~Game();

    void play();

private:
    NotePlayer noteplayer;
};
