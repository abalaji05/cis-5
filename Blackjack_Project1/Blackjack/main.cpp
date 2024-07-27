/*
 * Author: Akshay Balaji
 * Created on 7/21/2024
 * Updated on 7/26/2024
 * Purpose: Enhanced Blackjack game with betting, multiple players, and better output
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

// Named Constants
const int MAX_SCORE = 21;
const int DEALER_HIT_LIMIT = 17;
const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 8;

// Function Prototypes
int getCardValue(void);    // Get a random card value
string getCardSuit(void);  // Get a random card suit
void updateFile(ofstream&, string, int, string = "Unknown Suit");    // Update file with card details
void updateFile(ofstream&, string, int);                             // Overloaded function to update file with card details
void recordWinner(ofstream&, string, string);    // Record the winner in the file
void validateInput(char&);    // Validate user input for hit or stand
void validateBetInput(int&);    // Validate bet input
void displayLeaderboard(const map<string, int>&, int);    // Display the leaderboard
void exitFunction(const string& message);    // Exit function with a message

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Variables for file I/O
    ofstream outFile("card.dat", ios::app);
    if (!outFile.is_open()) {
        exitFunction("Error opening file!");    // Exit if file cannot be opened
    }

    // Input: Number of players
    int numPlyrs;
    cout << "Enter number of players (1-8): ";
    cin >> numPlyrs;
    while (numPlyrs < MIN_PLAYERS || numPlyrs > MAX_PLAYERS) {
        cout << "Invalid number of players. Enter a number between 1 and 8: ";
        cin >> numPlyrs;
    }

    // Input: Player names and bets
    string plyrNms[MAX_PLAYERS];
    int plyrBts[MAX_PLAYERS];
    int plyrBlncs[MAX_PLAYERS] = {0};    // Player balances initialized to 0
    map<string, int> ttlWnngs;    // Total winnings

    for (int i = 0; i < numPlyrs; ++i) {
        cout << "Enter player " << i + 1 << "'s name: ";
        cin.ignore();
        getline(cin, plyrNms[i]);
        cout << "Enter bet amount for " << plyrNms[i] << ": ";
        cin >> plyrBts[i];
        validateBetInput(plyrBts[i]);
    }

    // Initial card dealing
    int plyrTtls[MAX_PLAYERS] = {0};
    for (int i = 0; i < numPlyrs; ++i) {
        int crd1 = getCardValue();
        string sut1 = getCardSuit();
        updateFile(outFile, plyrNms[i], crd1, sut1);

        int crd2 = getCardValue();
        string sut2 = getCardSuit();
        updateFile(outFile, plyrNms[i], crd2, sut2);

        plyrTtls[i] = crd1 + crd2;
        cout << plyrNms[i] << "'s Hand: " << crd1 << " of " << sut1 << ", " << crd2 << " of " << sut2 << endl;
    }

    // Initial card dealing for the dealer
    int dlrCrd1 = getCardValue();
    string dlrSut1 = getCardSuit();
    updateFile(outFile, "Dealer", dlrCrd1, dlrSut1);

    int dlrCrd2 = getCardValue();
    string dlrSut2 = getCardSuit();
    updateFile(outFile, "Dealer", dlrCrd2, dlrSut2);

    int dlrTtl = dlrCrd1 + dlrCrd2;
    cout << "Dealer's Hand: " << dlrCrd1 << " of " << dlrSut1 << ", " << dlrCrd2 << " of " << dlrSut2 << endl;

    // Player's Turn: Each player can hit or stand
    for (int i = 0; i < numPlyrs; ++i) {
        char choice;
        do {
            cout << plyrNms[i] << "'s total: " << plyrTtls[i] << endl;
            cout << "Do you want to hit (h/H) or stand (s/S)? ";
            cin >> choice;
            validateInput(choice);

            if (choice == 'h' || choice == 'H') {
                int newCrd = getCardValue();
                string newSut = getCardSuit();
                plyrTtls[i] += newCrd;
                cout << "You got " << newCrd << " of " << newSut << endl;
                updateFile(outFile, plyrNms[i], newCrd, newSut);

                if (plyrTtls[i] > MAX_SCORE) {
                    cout << plyrNms[i] << " busts with total: " << plyrTtls[i] << endl;
                    break;
                }
            }
        } while (choice == 'h' || choice == 'H');
    }

    // Dealer's Turn: Dealer hits until reaching DEALER_HIT_LIMIT
    while (dlrTtl < DEALER_HIT_LIMIT) {
        int newCrd = getCardValue();
        string newSut = getCardSuit();
        dlrTtl += newCrd;
        cout << "Dealer got " << newCrd << " of " << newSut << endl;
        updateFile(outFile, "Dealer", newCrd, newSut);
    }

    cout << "Dealer's total: " << dlrTtl << endl;

    // Determine winners
    for (int i = 0; i < numPlyrs; ++i) {
        int plyrDiff = abs(plyrTtls[i] - MAX_SCORE);
        int dlrDiff = abs(dlrTtl - MAX_SCORE);

        cout << plyrNms[i] << "'s absolute difference from 21: " << plyrDiff << endl;
        cout << "Dealer's absolute difference from 21: " << dlrDiff << endl;

        if (plyrTtls[i] > MAX_SCORE) {
            cout << plyrNms[i] << " busts and cannot win!" << endl;
            ttlWnngs["Dealer"] += plyrBts[i];
        } else if (dlrTtl > MAX_SCORE || plyrTtls[i] > dlrTtl) {
            cout << plyrNms[i] << " wins!" << endl;
            recordWinner(outFile, plyrNms[i], plyrNms[i]);
            ttlWnngs[plyrNms[i]] += plyrBts[i] * (numPlyrs + 1); // Player gains bets from all players and dealer
            plyrBlncs[i] += plyrBts[i] * numPlyrs; // Calculate player balance after win
        } else if (dlrTtl > plyrTtls[i]) {
            cout << "Dealer wins against " << plyrNms[i] << "!" << endl;
            recordWinner(outFile, plyrNms[i], "Dealer");
            ttlWnngs["Dealer"] += plyrBts[i];
        } else {
            cout << "It's a tie for " << plyrNms[i] << "!" << endl;
            recordWinner(outFile, plyrNms[i], "Tie");
        }
    }

    outFile.close();
    displayLeaderboard(ttlWnngs, numPlyrs);

    // Display player balances
    for (int i = 0; i < numPlyrs; ++i) {
        cout << plyrNms[i] << "'s balance: " << plyrBlncs[i] << endl;
    }

    return 0;
}

// Get a random card value
int getCardValue() {
    int crd = rand() % 13 + 1;
    if (crd > 10) return 10;
    if (crd == 1) return 11;
    return crd;
}

// Get a random card suit
string getCardSuit() {
    int sut = rand() % 4;
    switch (sut) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
    }
    return "";
}

// Update file with card details
void updateFile(ofstream &file, string plyr, int val, string sut) {
    file << plyr << ": " << val << " of " << sut << endl;
}

// Overloaded function to update file with card details
void updateFile(ofstream &file, string plyr, int val) {
    file << plyr << ": " << val << " of " << "Unknown Suit" << endl;
}

// Record the winner in the file
void recordWinner(ofstream &file, string plyr, string wnr) {
    if (file.is_open()) {
        file << "Winner: " << wnr << " (Player: " << plyr << ")" << endl;
    } else {
        ofstream outFile("card.dat", ios::app);
        outFile << "Winner: " << wnr << " (Player: " << plyr << ")" << endl;
        outFile.close();
    }
}

// Validate user input for hit or stand
void validateInput(char &choice) {
    while (cin.fail() || (choice != 'h' && choice != 'H' && choice != 's' && choice != 'S')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 'h/H' to hit or 's/S' to stand: ";
        cin >> choice;
    }
}

// Validate bet input
void validateBetInput(int &bet) {
    while (cin.fail() || bet <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid bet amount. Please enter a positive number: ";
        cin >> bet;
    }
}

// Display the leaderboard
void displayLeaderboard(const map<string, int> &winnings, int numPlyrs) {
    cout << "\nLeaderboard:" << endl;
    for (const auto &entry : winnings) {
        cout << entry.first << ": " << entry.second << " points" << endl;
    }
}

// Exit function with a message
void exitFunction(const string& message) {
    cout << message << endl;
    exit(1);
}

