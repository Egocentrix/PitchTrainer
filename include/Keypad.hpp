#pragma once

#include <SFML/Graphics.hpp>

#include "Note.hpp"

// Keypad for playing/selecting notes
class Keypad : public sf::Drawable, public sf::Transformable
{
private:
    int startoctave{2};
    int numoctaves{2};
    bool chromatic{false};

public:
    int buttonsize{20};
    int buttonpadding{5};

    Keypad() = default;
    Keypad(int startoctave, int numoctaves, bool chromatic);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    // Get bounding box in world coordinates
    sf::FloatRect getBounds() const;

    // Get the note that corresponds to the key that was clicked on.
    // Checking bounds is the responsibility of the caller.
    Note catchclick(sf::Vector2i mousepos) const;
};
