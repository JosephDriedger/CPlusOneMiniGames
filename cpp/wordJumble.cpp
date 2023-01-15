#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcomePlayer(string jumble) {
    cout << "\tWelcome to Hockey Players Word Jumble!\n\n";

    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    cout << "The jumble is: " << jumble;
}

string jumbleWord(string word) {
    string newWord = word;
    int length = newWord.size();
    for (int i = 0; i < length; ++i) {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = newWord[index1];
        newWord[index1] = newWord[index2];
        newWord[index2] = temp;
    }

    return newWord;
}

int guessWord(string word, string hint) {
    string guess;
    do {
        cout << "\n\nYour guess: ";
        cin >> guess;

        if (guess == "quit") {
            return -1;
        }

        if (guess == "hint") {
            cout << hint;
            continue;
        }

        if (guess == word) {
            return 1;
        } else {
            cout << "Sorry, that's not it. Try again.";
        }

    } while ((guess != word));

    return 0;
}

void WordJumble() {
    int input;
    string game = "Word Jumble";

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"mcdavid", "Skates like the wind..."},
        {"gretzky", "Holds many NHL records..."},
        {"ovechkin", "Scores goals like its his breakfast..."},
        {"vasilevskiy", "Brick wall in net..."},
        {"pettersson", "Best IQ in the NHL currently..."}
    };

    do {
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand() % NUM_WORDS);
        string theWord = WORDS[choice][WORD];
        string theHint = WORDS[choice][HINT];

        string jumble = jumbleWord(theWord);

        welcomePlayer(jumble);

        if (guessWord(theWord, theHint) == -1) {
            cout << "\nYou quitter!! The word was " << theWord << ".\n";
        } else {
            cout << "\nThat's it. You guessed it!\n";
        }

        input = playAgain(game);
    } while (input != 2);
}
