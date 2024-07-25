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
const float CNVLBKG=45359.2/100.0f;//grams in 100lbs

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float wd,md; //weight and mass of dieter in lbs and grams
    float mm; //mass of mouse
    float mk; //mass of sweetener which exterminates the mouse
    float mkd;//mass of sweetener which exterminates the dieter
    float mc; //mass of the contents of the diet coke can
    float sc; // soda can concentration
    float mscc; // mass of sweetener in a can of coke
    unsigned short nCans; // number of cans of coke
    
    mm = 35;
    mk = 5;
    mc=350;
    sc=0.01/10; //sweetener concentration in a can of coke
    cout << "Program to calculate the limit of Soda Pop Consumption." <<endl;
    cout<<"Input the desired dieters weight in lbs."<<endl;
    cin>>wd;
    
    //Map inputs -> outputs
    md = wd*CNVLBKG; // mass of dieter converted from their wweight
    mkd = md * mk / mm; // mass of sweetener the diehat exterminates the dieter
    mscc = mc * sc; // mass of sweetener in a can of coke
    nCans = mkd / mscc;  // Number of cans not to consume
    
    //Display the outputs
    cout<<"The maximum number of soda pop cans"<<endl;
    cout << "which can be consumed is " << nCans << " cans";
    
    return 0;
}
