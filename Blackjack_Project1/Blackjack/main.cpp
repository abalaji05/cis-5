/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created: 7/21/2024
 * Purpose:  Blackjack game
 * 
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int MAX_SCORE = 21;
const int DEALER_LIMIT = 17;
const int MIN_PLAYERS = 1;
const int MAX_PLAYERS = 8;

// Function Prototypes
int getCard();          // Get a random card value
string getSuit();       // Get a random card suit
void updFile(ofstream&, string, int, string = "Unknown"); // Update file with card details
void updHand(string[], int,  int, string);
void recWin(ofstream&, string[], string[], int, string); // Record the winner in the file
void valInput(char&);    // Validate user input for hit or stand
void valBet(int&);       // Validate bet input
void showLead(string[], int[], int); // Display the leaderboard
void exitMsg(const string& msg); // Exit function with a message

//Execution Begins Here!
int main() {
    // Declare Variables
    int numPlyrs;
    string pNames[MAX_PLAYERS];
    int plyrBts[MAX_PLAYERS];
    int plyrBlns[MAX_PLAYERS] = {0}; // Player balances initialized to 0
    int ttlWngs[MAX_PLAYERS + 1] = {0}; // Total winnings (last index for dealer)
    string winners[MAX_PLAYERS + 1]; // Names of winners

    int plyrTls[MAX_PLAYERS] = {0};
    int dlrTtl;

    int dlrCrd1, dlrCrd2;
    string dlrSut1, dlrSut2;
    
    static string hands[MAX_PLAYERS + 1]; // +1 for the dealer

    srand(static_cast<unsigned int>(time(0)));

    ofstream outFile("card.dat", ios::app);
    if (!outFile.is_open()) {
        exitMsg("Error opening file!");
    }

    while (true) {
        cout << "Enter number of players (1-8): ";
        cin >> numPlyrs;
        
        // Check if the input is an integer
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
        } else if (numPlyrs < MIN_PLAYERS || numPlyrs > MAX_PLAYERS) {
            cout << "Invalid number of players. Enter a number between 1 and 8." << endl;
        } else {
            break;  // Valid input
        }
    }
    
    for (int i = 0; i < numPlyrs; ++i) {
        cout << "Enter player " << i + 1 << "'s name: ";
        cin.ignore();
        getline(cin, pNames[i]);
        cout << "Enter bet amount for " << pNames[i] << ": ";
        cin >> plyrBts[i];
        valBet(plyrBts[i]);
        
        hands[i] = "";
    }
    
    for (int i = 0; i < numPlyrs; ++i) {
        // Deal two cards to each player
        for (int j = 0; j < 2; ++j) {
            int crd = getCard();
            string sut = getSuit();
           
            updHand(hands, i, crd, sut);
            plyrTls[i] += crd; // Sum the card values for the player's total
        }
        cout << pNames[i] << "'s Hand : " << hands[i] << endl;
    }


    // Initial card dealing for the dealer
    dlrCrd1 = getCard();
    dlrSut1 = getSuit();
    updHand(hands, numPlyrs, dlrCrd1, dlrSut1);

    dlrCrd2 = getCard();
    dlrSut2 = getSuit();
    updHand(hands, numPlyrs, dlrCrd2, dlrSut2);

    dlrTtl = dlrCrd1 + dlrCrd2;
    cout << "Dealer's Hand: " << hands[numPlyrs] << endl;

    // Player's Turn: Each player can hit or stand
    for (int i = 0; i < numPlyrs; ++i) {
        char choice;
        do {
            cout << pNames[i] << "'s total: " << plyrTls[i] << endl;
            cout << "Do you want to hit (h/H) or stand (s/S)? ";
            cin >> choice;
            valInput(choice);

            if (choice == 'h' || choice == 'H') {
                int newCrd = getCard();
                string newSut = getSuit();
                plyrTls[i] += newCrd;
                cout << "You got " << newCrd << " of " << newSut << endl;
                updHand(hands, i, newCrd, newSut);

                if (plyrTls[i] > MAX_SCORE) {
                    cout << pNames[i] << " busts with total: " << plyrTls[i] << endl;
                    break;
                }
            }
        } while (choice == 'h' || choice == 'H');
    }

    // Dealer's Turn: Dealer hits until reaching DEALER_LIMIT
    while (dlrTtl < DEALER_LIMIT) {
        int newCrd = getCard();
        string newSut = getSuit();
        dlrTtl += newCrd;
        cout << "Dealer got " << newCrd << " of " << newSut << endl;
        updHand(hands, numPlyrs, newCrd, newSut);
    }

    cout << "Dealer's total: " << dlrTtl << endl;

    string bstPlyr = "";
    int bstTotl = 0;

    // Determine winners
    for (int i = 0; i < numPlyrs; ++i) {
        int plyrDif = abs(plyrTls[i] - MAX_SCORE);
        int dlrDif = abs(dlrTtl - MAX_SCORE);

        //cout << pNames[i] << "'s abs diff from 21: " << plyrDif << endl;
        //cout << "Dealer's abs diff from 21: " << dlrDif << endl;

        if (plyrTls[i] > MAX_SCORE) {
            cout << pNames[i] << " busts and cannot win!" << endl;
            ttlWngs[numPlyrs] += plyrBts[i]; // Dealer wins the bet
            winners[numPlyrs] = "Dealer";
        } 

        else if (dlrTtl > MAX_SCORE || plyrTls[i] > dlrTtl) {
            cout << pNames[i] << " wins!" << endl;
            recWin(outFile, hands, pNames, i, pNames[i]);
            ttlWngs[i] += plyrBts[i] * (numPlyrs + 1); // Player gains bets from all players and dealer
            plyrBlns[i] += plyrBts[i] * numPlyrs; // Calculate player balance after win
            winners[i] = pNames[i];
            
            if (plyrTls[i] > bstTotl) {
                bstTotl = plyrTls[i];
                bstPlyr = pNames[i];
            }
        } 

        else if (dlrTtl > plyrTls[i]) {
            cout << "Dealer wins against " << pNames[i] << "!" << endl;
            recWin(outFile, hands, pNames, i, "Dealer");
            ttlWngs[numPlyrs] += plyrBts[i]; // Dealer wins the bet
            winners[numPlyrs] = "Dealer";
        } 

        else {
            cout << "It's a tie for " << pNames[i] << "!" << endl;
            recWin(outFile, hands, pNames, i, "Tie");
            winners[i] = "Tie";
        }

        if (bstTotl > 0)
            cout << "Best Player : " << bstPlyr << " Score :" << bstTotl<<endl;
    }

    // Record dealer's final hand
    recWin(outFile, hands, pNames, numPlyrs, "Dealer");

    // close the card.dat file
    outFile.close();

    // Show Leaderboard
    showLead(winners, ttlWngs, numPlyrs);

    // Display player balances
    for (int i = 0; i < numPlyrs; ++i) {
        cout << pNames[i] << "'s bal: " << plyrBlns[i] << endl;
    }

    return 0;
}

