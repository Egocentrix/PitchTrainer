#include "Keypad.hpp"

Keypad::Keypad(int startoctave, int numoctaves, bool chromatic)
    : numoctaves(numoctaves), startoctave(startoctave), chromatic(chromatic)
{
}

Keypad::~Keypad()
{
}

void Keypad::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    sf::RectangleShape square(sf::Vector2f(20, 20));
    square.setFillColor(sf::Color::Green);
    for (int octave = 0; octave < numoctaves; octave++)
    {
        for (int note = 0; note < (chromatic ? 12 : 7); note++)
        {
            square.setPosition(5 + 25 * note, 5 + 25 * octave);
            target.draw(square, states);
        }
    }
}