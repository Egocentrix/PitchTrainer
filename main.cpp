#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

class NotePlayer
{
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    static unsigned int const SAMPLERATE{44100};

    NotePlayer() = default;
    ~NotePlayer() = default;

    void play(float frequencyHz, float durationS = 1, bool blocking = false)
    {

        std::vector<sf::Int16> wave;
        unsigned int samplecount = durationS * SAMPLERATE;
        wave.resize(samplecount);

        for (size_t i = 0; i < samplecount; i++)
        {
            wave[i] = INT16_MAX * sin(2 * M_PI * frequencyHz * i / SAMPLERATE);
        }
        
        buffer.loadFromSamples(wave.data(), samplecount, 1, SAMPLERATE);
        sound.setBuffer(buffer);
        sound.play();

        if (blocking)
        {
            sf::sleep(sf::seconds(durationS));
        }
        
    }
};

int main(int, char **)
{
    std::cout << "Hello, world!\n";

    NotePlayer np, np2;
    np.play(440, 1, false);
    np2.play(550, 1, true);
}