// Get a random card value
int getCard() {

    // get a random card
    int card = rand() % 13 + 1;

    // all face cards get value 10
    if (card > 10) return 10;

    // Ace gets value 11
    if (card == 1) return 11;

    // return card value otherwise
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
void updFile(ofstream &file, string plyr, int val, string suit) {
    file << plyr << ": " << val << " of " << suit << endl;
}

// Record the winner in the file
void recWin(ofstream &file, string hands[], string pNames[], int idx, string wnr) {
    if (file.is_open()) {
        // Write the accumulated hand for the player or dealer
        if (idx < MAX_PLAYERS) {
            file << pNames[idx] << ": " << hands[idx] << endl;
        } else {
            file << "Dealer: " << hands[idx] << endl;
        }
        file << "Winner: " << wnr << endl;
    } else {
        ofstream outFile("card.dat", ios::app);
        if (idx < MAX_PLAYERS) {
            outFile << pNames[idx] << ": " << hands[idx] << endl;
        } else {
            outFile << "Dealer: " << hands[idx] << endl;
        }
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
void updHand(string hands[], int idx, int crd, string suit) {
    // Construct card detail string
    
    string cardDetail = to_string(crd) + " of " + suit;

    // Update the hand in the array for display
    if (hands[idx].empty()) {
        hands[idx] = cardDetail;
    } 
    
    else {
        hands[idx] += ", " + cardDetail;
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
void showLead(string winners[], int ttlWngs[], int numPlyrs) {
    cout << "\nLeaderboard:" << endl;
    for (int i = 0; i <= numPlyrs; ++i) {
        if (!winners[i].empty()) {
            cout << winners[i] << ": " << ttlWngs[i] << " points" << endl;
        }
    }
}

// Exit function with a message
void exitMsg(const string& msg) {
    cout << msg << endl;
    exit(1);
}

