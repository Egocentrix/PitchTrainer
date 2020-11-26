#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <map>

class Note
{
public:
    // Notes start from 0 (C0), each semitone is a step up.
    int noteID = {0};

    Note() = default;

    Note(const std::string &name)
    {
        noteID = nameToNoteID(name);
    }

    static const std::map<std::string, int> notenameToIDMap;

    static const std::vector<std::string> noteIDToNameMap;

    static std::string noteIDToName(int noteID)
    {
        std::string name = "";

        name += noteIDToNameMap[noteID % 12];
        name += noteID / 12 + '0';

        return name;
    }

    static int nameToNoteID(const std::string &name)
    {
        int note = 0;
        note = notenameToIDMap.at(name.substr(0, 1)); // First character

        for (char c : name.substr(1)) // Rest of string
        {
            if (c >= '0' && c <= '9')
            {
                note += 12 * (c - '0');
            }
            else if (c == '#')
            {
                note++;
            }
            else if (c == 'b')
            {
                note--;
            }
            else
            {
                std::cout << "Unexpected character" << std::endl;
            }
        }

        return note;
    }

    float getFrequency()
    {
        return 440.f * pow(2, (noteID - 57) / 12.0); // A4 is 4*12 + 9 semitones above C0;
    }
};

const std::map<std::string, int> Note::notenameToIDMap = {
    {"C", 0},
    {"D", 2},
    {"E", 4},
    {"F", 5},
    {"G", 7},
    {"A", 9},
    {"B", 11}};

const std::vector<std::string> Note::noteIDToNameMap = {
    "C",
    "C#",
    "D",
    "D#",
    "E",
    "F",
    "F#",
    "G",
    "G#",
    "A",
    "A#",
    "B",
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
    Note N("Bb4");
    np.play(N.getFrequency(), 1, true);

    std::cout << Note::noteIDToName(N.noteID) << std::endl;
}
