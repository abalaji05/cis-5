/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Average Value
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    float average_value;
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int sum;
    
    //Initialize Variables
    num1 = 28;
    num2 = 32;
    num3 = 37;
    num4 = 24;
    num5 = 33;
    sum = num1 + num2 +num3 +num4 +num5;
    
    
    
    //Map/Process the Inputs -> Outputs
    average_value = sum/5.0;
    
    
            
    
    //Display Inputs/Outputs
    cout<<"Avg = " << average_value <<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}