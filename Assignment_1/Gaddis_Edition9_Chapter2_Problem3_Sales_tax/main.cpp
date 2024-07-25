/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Sales tax 
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
    float total_sales_tax;
    float state_tax;
    float county_tax;
    float purchase_amount;
    
    
    //Initialize Variables
    state_tax = 0.04;
    county_tax = 0.02;
    purchase_amount = 95;
    
    
    //Map/Process the Inputs -> Outputs
    total_sales_tax = purchase_amount * (county_tax + state_tax);
            
    
    //Display Inputs/Outputs
    cout<<"Total sales tax = $" << total_sales_tax <<endl;
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}