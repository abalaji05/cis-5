/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <math.h>    //Math/Library
#include <iomanip>  //Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float PI = 3.14159;
    int angle;
    float sine;
    float cosine;
    float tang;
    //Initialize or input i.e. set variable values
    cout<<"Calculate trig functions"<<endl;
    cout<<"Input the angle in degrees."<<endl;
    cin>>angle;
    //Map inputs -> outputs
    sine = sin(angle*PI/180.0);
    cosine = cos(angle*PI/180.0);
    tang = tan(angle*PI/180.0);
    //Display the outputs
    cout<<fixed;
    cout<<"sin("<<angle<<") = "<<setprecision(4)<<sine<<endl;
    cout<<"cos("<<angle<<") = "<<setprecision(4)<<cosine<<endl;
    cout<<"tan("<<angle<<") = "<<setprecision(4)<<tang;
    //Exit stage right or left!
    return 0;
}
