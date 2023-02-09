#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <ostream>
#include "../h/cPlusOneMiniGames.h"

#define MAX_HOUSES 32
#define MAX_HOTELS 12
#define MAX_SPACES 40
#define MAX_CHANCE_CARDS 16
#define MAX_COMMUNITY_CARDS 16
#define MAX_PROPERTIES 28

using namespace std;

enum Transaction {BUY, SELL};

class Space {
    public:
        string GetName();
        int GetLocation();
        Space(string name);
    protected:
        string name;
        int location;
};

class CardDraw: public Space {
    public:
        CardDraw(int chance, int community);

        Card drawCard();
    private:
        int chanceCards;
        int communityCards;
        Card chanceDrawPile[MAX_CHANCE_CARDS];
        Card chanceDiscardPile[MAX_CHANCE_CARDS];
        Card communityDrawPile[MAX_COMMUNITY_CARDS];
        Card communityDiscardPile[MAX_COMMUNITY_CARDS];
};

class Card {
    public:
        enum CardType {CHANCE, COMMUNITY};
        Card(CardType type, string title, string description, Action action, bool canKeep);

        void PlayCard();
    private:
        const CardType TYPE;
        string title;
        string description;
        Action action;
        bool canKeep;
        Player owner;
};

class Action {
    public:
        Action(int id, string instruction);

        void PerformAction();
    private:
        int id;
        string instruction;
};

class Tax: public Space {
    public:
        Tax(int tax);

        int ChargeTax();
    private:
        int taxAmount;
};

class Jail: public Space {
    public:
        Jail(int fee);

        int chargeBail();
        bool rollEscape();

    private:
        int bailFee;
};

class PassGo: public Space {
    public:
        PassGo(int amount);

        int CollectAmount();
    
    private:
        int amount;
};

class Property: public Space {
    public:
        virtual ~Property();
        virtual int ChargeRent();

        Player GetOwner();
        int GetPrice();
        int BuyProperty(Player buyer, int amount);
        bool isMortgaged();
        void ToggleMortgage();
    
    protected:
        int price;
        Player owner;
        bool isMortgaged;
        int mortgagePrice;
        int unmortgagePrice;
};

class Utility: public Property {
    public:
        Utility(int modifier);

        void ChangeMod(int modifier);
        int ChargeRent(Player tenant);
        void PrintModifiers();

    private:
        int curModifier;
        const int modifiers[2];
};

class Estate: public Property {
    public:
        enum ColourSet {BROWN, CYAN, PINK, ORANGE, RED, YELLOW, GREEN, BLUE};
        Estate(ColourSet colourSet, int rentPrices[], int upgradePrice);
        
        int ChargeRent(Player tenant);
        int GetCurRent();
        void PrintRentPrices();
        ColourSet GetColourSet();
        int GetHouses();
        int GetHotels();
        void BuyHouse();
        void SellHouse();
        void BuyHotel();
        void SellHotel();

    private:
        ColourSet m_ColourSet;
        int houses;
        int hotels;
        int curRent;
        const int rentPrices[4];
};

class Railroad: public Property {
    public:
        Railroad(int unitPrice, int rentPrices[]);

        void PrintRentPrices();
        int GetCurRent();
        int ChargeRent(Player tenant);
    private:
        int unitPrice;
        int curRent;
        int rentPrices[4];
};

class Player {
    public:
        Player(int startAmt);
    private:
        int boardPos;
        int bankAccount;
};

class Bank {
    public:
        Bank(int houses, int hotels);

        void PrintInventory();
        void UpdateHouse(Transaction mode);
        void UpdateHotel(Transaction mode);
    
    private:
        int houses;
        int hotels;
        Property properties[MAX_PROPERTIES];
};

class Board {
    public:
        Board(Player players[]);

        Space spaces[MAX_SPACES];
        Player players[];
        void PrintBoard();

    private:
        void AddPlayers();
        void AddSpaces();
};

Board board;
Bank bank;

int rollDie() {
    return 0;
}

void setupGame() {

}

void turn() {

}

void game() {

}

void Monopoly() {

}
