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
    float lgas1;
    float lgas2;
    float milest1;
    float milest2;
    float mpg1;
    float mpg2;
    char choice;
    
    cout << fixed;
    
    //Initialize or input i.e. set variable values
    choice='y';
    while (choice == 'y') {
        cout<<"Car 1"<<endl;
        cout<<"Enter number of liters of gasoline:"<<endl;
        cin>>lgas1;
        cout<<"Enter number of miles traveled:"<<endl;
        cin>>milest1;
        mpg1 = MPG(lgas1,milest1);
        cout<<"miles per gallon:"<<setprecision(2)<<setw(6)<<mpg1<<endl<<endl;
        
        
        
        cout<<"Car 2"<<endl;
        cout<<"Enter number of liters of gasoline:"<<endl;
        cin>>lgas2;
        cout<<"Enter number of miles traveled:"<<endl;
        cin>>milest2;
        mpg2 = MPG(lgas2,milest2);
        cout<<"miles per gallon:"<<setprecision(2)<<setw(6)<<mpg2<<endl<<endl;
        
        
        if (mpg1>mpg2)
            cout<<"Car 1 is more fuel efficient"<<endl<<endl;
        else
            cout<<"Car 2 is more fuel efficient"<<endl<<endl;
        
    
        
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