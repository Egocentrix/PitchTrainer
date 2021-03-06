#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"
#include "Keypad.hpp"

// Difficulty settings for the guessing game
class GameParameters
{
public:
    int startoctave{2};
    int numoctaves{3};
    bool chromatic{true};

    GameParameters() = default;

    GameParameters(int startoctave, int numoctaves, bool chromatic)
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

    Note currentnote;

    // Resources
    sf::RenderWindow window;
    sf::View view;
    sf::Font font;
    GameParameters gameparameters;
    NotePlayer noteplayer;

    // Game objects
    Keypad pad;
    sf::Text notedisplay;
    sf::RectangleShape referencebutton;
    sf::RectangleShape againbutton;

    std::vector<sf::Drawable *> drawlist;
};
