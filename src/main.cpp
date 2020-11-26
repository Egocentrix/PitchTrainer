#include <iostream>

#include "Note.hpp"

int main(int, char **)
{
    NotePlayer np;
    Note N("Bb4");
    np.play(N.getFrequency(), 1, true);
    np.play(Note("F4").getFrequency(), 1, true);
    std::cout << Note::noteIDToName(N.noteID) << std::endl;

    std::srand(std::time(0));
    for (size_t i = 0; i < 20; i++)
    {
        Note rn = Note::random(2, 7, true);

        std::cout << Note::noteIDToName(rn.noteID) << std::endl;
        np.play(rn.getFrequency(), 0.2, true);
    }
}
