#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include "../h/cPlusOneMiniGames.h"

using namespace std;

int playGame(string word, int maxWrong) {
    int wrong = 0;
    string soFar(word.size(), '_');
    string used = "";

    while ((wrong < maxWrong) && (soFar != word)) {
        cout << "\n\nYou have " << (maxWrong - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);
        while (used.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (word.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word.\n";

            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess) {
                    soFar[i] = guess;
                }
            } 
        } else {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    if (soFar == word) {
        return 1;
    } else {
        return 0;
    }
}

void Hangman() {
    int input;
    string curGame = "Hangman";
    const int MAX_WRONG = 8;

    vector<string> words;
    words.push_back("HOCKEY");
    words.push_back("WRESTLING");
    words.push_back("WHIPLASH");
    words.push_back("JESUS");
    words.push_back("FLETCHER");

    do {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(words.begin(), words.end());
        const string THE_WORD = words[0];

        cout << "Welcome to Hangman. Good luck!\n";
        
        if (playGame(THE_WORD, MAX_WRONG)) {
            cout << "\nYou've survived!";
        } else {
            cout << "\nYou've been hanged!";
        }

        cout << "\nThe word was " << THE_WORD << endl;

        input = playAgain(curGame);
    } while (input != 2);
}