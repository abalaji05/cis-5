/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int nbooks;
    int points;
    //Initialize or input i.e. set variable values
    cout<<"Book Worm Points"<<endl;
    cout<<"Input the number of books purchased this month."<<endl;
    cin>>nbooks;
    
    switch (nbooks)
    {
        case 0:
            points = 0;
            break;
        case 1 :
            points = 5;
            break;
        case 2:
            points = 15;
            break;
        case 3:
            points = 30;
            break;
        default:
            points = 60;
    }
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout<<"Books purchased ="<<setw(3)<<nbooks<<endl;
    cout<<"Points earned   ="<<setw(3)<<points;

    //Exit stage right or left!
    return 0;
}