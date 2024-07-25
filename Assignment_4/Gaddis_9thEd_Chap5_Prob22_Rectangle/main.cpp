/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr,akshay balaji
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
    int i;
    char x;
    int j;

    //Initialize or input i.e. set variable values
    cin>>num>>x;
    while(num>15)
    {
        cout<<"Invalid Entry!"<<endl;
        cout<<"Enter a number lesser than or equal to 15: ";
        cin>>num>>x;
            
    }
    

    //Map inputs -> outputs
    
    //Display the outputs
    for(i=0;i<num;i++){
        for(j=0;j<num;j++)
            cout<<x;
        if(i!=num-1)
            cout<<endl;
    } 
    
    
    //Exit stage right or left!
    return 0;
}