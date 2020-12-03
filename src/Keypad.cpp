#include "Keypad.hpp"

Keypad::Keypad(int startoctave, int numoctaves, bool chromatic)
    : startoctave(startoctave), numoctaves(numoctaves), chromatic(chromatic)
{
}

Keypad::~Keypad()
{
}

void Keypad::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    sf::RectangleShape square(sf::Vector2f(20, 20));
    square.setFillColor(sf::Color::Green);
    for (int octave = 0; octave < numoctaves; octave++)
    {
        for (int note = 0; note < (chromatic ? 12 : 7); note++)
        {
            square.setPosition((buttonsize + buttonpadding) * note + buttonpadding, (buttonsize + buttonpadding) * octave + buttonpadding);
            target.draw(square, states);
        }
    }
}

sf::FloatRect Keypad::getBounds() const
{
    float width = (chromatic ? 12 : 7) * (buttonsize + buttonpadding);
    float height = numoctaves * (buttonsize + buttonpadding);

    return sf::FloatRect(getPosition(), sf::Vector2f(width, height));
}

Note Keypad::catchclick(sf::Vector2i mousepos) const
{
    mousepos.x -= getPosition().x + buttonpadding;
    mousepos.y -= getPosition().y + buttonpadding;

    int octave = mousepos.y / (buttonsize + buttonpadding) + startoctave;
    int note = mousepos.x / (buttonsize + buttonpadding);

    if (!chromatic)
    {
        note = Note::chromaticNoteID(note);
    }

    return Note(12 * octave + note);
}