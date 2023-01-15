#ifndef CPLUSONEMINIGAMES_H
#define CPLUSONEMINIGAMES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <ostream>

using namespace std;

// Main
int playAgain(string game);

// Campfire Story
void tellStory(int goldPieces, int adventurers, int killed, int survivors, string leader);
void CampfireStory();

// Guess My Number
void GuessMyNumber();

// Word Jumble
void WordJumble();

// Hangman
void Hangman();

// Blackjack
void Blackjack();

#endif