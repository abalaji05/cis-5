/* 
 * Author: Akshay Balaji
 * Created on 7/21/2024
 * Purpose:  Blackjack game - version 3
 */

//System Libraries 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function Prototypes
int getCardValue(void);
string getCardSuit(void);

// Execution begins here
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    // Dealing initial cards for the player
    int pc1val = getCardValue();
    string pc1vst = getCardSuit();

    int pc2val = getCardValue();
    string pc2vst = getCardSuit();

    // Dealing initial cards for the dealer
    int dc1val = getCardValue();
    string dc1vst = getCardSuit();

    int dc2val = getCardValue();
    string dc2vst = getCardSuit();

    // Display the initial hands
    cout << "Player's Hand: " << pc1val << " of " << pc1vst
         << ", " << pc2val << " of " << pc2vst << endl;

    cout << "Dealer's Hand: " << dc1val << " of " << dc1vst
         << ", " << dc2val << " of " << dc2vst << endl;

    // Player's turn logic
    char choice;
    int pTotal = pc1val + pc2val;
    while (true) {
        cout << "Player's total: " << pTotal << endl;
        cout << "Do you want to hit (h/H) or stand (s/S)? ";
        cin >> choice;
        if (choice == 'h' || choice == 'H') {
            int nCValue = getCardValue();
            string nCSuit = getCardSuit();
            pTotal += nCValue;
            cout << "You got " << nCValue << " of " << nCSuit << endl;
            if (pTotal > 21) {
                cout << "Player busts with total: " << pTotal << endl;
                return 0;
            }
        } else if (choice == 's' || choice == 'S') {
            break;
        } else {
            cout << "Invalid choice. Please enter 'h/H' to hit or 's/S' to stand." << endl;
        }
    }

    // Dealer's turn logic
    int dTotal = dc1val + dc2val;
    while (dTotal < 17) {
        int nCValue = getCardValue();
        string nCSuit = getCardSuit();
        dTotal += nCValue;
        cout << "Dealer got " << nCValue << " of " << nCSuit << endl;
    }
    cout << "Dealer's total: " << dTotal << endl;

    // Determine winner
    if (dTotal > 21 || pTotal > dTotal) {
        cout << "Player wins!" << endl;
    } else if (dTotal > pTotal) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

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
