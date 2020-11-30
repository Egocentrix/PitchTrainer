#pragma once

#include <map>
#include <cmath>
#include <vector>

#include <SFML/Audio.hpp>

class Note
{
public:
    // Notes start from 0 (C0), each semitone is a step up.
    int noteID = {0};

    Note() = default;

    Note(const int noteID)
    {
        this->noteID = noteID;
    }

    Note(const std::string &name)
    {
        noteID = nameToNoteID(name);
    }

    float getFrequency()
    {
        return 440.f * pow(2, (noteID - 57) / 12.0); // A4 is 4*12 + 9 semitones above C0;
    }

    static std::string noteIDToName(int noteID);
    static int nameToNoteID(const std::string &name);
    static int chromaticNoteID(int diatonicNoteID);

    static Note random(int minoctave, int maxoctave, bool chromatic = true);

private:
    static const std::map<std::string, int> notenameToIDMap;
    static const std::vector<std::string> noteIDToNameMap;
    static const std::vector<int> diatonicNoteID;
};

class NotePlayer
{
public:
    static const unsigned int SAMPLERATE = {44100};

    NotePlayer() = default;
    ~NotePlayer() = default;

    void play(float frequencyHz, float durationS = 1, bool blocking = false);

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};