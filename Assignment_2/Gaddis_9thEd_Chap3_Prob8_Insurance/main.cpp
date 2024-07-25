/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables
    float replacementcost;
    float insuredcost;
    //Initialize or input i.e. set variable values
    cout<<"Insurance Calculator"<<endl;
    cout<<"How much is your house worth?"<<endl;
    cin>>replacementcost;
    
    //Map inputs -> outputs
    insuredcost = 0.8*replacementcost;
    //Display the outputs
    cout<<"You need $"<<insuredcost<<" of insurance.";
    //Exit stage right or left!
    return 0;
}