#include <iostream>

// Games Functions
#include "campfireStory.h"
#include "guessMyNumber.h"
#include "wordJumble.h"
#include "hangman.h"

using namespace std;

int main() {
    int input;

    do {
        cout << "\tWelcome to C Plus One Mini Games!\n";
        cout << "\nWhich game do you want to play?\n";

        input = gameOptions();

        goToGame(input);
        
    } while (input != 0);

    cout << "\nThanks for playing!\n";

    return 0;
}

int gameOptions() {
    int option;

    // Options
    cout << "\n1 - Campfire Story\n";
    cout << "2 - Guess My Number\n";
    cout << "3 - Word Jumble\n";
    cout << "4 - Hangman\n";
    cout << "5 - \n";
    cout << "6 - \n";
    cout << "7 - \n";
    cout << "8 - \n";
    cout << "9 - \n";
    cout << "10 - \n";

    cout << "\n0 - Quit\n";

    do {
        cout << "\nYour choice: ";
        cin >> option;

        if (option < 0 || option > 10) {
            cout << "Not a valid option.";
        }
    } while (option < 0 || option > 10);

    return option;
}

void goToGame(int input) {
    switch (input) {
        case 1:
            campfireStory();
            break;
        
        case 2:
            guessMyNumber();
            break;
        
        case 3:
            wordJumble();
            break;
        
        case 4:
            hangman();
            break;

        case 5:
            break;
            
        case 6:
            break;
        
        case 7:
            break;
        
        case 8:
            break;
        
        case 9:
            break;
        
        case 10:
            break;
        
        
        default:
            break;
    }
}