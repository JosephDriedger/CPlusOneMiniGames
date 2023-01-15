#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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

void GuessMyNumber() {
    int input;
    string game = "Guess My Number";

    do {
        srand(static_cast<unsigned int>(time(0)));

        // Get a Number between 1 and 100
        int num = (rand() / 100) + 1;

        int guess;
        int numOfGuesses = 0;
        bool success;

        cout << "\tWelcome to Guess My Number\n\n";

        do {
            cout << "Enter a guess: ";
            cin >> guess;

            int feedback = guessNumber(num, guess);

            if (feedback == 1) {
                cout << "Too low!\n\n";
                success = false;
            } else if (feedback == -1) {
                cout << "Too high!\n\n";
                success = false;
            } else {
                success = true;
            }

            numOfGuesses++;
        } while (!success);

        cout << "\nThat's it! You got it in " << numOfGuesses << " guesses!\n";

        input = playAgain(game);
    } while (input != 2);

}