/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
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
    int num;
    bool c;
    int sum;
    int i;
    c = true;
    
        
    //Initialize or input i.e. set variable values
    while (c){
        cin>>num;
        if (num>0)
            c = false;
    }
    
    sum = 0;
    
    //Map inputs -> outputs
    for (i=1;i<=num;i++){
        sum += i;
    }
    //Display the outputs
    cout<<"Sum = "<<sum;
    

    //Exit stage right or left!
    return 0;
}