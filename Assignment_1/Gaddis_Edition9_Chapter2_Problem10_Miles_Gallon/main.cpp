/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Miles Per Gallon
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
    float milesdriven;
    float gallonsused;
    float mpg;

    
    //Initialize Variables
    milesdriven = 375;
    gallonsused = 15;
    
    //Map/Process the Inputs -> Outputs
    mpg = milesdriven/gallonsused;
    
    
    //Display Inputs/Outputs
    cout <<"MPG =  "<< mpg <<" mpg" <<endl;



    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}