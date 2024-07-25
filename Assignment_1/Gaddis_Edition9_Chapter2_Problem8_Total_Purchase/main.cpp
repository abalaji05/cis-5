/* 
 * File:   main.cpp
 * Author: abalaji
 * Created on June 25, 2024
 * Purpose: Total Purchase
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
    float price1;
    float price2;
    float price3;
    float price4;
    float price5;
    float subtotal;
    float salestax;
    float total;
    float taxrate;
    
    
   
    
    //Initialize Variables
    price1 = 15.95;
    price2 = 24.95;
    price3 = 6.95;
    price4 = 12.95;
    price5 = 3.95;
    taxrate = 0.07;
    
    
    //Map/Process the Inputs -> Outputs
    subtotal = price1 + price2 + price3 + price4 + price5;
    salestax = subtotal * taxrate;
    total = subtotal + salestax;
    
    
    //Display Inputs/Outputs
    cout<<"Price of item 1 = $" << price1 <<endl;
    cout<<"Price of item 2 = $" << price2 <<endl;
    cout<<"Price of item 3 = $" << price3 <<endl;
    cout<<"Price of item 4 = $" << price4 <<endl;
    cout<<"Price of item 5 = $" << price5 <<endl;
    cout<<"Subtotal = $" << subtotal <<endl;
    cout<<"Sales tax = $" << salestax <<endl;
    cout<<"Total = $" << total <<endl;

    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}