/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr,Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> 
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int ndays;
    int i;
    int salary;
    int pay;
    //Initialize or input i.e. set variable values
    cin>>ndays;
    while(ndays<1)
    {
        cout<<"Invalid Entry!"<<endl;
        cout<<"Enter a number greater than or equal to 1: ";
        cin>>ndays;
            
    }

    salary = 0;
    pay = 1;
    //Map inputs -> outputs
    for(i=1;i<=ndays;i++)
    {
        salary += pay;
        pay *= 2;
        
        
    }
        
    //Display the outputs
    cout<<fixed;
    cout<<"Pay = $"<<setprecision(2)<<showpoint<<salary*0.01;

    //Exit stage right or left!
    return 0;
}