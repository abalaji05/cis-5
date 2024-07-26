/*
 * Author: Akshay Balaji
 * Created on 7/21/2024
 * Purpose: Blackjack game
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
using namespace std;

// Named Constants
const int MAX_SCORE = 21;
const int DEALER_HIT_LIMIT = 17;

// Function Prototypes
int getCardValue(void);
string getCardSuit(void);
void updateFile(ofstream&, string, int, string);
void recordWinner(ofstream&, string, string);
void displayWinner(bool, bool);

// Execution begins here
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    // Variables for file I/O
    ifstream inFile("card.dat");
    ofstream outFile("card.dat", ios::app); // Open in append mode
    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Get player's name
    string playerName;
    cout << "Enter player's name: ";
    getline(cin, playerName);

    // Initial Card Dealing
    int pc1val = getCardValue(); // Primitive data type (int)
    string pc1vst = getCardSuit(); // Reference data type (string)
    updateFile(outFile, playerName, pc1val, pc1vst);

    int pc2val = getCardValue(); // Primitive data type (int)
    string pc2vst = getCardSuit(); // Reference data type (string)
    updateFile(outFile, playerName, pc2val, pc2vst);

    int dc1val = getCardValue(); // Primitive data type (int)
    string dc1vst = getCardSuit(); // Reference data type (string)
    updateFile(outFile, "Dealer", dc1val, dc1vst);

    int dc2val = getCardValue(); // Primitive data type (int)
    string dc2vst = getCardSuit(); // Reference data type (string)
    updateFile(outFile, "Dealer", dc2val, dc2vst);

    // Display Initial Hands
    cout << playerName << "'s Hand: " << pc1val << " of " << pc1vst << ", " << pc2val << " of " << pc2vst << endl;
    cout << "Dealer's Hand: " << dc1val << " of " << dc1vst << ", " << dc2val << " of " << dc2vst << endl;

    // Player's Turn Logic
    char choice; // Primitive data type (char)
    int pTotal = pc1val + pc2val; // Primitive data type (int)
    do {
        cout << playerName << "'s total: " << pTotal << endl;
        cout << "Do you want to hit (h/H) or stand (s/S)? ";
        cin >> choice;
        
        while (cin.fail() || (choice != 'h' && choice != 'H' && choice != 's' && choice != 'S')) {
            
            cin.clear(); // clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
            cout << "Invalid choice. Please enter 'h/H' to hit or 's/S' to stand: ";
            cin >> choice;
        }
        
        if (choice == 'h' || choice == 'H') {
            
            int nCValue = getCardValue(); // Primitive data type (int)
            string nCSuit = getCardSuit(); // Reference data type (string)
            
            pTotal += nCValue;
            cout << "You got " << nCValue << " of " << nCSuit << endl;
            updateFile(outFile, playerName, nCValue, nCSuit);
            
            if (pTotal > MAX_SCORE) {
                
                cout << playerName << " busts with total: " << pTotal << endl;
                outFile.close();
                recordWinner(outFile, playerName, "Dealer");
                return 0;
            }
        }
    } while (choice == 'h' || choice == 'H');

    // Dealer's Turn Logic
    int dTotal = dc1val + dc2val; // Primitive data type (int)
    
    while (dTotal < DEALER_HIT_LIMIT) {
        
        int nCValue = getCardValue(); // Primitive data type (int)
        string nCSuit = getCardSuit(); // Reference data type (string)
        
        dTotal += nCValue;
        cout << "Dealer got " << nCValue << " of " << nCSuit << endl;
        updateFile(outFile, "Dealer", nCValue, nCSuit);
    }
    
    cout << "Dealer's total: " << dTotal << endl;

    // Determine Winner
    if (dTotal > MAX_SCORE || pTotal > dTotal) {
        
        cout << playerName << " wins!" << endl;
        recordWinner(outFile, playerName, playerName);
    } 
    else if (dTotal > pTotal) {
        
        cout << "Dealer wins!" << endl;
        recordWinner(outFile, playerName, "Dealer");
    } 
    else {
        
        cout << "It's a tie!" << endl;
        recordWinner(outFile, playerName, "Tie");
    }

    outFile.close();
    return 0;
}

// Function to get a random card value
int getCardValue() {
    
    int card = rand() % 13 + 1;
    if (card > 10) return 10;
    if (card == 1) return 11;
    
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

// Function to record a card to a file
void updateFile(ofstream &file, string player, int value, string suit) {
    file << player << ": " << value << " of " << suit << endl;
}

// Function to record the winner
void recordWinner(ofstream &file, string player, string winner) {
    
    if (file.is_open()) {
        file << "Winner: " << winner << " (Player: " << player << ")" << endl;
    } 
    
    else {
        ofstream outFile("card.dat", ios::app);
        outFile << "Winner: " << winner << " (Player: " << player << ")" << endl;
        outFile.close();
    }
}