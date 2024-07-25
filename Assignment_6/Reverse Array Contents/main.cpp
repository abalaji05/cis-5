/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created: Jul 22, 2024
 * Purpose:  Reverse the Array
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void  init(int [],int);//Initialize the array
void  print(int [],int,int);//Print the array
void  revrse(int [],int);;//Reverse the array


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int SIZE=50;
    int test[SIZE];
    
    //Initialize or input i.e. set variable values
    init(test,SIZE);
    
    //Reverse the Values
    revrse(test,SIZE);
    
    //Display the outputs
    print(test,SIZE,10);

    //Exit stage right or left!
    return 0;
}

void init(int arr[], int size) {
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];    
    }
}

void print(int arr[], int size, int rsize) {
    
    int rows;
    
    if (size%rsize == 0) 
        rows = size / rsize;
    else
        rows = size / rsize + 1;
    
    for (int row = 0; row < rows; row++) {
        int spos = 0;
        
        if (row > 0)
            spos = row  * rsize;
        
        for (int i = 0; i < rsize; i++ ){
            cout << arr[i+spos] << " ";
        }
        cout <<endl;
    }
}

void revrse(int arr[], int size) {
    
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}