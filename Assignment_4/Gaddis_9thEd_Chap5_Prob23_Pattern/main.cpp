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
    int i;
    int j;
    int num;
    
    
    //Initialize or input i.e. set variable values
    cin>>num;
    //Map inputs -> outputs
    
    //Display the outputs
    for(i=1;i<=num;i++){
        
        for(j=0;j<i;j++){
            cout<<"+";
        }
        
        cout<<endl;
        
        cout<<endl;
    
    }

    for(i=num;i>0;i--){
        
        for(j=0;j<i;j++){
            cout<<"+";
        }
        
        if (i !=  1){
        cout<<endl;
        cout<<endl;
        }
       
       
       
    }
    
    //Exit stage right or left!
    return 0;
}