#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"

// Keypad for playing/selecting notes
class Keypad : public sf::Drawable, public sf::Transformable
{
private:
    int startoctave;
    int numoctaves;
    bool chromatic;

public:
    int buttonsize;
    int buttonpadding;

    Keypad(int startoctave, int numoctaves, bool chromatic);
    ~Keypad();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::FloatRect getBounds() const;

    Note catchclick(sf::Vector2i mousepos) const;
};
