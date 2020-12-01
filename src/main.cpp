#include <iostream>

#include "Note.hpp"
#include "Game.hpp"

int main(int, char **)
{
    Game game;
    game.play();

    std::cout << "You will hear a tone. Use a tuning fork to determine what \n"
              << "note you just heard and type the answer in the form \'Ab5\'.\n"
              << "Use capital letters and don' t forget to include an \n"
              << "octave number. Use \'#\' and \'b\' for sharps and flats.\n"
              << std::endl;

    NotePlayer np;
    std::string answer;
    bool exit = false;
    srand(time(0));

    while (!exit)
    {
        Note note = Note::random(3, 5, true);
        np.play(note, 1, false);

        std::cout << "\nWhat note was this? \n(l)isten again / (e)xit / give (a)nswer / \n";

        bool next = false;
        while (!next)
        {
            std::cout << "Your answer: ";
            std::cin >> answer;

            if (answer == "e")
            {
                exit = true;
                break;
            }
            else if (answer == "l")
            {
                np.play(note, 1, false);
            }
            else if (answer == "a")
            {
                std::cout << "The correct answer was " << Note::noteIDToName(note.noteID) << "." << std::endl;
                next = true;
            }
            else if (Note::nameToNoteID(answer) == note.noteID)
            {
                std::cout << "Correct!" << std::endl;
                next = true;
            }
            else
            {
                std::cout << "Sorry, wrong answer" << std::endl;
            }
        }
    }
}
