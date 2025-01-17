/*
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created: 7/21/2024
 * Purpose:  Blackjack game
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int MAX_SCORE = 21;
const int DEALER_LIMIT = 17;
const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 8;
const int MAX_CARDS = 10;

// Structure to hold player information
struct Player {
    string name;
    int total;
    int wnngs;
};

// Function Prototypes
int getCard();          // Get a random card value
string getSuit();       // Get a random card suit
void updFile(ofstream&, const string&, int, const string& = "Unknown"); // Update file with card details
void updHand(int[][MAX_CARDS], int[], int, int, int, vector<string>&, const string&); // Update hand with card details
void recWin(ofstream&, const vector<string>&, int[][MAX_CARDS], int[], int, const string&); // Record the winner in the file
void valInput(char&);    // Validate user input for hit or stand
void valBet(int&);       // Validate bet input
void showLead(const vector<Player>&, int); // Display the leaderboard
void exitMsg(const string& msg); // Exit function with a message
void bubbleSort(vector<Player>&); // Bubble sort for player scores
void selectionSort(vector<Player>&); // Selection sort for player winnings
int linearSearch(const vector<string>&, const string&); // Linear search for player names
int getCard(int mplier); // Overloaded function to get a random card value with a mplier

// Execution Begins Here!
int main() {
    // Declare Variables
    int nPlyrs;
    vector<string> pNames;  // Declare vector without initializing size
    int pBets[MAX_PLAYERS];
    int pBlns[MAX_PLAYERS] = {0}; // Player balances initialized to 0
    int tWngs[MAX_PLAYERS + 1] = {0}; // Total wnngs (last index for dealer)
    vector<string> winnrs(MAX_PLAYERS + 1); // Names of winners

    int pTotals[MAX_PLAYERS + 1] = {0}; // +1 for the dealer
    int dTotal;

    int dCard1, dCard2;
    string dSuit1, dSuit2;
    
    int hands[MAX_PLAYERS + 1][MAX_CARDS] = {0}; // +1 for the dealer
    vector<string> hSuits; // Vector for hand suits based on number of players

    srand(static_cast<unsigned int>(time(0)));

    ofstream outFile("card.dat", ios::app);
    if (!outFile.is_open()) {
        exitMsg("Error opening file!");
    }

    while (true) {
        cout << "Enter number of players (1-8): ";
        cin >> nPlyrs;
        
        // Check if the input is an integer
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
        } else if (nPlyrs < MIN_PLAYERS || nPlyrs > MAX_PLAYERS) {
            cout << "Invalid number of players. Enter a number between 1 and 8." << endl;
        } else {
            break;  // Valid input
        }
    }
    
    pNames.resize(nPlyrs);  // Resize vector to the number of players
    vector<Player> players(nPlyrs);  // Vector of Player structures
    hSuits.resize(nPlyrs + 1); // Resize handSuits for the number of players and one for the dealer

    for (int i = 0; i < nPlyrs; ++i) {
        cout << "Enter player " << i + 1 << "'s name: ";
        cin.ignore();
        getline(cin, pNames[i]);
        players[i].name = pNames[i];
        cout << "Enter bet amount for " << pNames[i] << ": ";
        cin >> pBets[i];
        valBet(pBets[i]);
    }
    
    for (int i = 0; i < nPlyrs; ++i) {
        // Deal two cards to each player
        for (int j = 0; j < 2; ++j) {
            int crd = getCard();
            string sut = getSuit();
           
            updHand(hands, pTotals, i, j, crd, hSuits, sut);
        }
        players[i].total = pTotals[i];
        cout << pNames[i] << "'s Hand: " << hSuits[i] << endl;
    }

    // Initial card dealing for the dealer
    dCard1 = getCard();
    dSuit1 = getSuit();
    updHand(hands, pTotals, nPlyrs, 0, dCard1, hSuits, dSuit1);

    dCard2 = getCard();
    dSuit2 = getSuit();
    updHand(hands, pTotals, nPlyrs, 1, dCard2, hSuits, dSuit2);

    dTotal = dCard1 + dCard2;
    cout << "Dealer's Hand: " << hSuits[nPlyrs] << endl;

    // Player's Turn: Each player can hit or stand
    for (int i = 0; i < nPlyrs; ++i) {
        char choice;
        int cardIndex = 2;
        do {
            cout << pNames[i] << "'s total: " << pTotals[i] << endl;
            cout << "Do you want to hit (h/H) or stand (s/S)? ";
            cin >> choice;
            valInput(choice);

            if (choice == 'h' || choice == 'H') {
                int newCrd = getCard();
                string newSut = getSuit();
                if (cardIndex < MAX_CARDS) {
                    updHand(hands, pTotals, i, cardIndex, newCrd, hSuits, newSut);
                    cardIndex++;
                    cout << "You got " << newCrd << " of " << newSut << endl;
                } else {
                    cout << "Maximum cards reached for " << pNames[i] << endl;
                    break;
                }

                if (pTotals[i] > MAX_SCORE) {
                    cout << pNames[i] << " busts with total: " << pTotals[i] << endl;
                    break;
                }
            }
        } while (choice == 'h' || choice == 'H');
        players[i].total = pTotals[i];
    }

    // Dealer's Turn: Dealer hits until reaching DEALER_LIMIT
    int dCrdIdx = 2;
    while (dTotal < DEALER_LIMIT && dCrdIdx < MAX_CARDS) {
        int newCrd = getCard();
        string newSut = getSuit();
        dTotal += newCrd;
        cout << "Dealer got " << newCrd << " of " << newSut << endl;
        updHand(hands, pTotals, nPlyrs, dCrdIdx, newCrd, hSuits, newSut);
        dCrdIdx++;
    }

    cout << "Dealer's total: " << dTotal << endl;

    string bPlyr = "";
    int bTotal = 0;

    // Determine winners
    for (int i = 0; i < nPlyrs; ++i) {
        if (pTotals[i] > MAX_SCORE) {
            cout << pNames[i] << " busts and cannot win!" << endl;
            tWngs[nPlyrs] += pBets[i];
            winnrs[nPlyrs] = "Dealer";
        } else if (dTotal > MAX_SCORE || pTotals[i] > dTotal) {
            cout << pNames[i] << " wins!" << endl;
            recWin(outFile, pNames, hands, pTotals, i, pNames[i]);
            tWngs[i] += pBets[i] * (nPlyrs + 1);
            pBlns[i] += pBets[i] * nPlyrs;
            winnrs[i] = pNames[i];
            players[i].wnngs = pBets[i] * (nPlyrs + 1);

            if (pTotals[i] > bTotal) {
                bTotal = pTotals[i];
                bPlyr = pNames[i];
            }
        } else if (dTotal > pTotals[i]) {
            cout << "Dealer wins against " << pNames[i] << "!" << endl;
            recWin(outFile, pNames, hands, pTotals, i, "Dealer");
            tWngs[nPlyrs] += pBets[i];
            winnrs[nPlyrs] = "Dealer";
        } else {
            cout << "It's a tie for " << pNames[i] << "!" << endl;
            recWin(outFile, pNames, hands, pTotals, i, "Tie");
            winnrs[i] = pNames[i];
        }

        if (bTotal > 0)
            cout << "Best Player: " << bPlyr << " Score: " << bTotal << endl;
    }

    // Record dealer's final hand
    recWin(outFile, pNames, hands, pTotals, nPlyrs, "Dealer");

    // Close the card.dat file
    outFile.close();

    // Show Leaderboard
    showLead(players, nPlyrs);

    // Sort player totals using bubble sort
    bubbleSort(players);

    // Display sorted player totals
    cout << "\nSorted Player Totals (Bubble Sort):" << endl;
    for (int i = 0; i < nPlyrs; ++i) {
        cout << players[i].name << ": " << players[i].total << endl;
    }

    // Sort player wnngs using selection sort
    selectionSort(players);

    // Display sorted wnngs
    cout << "\nSorted Player Winnings (Selection Sort):" << endl;
    for (int i = 0; i < nPlyrs; ++i) {
        cout << players[i].name << ": " << players[i].wnngs << " points" << endl;
    }

    // Display player balances
    for (int i = 0; i < nPlyrs; ++i) {
        cout << pNames[i] << "'s balance: " << pBlns[i] << endl;
    }
    // Search for a player by name
    string srchNm;
    cout << "\nEnter player name to search: ";
    cin.ignore();
    getline(cin, srchNm);
    int srchIdx = linearSearch(pNames, srchNm);

    if (srchIdx != -1) {
        cout << srchNm << " found with total: " << pTotals[srchIdx] << endl;
    } else {
        cout << srchNm << " not found." << endl;
    }

    return 0;
}

// Static variable to count number of cards dealt
static int cardCount = 0;

// Get a random card value
int getCard() {
    cardCount++;
    // get a random card
    int card = rand() % 13 + 1;

    // all face cards get value 10
    if (card > 10) return 10;

    // Ace gets value 11
    if (card == 1) return 11;

    // return card value otherwise
    return card;
}

// Overloaded function to get a random card value with a mplier
int getCard(int mplier) {
    cardCount++;
    int card = (rand() % 13 + 1) * mplier;

    if (card > 10 * mplier) return 10 * mplier;
    if (card == 1 * mplier) return 11 * mplier;

    return card;
}

// Get a random card suit
string getSuit() {
    // get a random suite
    int suit = rand() % 4;
    switch (suit) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
    }
    return "";
}

// Update file with card details
void updFile(ofstream &file, const string &plyr, int val, const string &suit) {
    file << plyr << ": " << val << " of " << suit << endl;
}

// Record the winner in the file
void recWin(ofstream &file, const vector<string> &pNames, int hands[][MAX_CARDS], int pTotals[], int idx, const string &wnr) {
    if (file.is_open()) {
        // Write the accumulated hand for the player or dealer
        if (idx < pNames.size()) {
            file << pNames[idx] << ": ";
        } else {
            file << "Dealer: ";
        }

        for (int i = 0; i < MAX_CARDS; ++i) {
            if (hands[idx][i] == 0) break;
            file << hands[idx][i] << " ";
        }

        file << "\nTotal: " << pTotals[idx] << endl;
        file << "Winner: " << wnr << endl;
    } else {
        ofstream outFile("card.dat", ios::app);
        if (idx < pNames.size()) {
            outFile << pNames[idx] << ": ";
        } else {
            outFile << "Dealer: ";
        }

        for (int i = 0; i < MAX_CARDS; ++i) {
            if (hands[idx][i] == 0) break;
            outFile << hands[idx][i] << " ";
        }

        outFile << "\nTotal: " << pTotals[idx] << endl;
        outFile << "Winner: " << wnr << endl;
        outFile.close();
    }
}

// Validate user input for hit or stand
void valInput(char &choice) {
    while (cin.fail() || (choice != 'h' && choice != 'H' && choice != 's' && choice != 'S')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 'h/H' to hit or 's/S' to stand: ";
        cin >> choice;
    }
}

// Update hands in array
void updHand(int hands[][MAX_CARDS], int pTotals[], int idx, int cardIdx, int crd, vector<string> &hSuits, const string &suit) {
    if (idx >= MAX_PLAYERS + 1 || cardIdx >= MAX_CARDS) {
        cout << "Index out of bounds. Skipping hand update." << endl;
        return;
    }
    hands[idx][cardIdx] = crd;
    pTotals[idx] += crd;

    if (hSuits[idx].empty()) {
        hSuits[idx] = to_string(crd) + " of " + suit;
    } else {
        hSuits[idx] += ", " + to_string(crd) + " of " + suit;
    }
}

// Validate bet input
void valBet(int &bet) {
    while (cin.fail() || bet <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid bet amount. Please enter a positive number: ";
        cin >> bet;
    }
}

// Display the leaderboard
void showLead(const vector<Player> &players, int nPlyrs) {
    cout << "\nLeaderboard:" << endl;
    for (int i = 0; i < nPlyrs; ++i) {
        if (!players[i].name.empty()) {
            cout << players[i].name << ": " << players[i].wnngs << " points" << endl;
        }
    }
}

// Exit function with a message
void exitMsg(const string &msg) {
    cout << msg << endl;
    exit(1);
}

// Bubble sort for player scores
void bubbleSort(vector<Player> &players) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < players.size() - 1; ++i) {
            if (players[i].total < players[i + 1].total) {
                swap(players[i], players[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

// Selection sort for player wnngs
void selectionSort(vector<Player> &players) {
    for (size_t i = 0; i < players.size() - 1; ++i) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < players.size(); ++j) {
            if (players[j].wnngs > players[maxIdx].wnngs) {
                maxIdx = j;
            }
        }
        swap(players[i], players[maxIdx]);
    }
}

// Linear search for player names
int linearSearch(const vector<string> &names, const string &target) {
    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}
