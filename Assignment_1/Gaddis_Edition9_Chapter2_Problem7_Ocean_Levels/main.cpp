/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Ocean Levels
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
    float ocean_level_rate;
    float ocean_level5;
    float ocean_level7;
    float ocean_level10;
    
   
    
    //Initialize Variables
    ocean_level_rate = 1.5;
    
    
    //Map/Process the Inputs -> Outputs
    ocean_level5 = ocean_level_rate * 5;
    ocean_level7 = ocean_level_rate * 7;
    ocean_level10 = ocean_level_rate *10;
    
    //Display Inputs/Outputs
    cout<<"In 5 years ocean level will rise = " << ocean_level5 << "mm" << endl;
    cout<<"In 7 years ocean level will rise = " << ocean_level7 << "mm" << endl;
    cout<<"In 10 years ocean level will rise = " << ocean_level10 << "mm" << endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}