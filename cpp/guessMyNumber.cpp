#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../h/cPlusOneMiniGames.h"

using namespace std;

int guessNumber(int num, int guess) {
    if (guess > num) {
        return 1;
    } else if (guess < num) {
        return -1;
    } else {
        return 0;
    }
}

int playerGuess() {
    srand(static_cast<unsigned int>(time(0)));

    // Get a Number between 1 and 100
    int num = (rand() % 100) + 1;

    int guess;
    int numOfGuesses = 0;
    bool success;

    do {
        cout << "Enter a guess: ";
        cin >> guess;

        int feedback = guessNumber(num, guess);

        if (feedback == 1) {
            cout << "Too high!\n\n";
            success = false;
        } else if (feedback == -1) {
            cout << "Too low!\n\n";
            success = false;
        } else {
            success = true;
        }

        numOfGuesses++;
    } while (!success);

    cout << "\nThat's it! You got it in " << numOfGuesses << " guesses!\n";

    return numOfGuesses;
}

int cpuGuess() {
    srand(static_cast<unsigned int>(time(0)));

    int num;

    do {
        cout << "\nEnter your number from 1 to 100: ";
        cin >> num;

        if (num > 100 || num < 0) {
            cout << "Invalid Number. ";
        }
    } while (num > 100 || num < 0);

    int guess;
    int lowRange = 1;
    int highRange = 100;
    int numOfGuesses = 0;

    do {
        int range = highRange - lowRange + 1;
        guess = (rand() % range) + lowRange;

        int feedback = guessNumber(num, guess);

        if (feedback > 0) {
            highRange = guess - 1;
        } else if (feedback < 0) {
            lowRange = guess + 1;
        }

        cout << guess << endl;

        ++numOfGuesses;
    } while (num != guess);

    cout << "\nIt took the CPU " << numOfGuesses << " guesses to guess your number.\n";

    return numOfGuesses;
}

void GuessMyNumber() {
    int input;
    string curGame = "Guess My Number";

    cout << "\tWelcome to Guess My Number\n\n";

    do {
        int playerGuesses;
        int cpuGuesses;

        bool yesNoValid;
        do {
            cout << "Do you want to go first?";
            cout << "\n1 - Yes";
            cout << "\n2 - No";
            cout << "\nYour response: ";
            cin >> input;

            yesNoValid = input < 1 || input > 2;

            if (yesNoValid) {
                cout << "Not a valid response.\n";
            }
        } while (yesNoValid);

        if (input == 1) {
            playerGuesses = playerGuess();
            cpuGuesses = cpuGuess();
        } else {
            cpuGuesses = cpuGuess();
            playerGuesses = playerGuess();
        }

        if (playerGuesses < cpuGuesses) {
            int difference = cpuGuesses - playerGuesses;
            cout << "Dang. You won by " << difference << " guesses.\n\n";
        } else if (playerGuesses > cpuGuesses) {
            int difference = playerGuesses - cpuGuesses;
            cout << "Haha. I won by " << difference << " guesses.\n\n";
        } else {
            cout << "Oof. That's a tie.";
        }

        input = playAgain(curGame);
    } while (input != 2);

}
