/* 
 * Author: Akshay Balaji
 * Created on 7/21/2024
 * Purpose:  Blackjack game - version 1
 */

//System Libraries 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int getCardValue(void);
string getCardSuit(void);

// Execution begins here
int main() {
    
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0))); 

    // Initialize cards for player1
    int pc1val = getCardValue();
    string pc1st = getCardSuit();

    int pc2val = getCardValue();
    string pc2vst = getCardSuit();

    // Dealing initial cards for the dealer
    int dc1val = getCardValue();
    string dc1vst = getCardSuit();

    int dc2val = getCardValue();
    string dc2vst = getCardSuit();

    // Display the initial hands
    cout << "Player's Hand: " << pc1val << " of " << pc1st
         << ", " << pc2val << " of " << pc2vst << endl;

    cout << "Dealer's Hand: " << dc1val << " of " << dc1vst
         << ", " << dc2val << " of " << dc2vst << endl;

    return 0;
}

// Function to get a random card value
int getCardValue() {
    int card = rand() % 13 + 1;
    // Face Cards
    if (card > 10)
        return 10;
    // Ace
    else if (card == 1)
        return 11; 
    return card;
}

// Function to get a random card suit
string getCardSuit() {
    int suit = rand() % 4;
    switch (suit) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
    }
    return "";
}
