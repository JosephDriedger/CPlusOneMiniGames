#include <iostream>

// Games Functions
#include "campfireStory.cpp"
#include "guessMyNumber.cpp"
#include "wordJumble.cpp"
#include "hangman.cpp"
#include "blackjack.cpp"

using namespace std;

int main() {
    int input;

    do {
        cout << "\tWelcome to C Plus One Mini Games!\n";
        cout << "\nWhich game do you want to play?\n\n";

        input = gameOptions();

        goToGame(input);
        
    } while (input != 0);

    cout << "\nThanks for playing!\n";

    return 0;
}

int gameOptions() {
    int option;

    // Options
    cout << "1 - Campfire Story\n";
    cout << "2 - Guess My Number\n";
    cout << "3 - Word Jumble\n";
    cout << "4 - Hangman\n";
    cout << "5 - Blackjack\n";
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
            CampfireStory();
            break;
        
        case 2:
            GuessMyNumber();
            break;
        
        case 3:
            WordJumble();
            break;
        
        case 4:
            Hangman();
            break;

        case 5:
            Blackjack();
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