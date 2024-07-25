/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float payrate;
    float gross;
    float hours;
    int stdhour;
    //Initialize or input i.e. set variable values
    stdhour = 40;
    
    //Map inputs -> outputs
    cout<<"This program calculates the gross paycheck."<<endl;
    cout<<"Input the pay rate in $'s/hr and the number of hours."<<endl;
    cin>>payrate>>hours;
    
    if (hours>stdhour)
        gross = (hours-stdhour) *payrate *2.0+ stdhour*payrate;
    else
        gross = hours*payrate;
    //Display the outputs
    cout<<fixed;
    cout<<"Paycheck = $ "<<setprecision(2)<<gross;
    //Exit stage right or left!
    return 0;
}
