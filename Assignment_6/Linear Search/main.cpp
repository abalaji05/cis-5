/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created on: 22 July 2024
 * Purpose:  Linear Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int);
bool linSrch(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    //srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val=50; // Value to search for is set to 50
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);
    
    //Perform the linear search and display the result
    if(linSrch(array,SIZE,val,indx))
        cout << val << " was found at indx = " << indx << endl;
    else
        cout << val << " was not found in the array." << endl;
    
    //Exit stage right or left!
    return 0;
}

//Function to fill array with user input values
void fillAry(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

//Linear search function
bool linSrch(int array[], int size, int val, int &indx) {
    for(int i = 0; i < size; i++) {
        if(array[i] == val) {
            indx = i;
            return true;
        }
    }
    return false;
}
