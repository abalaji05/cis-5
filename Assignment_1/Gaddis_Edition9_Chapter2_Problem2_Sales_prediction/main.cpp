/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Sales Prediction  
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
    float total_sales;
    float east_coast_sales;
    
    
    //Initialize Variables
    total_sales = 8600000;
    
    
    //Map/Process the Inputs -> Outputs
    east_coast_sales = total_sales * 0.58;
    
    
    //Display Inputs/Outputs
    cout<<"East Coast Sales = " << east_coast_sales << endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}