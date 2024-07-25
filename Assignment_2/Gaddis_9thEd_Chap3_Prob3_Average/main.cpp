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
    float a,b,c,d,e;
    float avg;
    
    //Initialize or input i.e. set variable values
    cout<<"Input 5 numbers to average."<<endl;
    cin>> a >> b >> c >> d >> e;
    
    
    //Map inputs -> outputs
    avg = (a+b+c+d+e)/5;
    
    cout<<fixed;
    //Display the outputs
    cout<<"The average = "<<setprecision(1)<< avg;
    //Exit stage right or left!
    return 0;
}