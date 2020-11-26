#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <map>

class Note
{
public:
    // Notes start from 0 (C0), eacht semitone is a step up.
    int noteID = {0};

    Note() = default;

    Note(const std::string &name)
    {
        noteID = nameToNoteID(name);
    }

    static std::string noteIDToName(int noteID)
    {
        std::string name = "";

        int octave = noteID / 12;
        int note = noteID % 12;

        char notename;
        bool sharp;
        do
        {
            switch (note)
            {
            case 0:
                notename = 'C';
                note -= 0;
                break;
            case 2:
                notename = 'D';
                note -= 2;
                break;
            case 4:
                notename = 'E';
                note -= 4;
                break;
            case 5:
                notename = 'F';
                note -= 5;
                break;
            case 7:
                notename = 'G';
                note -= 7;
                break;
            case 9:
                notename = 'A';
                note -= 9;
                break;
            case 11:
                notename = 'B';
                note -= 11;
                break;
            default:
                note -= 1;
                sharp = true;
            }
        } while (note != 0);

        name += notename;
        if (sharp)
        {
            name += '#';
        }
        name += ('0' + octave);        

        return name;
    }

    static int nameToNoteID(const std::string &name)
    {
        int note = 0;

        for (char c : name)
        {
            if (c >= 'A' && c <= 'H') // Note name
            {
                switch (c)
                {
                case 'C':
                    note += 0;
                    break;
                case 'D':
                    note += 2;
                    break;
                case 'E':
                    note += 4;
                    break;
                case 'F':
                    note += 5;
                    break;
                case 'G':
                    note += 7;
                    break;
                case 'H':
                    std::cout << "Nice try, I'm not a German" << std::endl;
                    break;
                case 'A':
                    note += 9;
                    break;
                case 'B':
                    note += 11;
                    break;
                }
            }
            else if (c == '#') // Modifier
            {
                note += 1;
            }
            else if (c == 'b')
            {
                note -= 1;
            }
            else if (c >= '0' && c <= '9') // Octave
            {
                note += 12 * (c - '0');
            }
            else
            {
                std::cout << "Error parsing note" << std::endl;
                return 0;
            }
        }

        return note;
    }

    float getFrequency()
    {
        return 440.f * pow(2, (noteID - 57) / 12.0); // A4 is 4*12 + 9 semitones above C0;
    }
};

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
    std::string testname = "a#7";

    NotePlayer np;
    Note N("H4");
    np.play(N.getFrequency(), 1, true);

    std::cout << Note::noteIDToName(N.noteID) << std::endl;
}
