/*
 * Author: Akshay Balaji
 * Created on 7/21/2024
 * Purpose: Blackjack game
 */

// System Libraries
#include <iostream>   // For input/output operations
#include <cstdlib>    // For random number generation and utility functions
#include <ctime>      // For seeding the random number generator
#include <string>     // For string operations
#include <fstream>    // For file input/output operations
#include <limits>     // For handling input validation
#include <cmath>      // For mathematical functions
using namespace std;

// Named Constants
const int MAX_SCORE = 21;           // Maximum score in Blackjack
const int DEALER_HIT_LIMIT = 17;    // Dealer must hit if their score is below this limit

// Function Prototypes
int getCardValue(void);                             // Function to get a random card value
string getCardSuit(void);                           // Function to get a random card suit
void updateFile(ofstream&, string, int, string);    // Function to update the file with card details
void recordWinner(ofstream&, string, string);       // Function to record the winner in the file
void displayWinner(bool, bool);                     // Function to display the winner (prototype only)
void validateInput(char&);                          // Function to validate user input

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    // Variables for file I/O
    ifstream inFile("card.dat");                       // Input file stream for reading
    ofstream outFile("card.dat", ios::app);            // Output file stream for appending data
    if (!outFile.is_open()) {                          // Check if the file is open
        cout << "Error opening file!" << endl;         // Print error message if file fails to open
        return 1;                                      // Exit with error code
    }

    // Get player's name
    string pName;
    cout << "Enter player's name: ";
    getline(cin, pName);                          // Read player's name

    // Initial Card Dealing
    int pc1val = getCardValue();                       // Get first card value for player
    string pc1vst = getCardSuit();                     // Get first card suit for player
    updateFile(outFile, pName, pc1val, pc1vst);   // Update file with player's first card details

    int pc2val = getCardValue();                       // Get second card value for player
    string pc2vst = getCardSuit();                     // Get second card suit for player
    updateFile(outFile, pName, pc2val, pc2vst);   // Update file with player's second card details

    int dc1val = getCardValue();                       // Get first card value for dealer
    string dc1vst = getCardSuit();                     // Get first card suit for dealer
    updateFile(outFile, "Dealer", dc1val, dc1vst);     // Update file with dealer's first card details

    int dc2val = getCardValue();                       // Get second card value for dealer
    string dc2vst = getCardSuit();                     // Get second card suit for dealer
    updateFile(outFile, "Dealer", dc2val, dc2vst);     // Update file with dealer's second card details

    // Display Initial Hands
    cout << pName << "'s Hand: " << pc1val << " of " << pc1vst << ", " << pc2val << " of " << pc2vst << endl;
    cout << "Dealer's Hand: " << dc1val << " of " << dc1vst << ", " << dc2val << " of " << dc2vst << endl;

    // Player's Turn Logic
    char choice;                                      // Variable to store player's choice
    int pTotal = pc1val + pc2val;                     // Calculate player's initial total score
    do {
        cout << pName << "'s total: " << pTotal << endl;
        cout << "Do you want to hit (h/H) or stand (s/S)? ";
        cin >> choice;                                // Get player's choice

        validateInput(choice);                        // Validate user input

        if (choice == 'h' || choice == 'H') {         // If player chooses to hit
            int nCValue = getCardValue();             // Get new card value for player
            string nCSuit = getCardSuit();            // Get new card suit for player

            pTotal += nCValue;                        // Update player's total score
            cout << "You got " << nCValue << " of " << nCSuit << endl;
            updateFile(outFile, pName, nCValue, nCSuit);   // Update file with new card details

            if (pTotal > MAX_SCORE) {                 // If player's total exceeds MAX_SCORE
                cout << pName << " busts with total: " << pTotal << endl;
                outFile.close();                      // Close the output file
                recordWinner(outFile, pName, "Dealer");    // Record dealer as winner
                return 0;                             // Exit the program
            }
        }
    } while (choice == 'h' || choice == 'H');         // Repeat if player chooses to hit

    // Dealer's Turn Logic
    int dTotal = dc1val + dc2val;                     // Calculate dealer's initial total score
    while (dTotal < DEALER_HIT_LIMIT) {               // Dealer hits while total is below DEALER_HIT_LIMIT
        int nCValue = getCardValue();                 // Get new card value for dealer
        string nCSuit = getCardSuit();                // Get new card suit for dealer

        dTotal += nCValue;                            // Update dealer's total score
        cout << "Dealer got " << nCValue << " of " << nCSuit << endl;
        updateFile(outFile, "Dealer", nCValue, nCSuit);  // Update file with new card details
    }

    cout << "Dealer's total: " << dTotal << endl;

    // Determine Winner
    int pAbstot = abs(pTotal - MAX_SCORE);          // Calculate absolute difference from MAX_SCORE for player
    int dAbstot = abs(dTotal - MAX_SCORE);          // Calculate absolute difference from MAX_SCORE for dealer

    cout << pName << "'s absolute difference from 21: " << pAbstot << endl;
    cout << "Dealer's absolute difference from 21: " << dAbstot << endl;

    if (dTotal > MAX_SCORE || pTotal > dTotal) {      // Determine winner based on scores
        cout << pName << " wins!" << endl;
        recordWinner(outFile, pName, pName); // Record player as winner
    } else if (dTotal > pTotal) {
        cout << "Dealer wins!" << endl;
        recordWinner(outFile, pName, "Dealer");  // Record dealer as winner
    } else {
        cout << "It's a tie!" << endl;
        recordWinner(outFile, pName, "Tie");     // Record a tie
    }

    outFile.close();                                  // Close the output file
    return 0;
}

// Function to get a random card value
int getCardValue() {
    int card = rand() % 13 + 1;                       // Generate a random number between 1 and 13
    if (card > 10) return 10;                         // Face cards are worth 10
    if (card == 1) return 11;                         // Ace is worth 11
    return card;                                      // Return card value
}

// Function to get a random card suit
string getCardSuit() {
    int suit = rand() % 4;                            // Generate a random number between 0 and 3
    switch (suit) {                                   // Return corresponding suit as string
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
    }
    return "";                                        // Default return if no match
}

// Function to record a card to a file
void updateFile(ofstream &file, string player, int value, string suit) {
    file << player << ": " << value << " of " << suit << endl; // Write player, card value, and suit to file
}

// Function to record the winner
void recordWinner(ofstream &file, string player, string winner) {
    if (file.is_open()) {                             // Check if file is open
        file << "Winner: " << winner << " (Player: " << player << ")" << endl; // Write winner to file
    } else {                                          // If file is not open, open it in append mode
        ofstream outFile("card.dat", ios::app);
        outFile << "Winner: " << winner << " (Player: " << player << ")" << endl;
        outFile.close();                              // Close the file after writing
    }
}

// Function to validate user input
void validateInput(char &choice) {
    while (cin.fail() || (choice != 'h' && choice != 'H' && choice != 's' && choice != 'S')) {
        cin.clear();                                  // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore last input
        cout << "Invalid choice. Please enter 'h/H' to hit or 's/S' to stand: ";
        cin >> choice;                                // Get user input again
    }
}

