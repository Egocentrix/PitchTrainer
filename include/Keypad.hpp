#pragma once

#include <SFML/Graphics.hpp>

class Keypad : public sf::Drawable, public sf::Transformable
{
private:
    int startoctave;
    int numoctaves;
    bool chromatic;

public:
    Keypad(int startoctave, int numoctaves, bool chromatic);
    ~Keypad();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
