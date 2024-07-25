/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring>
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
    cout<<"Race Ranking Program"<<endl;
    cout<<"Input 3 Runners"<<endl;
    cout<<"Their names, then their times"<<endl;
    string runner[3];
    signed short int rtime[3];
    signed short int i;
    
    //Initialize or input i.e. set variable values
    i = 0;
    while (i < 3) {
        cin>>runner[i]>>rtime[i];
        if (rtime[i] < 0) {
            cout <<"Time cannot be negative."<< endl; 
        }
        i++;
    }

    //Map inputs -> outputs
    
    //Display the outputs
    cout<<fixed;
    if(rtime[0]<rtime[1]){
        if(rtime[0]<rtime[2])
            cout<<runner[0]<<setw(8)<<rtime[0]<<endl;
        else if(rtime[1]<rtime[2])
            cout<<runner[1]<<setw(8)<<rtime[1]<<endl<<runner[2]<<setw(8)<<rtime[2];
        else
            cout<<runner[2]<<"\t"<<setw(3)<<rtime[2]<<endl<<runner[0]<<"\t"<<setw(3)<<rtime[0]<<endl<<runner[1]<<"\t"<<setw(3)<<rtime[1];
        
    }
    else if(rtime[0]>rtime[2]){
        if(rtime[1]<rtime[2])
            cout<<runner[1]<<setw(8)<<rtime[1]<<endl<<runner[2]<<setw(8)<<rtime[2]<<runner[0]<<setw(8)<<rtime[0];
        else
            cout<<runner[2]<<setw(8)<<rtime[2]<<endl<<runner[1]<<setw(8)<<rtime[1]<<endl<<runner[0]<<setw(8)<<rtime[0];
    }
    
    //Exit stage right or left!
    return 0;
}