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
    int buttonsize = 20;
    int buttonpadding = 5;

    Keypad() = default;
    Keypad(int startoctave, int numoctaves, bool chromatic);
    ~Keypad();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    // Get bounding box in world coordinates
    sf::FloatRect getBounds() const;

    // Get the note that corresponds to the key that was clicked on.
    // Checking bounds is the responsibility of the caller.
    Note catchclick(sf::Vector2i mousepos) const;
};
