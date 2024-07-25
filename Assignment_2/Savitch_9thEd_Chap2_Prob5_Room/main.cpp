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
    unsigned short mrc; //maximum room capacity
    unsigned short pa; //people attending
    unsigned short ap; // additional people that can attend 
    unsigned short ep; // number of people that have exceeded
    
    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people"<<endl;
    cin >> mrc >> pa;
    
    ap = mrc - pa;
    ep = pa - mrc;
    
    //Map inputs -t> outputs
    if (pa <= mrc) {
        cout << "Meeting can be held."<<endl;
        cout << "Increase number of people by "<< ap << " will be allowed without violation.";
    }
    else {
        cout << "Meeting cannot be held."<<endl;
        cout << "Reduce number of people by "<< ep << " to avoid fire violation.";
    }
    //Display the outputs

    //Exit stage right or left!

    return 0;
}