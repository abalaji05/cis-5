/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Restaurant Bill
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
    float tip;
    float tax;
    float meal_charge;
    float tax_rate;
    float tip_rate;
    float total;
    
    
    //Initialize Variables
    meal_charge = 88.67;
    tax_rate = 0.0675;
    tip_rate = 0.2;
    
    
    //Map/Process the Inputs -> Outputs
    tax = tax_rate * meal_charge;
    tip = tip_rate * (meal_charge + tax_rate);
    total = tip + tax + meal_charge;
    
            
    
    //Display Inputs/Outputs
    cout<<"Meal Cost = $" << meal_charge <<endl;
    cout<<"Tax Amt = $" << tax <<endl;
    cout<<"Tip Amt = $" << tip <<endl;
    cout<<"Total = $" << total <<endl;
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}