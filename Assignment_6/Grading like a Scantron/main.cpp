/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created on: 22 July 2024
 * Purpose: Compare the answer sheet to the key and grade
 */

// System Libraries
#include <iostream>  // Input/Output Library
#include <string>    // String Library
#include <sstream>   // For stringstream
using namespace std;

// User Libraries

// Global Constants, no Global Variables are allowed
// Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

// Function Prototypes
void print(const string &);
void read(const char [], string &);
int compare(const string &, const string &, string &);

// Execution Begins Here!
int main(int argc, char** argv) {
    // Declare Variables
    string key, answers, score;
    float pRight;

    // Initialize or input i.e. set variable values
    read("key", key);
    read("answers", answers);
    
    // Score the exam
    pRight = compare(key, answers, score);
    
    // Display the outputs
    cout << "C/W     "; print(score);
    cout << "Percentage Correct = " << pRight / score.size() * 100 << "%" << endl;
    
    // Exit stage right or left!
    return 0;
}

void print(const string &values) {
    for (char ch : values) {
        cout << ch << " ";
    }
    cout << endl;
}

void read(const char prompt[], string &values) {
    string temp;
    getline(cin, temp);

    // Find the position of the first space after "key" or "answers"
    size_t pos = temp.find(' ');
    if (pos != string::npos) {
        // Extract the actual values from the string
        string actualValues = temp.substr(pos + 1);

        // Process the input to remove extra spaces and tabs
        stringstream ss(actualValues);
        string word;
        values.clear();
        while (ss >> word) {
            values += word;
        }
    }
}

int compare(const string &key, const string &answers, string &score) {
    int correct = 0;
    for (size_t i = 0; i < key.size(); ++i) {
        if (key[i] == answers[i]) {
            score += 'C';
            correct++;
        } else {
            score += 'W';
        }
    }
    return correct;
}
