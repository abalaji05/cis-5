/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Annual Pay
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
   float payAmount;
   float annualPay;
   int payPeriods;
   
    
    //Initialize Variables
   payAmount = 2200.0;
   payPeriods = 26;
   
    
    
    //Map/Process the Inputs -> Outputs
   annualPay = payAmount * payPeriods;
   
    
    //Display Inputs/Outputs
    cout<<"Annual Pay = $" << annualPay <<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}