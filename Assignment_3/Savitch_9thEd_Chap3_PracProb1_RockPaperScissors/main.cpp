/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char choice1, choice2;
    bool condition = true;
    
    
    //Initialize or input i.e. set variable values
    cout <<"Rock Paper Scissors Game"<< endl;
    cout << "Input Player 1 and Player 2 Choices" <<endl;
    
    while (condition) {
        cin >> choice1 >> choice2;
        
        if (choice1 == 'P' || choice1 == 'p' || choice1 == 'R' || choice1 == 'r' || choice1 == 'S' || choice1 == 's')
            condition = false;
        if (choice2 == 'P' || choice2 == 'p' || choice2 == 'R' || choice2 == 'r' || choice2 == 'S' || choice2 == 's')
            condition = false;
        
    }
    
    //Map inputs -> outputs
    
    //Display the outputs
    if (((choice1 == 'P' || choice1 == 'p') && (choice2 == 'R' || choice2 == 'r')) ||
        ((choice2 == 'P' || choice2 == 'p') && (choice1 == 'R' || choice1 == 'r')))
        cout << "Paper covers rock.";
    else if (((choice1 == 'R' || choice1 == 'r') && (choice2 == 'S' || choice2 == 's')) ||
        ((choice2 == 'R' || choice2 == 'r') && (choice1 == 'S' || choice1 == 's')))
        cout << "Rock breaks scissors.";
    else if (((choice1 == 'P' || choice1 == 'p') && (choice2 == 'S' || choice2 == 's')) ||
        ((choice2 == 'P' || choice2 == 'p') && (choice1 == 'S' || choice1 == 's')))
        cout << "Scissors cuts paper.";
    else
        cout << "Nobody wins.";
    

    //Exit stage right or left!
    return 0;
}