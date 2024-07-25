/*
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created on: 22 July 2024
 * Purpose: Standard Deviation
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
const float MAXRAND = pow(2, 31) - 1;

//Function Prototypes
void init(float[], int);          //Initialize the array
void print(float[], int, int);    //Print the array
float avgX(float[], int);         //Calculate the Average
float stdX(float[], int);         //Calculate the standard deviation

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    //srand(static_cast<unsigned>(time(0)));

    //Declare Variables
    const int SIZE = 20;
    float test[SIZE];

    //Initialize or input i.e. set variable values
    init(test, SIZE);

    //Display the outputs
    //print(test, SIZE, 5);
    cout << fixed;
    cout << "The average            = " << setprecision(7) << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << setprecision(7) << stdX(test, SIZE) << endl;

    //Exit stage right or left!
    return 0;
}

void init(float array[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print(float array[], int size, int perLine) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(7) << array[i] << " ";
        if ((i + 1) % perLine == 0) cout << endl;
    }
}

float avgX(float array[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

float stdX(float array[], int size) {
    float mean = avgX(array, size);
    float sumSqDiff = 0;
    for (int i = 0; i < size; i++) {
        sumSqDiff += pow(array[i] - mean, 2);
    }
    return sqrt(sumSqDiff / (size - 1));
}
