#pragma once

#include <map>
#include <cmath>
#include <vector>

#include <SFML/Audio.hpp>

// Represents a single note (pitch)
class Note
{
public:
    // Notes start from 0 (C0), each semitone is a step up.
    int noteID{0};

    Note() = default;
    Note(const int noteID) : noteID{noteID} {}
    Note(const std::string &name) : noteID{nameToNoteID(name)} {}

    float getFrequency() const
    {
        return 440.f * pow(2, (noteID - 57) / 12.0); // A4 is 4*12 + 9 semitones above C0;
    }

    // Conversion functions
    static std::string noteIDToName(int noteID);
    static int nameToNoteID(const std::string &name);
    static int chromaticNoteID(int diatonicNoteID);

    // Get a random note in the interval [ C_minoctave, C_maxoctave )
    static Note random(int minoctave, int maxoctave, bool chromatic = true);

private:
    static const std::map<std::string, int> notenameToIDMap;
    static const std::vector<std::string> noteIDToNameMap;
    static const std::vector<int> diatonicNoteID;
};

bool operator==(const Note& lhs, const Note& rhs);
bool operator!=(const Note& lhs, const Note& rhs);

// Class for playing sine waves of a given frequency
class NotePlayer
{
public:
    static const unsigned int SAMPLERATE{44100};

    void play(float frequencyHz, float durationS = 1, bool blocking = false);
    void play(const Note &note, float durationS = 1, bool blocking = false);

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};