/* 
 * File:   
 * Author: akshay balaji
 * Created on 
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
float calc_inflation(float oldp ,float newp ){
    float infl;
    
    infl = ((newp-oldp)/(oldp))*(100.0);
    
    
    return infl;
    
}


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float oldp;
    float newp;
    float infl;
    char choice;
    
    cout << fixed;
    
    //Initialize or input i.e. set variable values
    choice='y';
    while (choice == 'y') {
        cout<<"Enter current price:"<<endl;
        cin>>newp;
        cout<<"Enter year-ago price:"<<endl;
        cin>>oldp;
        infl = calc_inflation(oldp,newp);
        cout<<"Inflation rate: "<<setprecision(2)<<infl<<"%"<<endl<<endl;
        

        
    
        
        cout<<"Again:"<<endl;
        cin>>choice;
        if (choice != 'n')
        cout << endl;
    }
    

    
    //Map inputs -> outputs
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}