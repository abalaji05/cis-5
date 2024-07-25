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
const float LTG = 0.264179;

//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float MPG(float lgas,float milest){
    float mpg;
    
    mpg = milest / (lgas * LTG);
    
    return mpg;
    
}


//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float lgas;
    float milest;
    float mpg;
    char choice;
    
    cout << fixed;
    
    //Initialize or input i.e. set variable values
    choice='y';
    while (choice == 'y') {
        cout<<"Enter number of liters of gasoline:"<<endl<<endl;
        cin>>lgas;
        cout<<"Enter number of miles traveled:"<<endl<<endl;
        cin>>milest;
        mpg = MPG(lgas,milest);
        cout<<"miles per gallon:"<<endl;
        cout<<setprecision(2)<<mpg<<endl;
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