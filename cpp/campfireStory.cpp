#include <iostream>
#include <string>
#include "../h/cPlusOneMiniGames.h"

using namespace std;

void tellStory(int goldPieces, int adventurers, int killed, int survivors, string leader) {
    cout << "\nA brave group of " << adventurers << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue, " << leader << ".\n";

    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventurers, " << killed << " were vanquished, ";
    cout << "leaving just " << survivors << " in the group.\n";

    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortunes. ";
    cout << "So the adventurers split " << goldPieces << " gold pieces. ";
    cout << leader << " held on to the extra " << (goldPieces % survivors);
    cout << " pieces to keep things fair of course.\n\n";
}

void CampfireStory() {
    const int GOLD_PIECES = 900;
    int adventurers = 0;
    int killed = 0;
    int survivors;
    string leader;
    string curGame = "Campfire Story";
    int input;

    cout << "Welcome to Lost Fortune\n\n";

    do {
        cout << "Please enter the following for your personalized adventure\n";

        cout << "Enter a number: ";
        cin >> adventurers;

        do {
            cout << "Enter a number, smaller than the first: ";
            cin >> killed;

            if (killed >= adventurers) {
                cout << killed << " is not smaller than " << adventurers << endl;
            } else if (killed < 0) {
                cout << killed << " is not a valid number." << endl;
            }
        } while (killed >= adventurers || killed < 0);

        survivors = adventurers - killed;

        cout << "Enter your last name: ";
        cin >> leader;

        tellStory(GOLD_PIECES, adventurers, killed, survivors, leader);

        input = playAgain(curGame);
    } while (input != 2);

}

