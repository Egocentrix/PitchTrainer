#include "Note.hpp"

#include <iostream>
#include <random>

std::string Note::noteIDToName(int noteID)
{
    std::string name = "";

    name += noteIDToNameMap[noteID % 12];
    name += noteID / 12 + '0';

    return name;
}

int Note::nameToNoteID(const std::string &name)
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

int Note::chromaticNoteID(int noteID)
{
    return diatonicNoteID.at(noteID);
}

Note Note::random(int minoctave, int maxoctave, bool chromatic)
{
    int octave = std::rand() % (maxoctave - minoctave) + minoctave;
    int note = 0;

    if (chromatic)
    {
        note = std::rand() % 12;
    }
    else
    {
        note = std::rand() % 7;
        std::vector<int> diatonic = {0, 2, 4, 5, 7, 9, 11};
        note = diatonic[note];
    }
    return Note(12 * octave + note);
}

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

const std::vector<int> Note::diatonicNoteID = {0, 2, 4, 5, 7, 9, 11};

bool operator==(const Note& lhs, const Note& rhs)
{
    return lhs.noteID == rhs.noteID;
}

bool operator!=(const Note& lhs, const Note& rhs)
{
    return !(lhs == rhs);
}

void NotePlayer::play(float frequencyHz, float durationS, bool blocking)
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

void NotePlayer::play(const Note &note, float durationS, bool blocking)
{
    play(note.getFrequency(), durationS, blocking);
}