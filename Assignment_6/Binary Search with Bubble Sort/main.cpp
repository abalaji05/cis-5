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
void bublSrt(int [], int);
bool binSrch(int [], int, int, int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 100;
    int array[SIZE];
    int indx, val;
    
    //Initialize or input i.e. set variable values
    fillAry(array, SIZE);

    //Sorted List
    bublSrt(array, SIZE);
    
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

void fillAry(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void prntAry(int a[], int n, int perLine) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
        if((i + 1) % perLine == 0) cout << endl;
    }
    cout << endl;
}

void bublSrt(int a[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

bool binSrch(int a[], int n, int val, int &indx) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] == val) {
            indx = mid;
            return true;
        } else if(a[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
