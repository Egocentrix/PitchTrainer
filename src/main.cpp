#include <iostream>

#include "Note.hpp"

int main(int, char **)
{
    NotePlayer np;
    Note N("Bb4");
    np.play(N.getFrequency(), 1, true);
    np.play(Note("F4").getFrequency(),1,true);
    std::cout << Note::noteIDToName(N.noteID) << std::endl;
}
