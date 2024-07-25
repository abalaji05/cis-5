/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   // Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float pinc;
    unsigned short rm = 6;
    float las; //last annual salary
    float nas; // new annual salary
    float rp; // amount of retroactive pay
    float lms; // last monthly salary
    float nms; // new monthly salary
    
    //Initialize or input i.e. set variable values
    pinc = 0.076;
    cout << "Input previous annual salary."<<endl;
    cin >> las;
    
    
    //Map inputs -> outputs
    nas = las * (1 + pinc);
    lms = las / 12.0;
    nms = nas / 12.0;
    rp = (nms - lms) * 6.0;
    
    //Display the outputs
    cout << fixed;
    cout << "Retroactive pay    "<<"= $"<<setprecision(2)<<setw(7)<<rp<<endl;
    cout << "New annual salary  "<<"= $"<<setprecision(2)<<setw(7)<<nas<<endl;
    cout << "New monthly salary "<<"= $"<<setprecision(2)<<setw(7)<<nms;

    //Exit stage right or left!
    return 0;
}