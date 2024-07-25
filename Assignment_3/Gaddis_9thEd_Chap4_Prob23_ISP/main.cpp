/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
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
    char package;
    signed short int hours;
    float charges = 0.0;
    bool condition = true;
    
    //Initialize or input i.e. set variable values
    cout << "ISP Bill" <<endl;
    cout << "Input Package and Hours" << endl;
    
    while (condition) {
        cin >> package >> hours;
        if (package == 'A' || package == 'B' || package == 'C')
            condition = false;
        else
            cout << "Select from Package A,B,C."<<endl;
        if (hours <= 744)
            condition = false;
        else
            cout << "Hours used in a month cannot exceed 744."<<endl;
    }
    
    // Calculate monthly charges
    switch (package) {
        case 'A':
            if (hours <= 10)
                charges = 9.95;
            else
                charges = 9.95 + 2.00 *(hours-10);
            break;
        case 'B':
            if (hours <= 20)
                charges = 14.95; 
            else
                charges = 14.95 + 1.00 *(hours-20);
            break;
 
        case 'C':
            charges = 19.95;
    }
    
    cout << fixed;
    cout << "Bill = $"<< setprecision(2)<<setw(6)<< charges;

    //Exit stage right or left:
}