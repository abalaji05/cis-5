/*
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created on: 22 July 2024
 * Purpose:  Binary Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [], int);
void prntAry(int [], int, int);
void selSrt(int [], int);
bool binSrch(int [], int, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 100;
    int array[SIZE];
    int indx;
    int val;
    
    //Initialize or input i.e. set variable values
    fillAry(array, SIZE);

    //Sorted List
    selSrt(array, SIZE);
    
    //Display the outputs
    prntAry(array, SIZE, 10);
    cout << "Input the value to find in the array" << endl;
    cin >> val;
    if(binSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
    else
        cout << val << " was not found in the array" << endl;

    //Exit stage right or left!
    return 0;
}

void fillAry(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void prntAry(int array[], int size, int perLine) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
        if ((i % perLine) == (perLine - 1)) cout << endl;
    }
    cout << endl;
}

void selSrt(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        swap(array[i], array[minIdx]);
    }
}

bool binSrch(int array[], int size, int val, int &indx) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == val) {
            indx = mid;
            return true;
        } else if (array[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
