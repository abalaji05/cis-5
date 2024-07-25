/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float F,C;
    
    //Initialize or input i.e. set variable values
    cout<<"Temperature Converter"<<endl;
    cout<<"Input Degrees Fahrenheit"<<endl;
    cin>>F;
    
    //Map inputs -> outputs
    C = 5.0/9.0*(F-32);
    //Displathe outputs
    cout<<fixed;
    cout<<setprecision(1)<<F<<" Degrees Fahrenheit = "<<setprecision(1)<<C<<" Degrees Centigrade";
    //Exit stage right or left!
    return 0;
}
