/* 
 * File:   
 * Author: Akshay Balaji
 * Created on mm/dd/yyyy hh:mm 
 * Purpose:  Akshay Balaji Template
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>     // Math library - comment if not needed
#include <iomanip>   // Format library - comment if not needed
#include <cstring>   // String library - comment if not needed

using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float psntVal(float,float,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float pValue, fValue;
    int nYears;
    float rate;
    
    //Initialize or input i.e. set variable values
    cout << "This is a Present Value Computation"<<endl;
    
    cout << "Input the Future Value in Dollars" <<endl;
    cin >> fValue;
    cout << "Input the Number of Years" <<endl;
    cin >> nYears;
    cout << "Input the Interest Rate %/yr"<<endl;
    cin >> rate;
    
    
    //Process
    cout << fixed << setprecision(2);
    
    pValue = psntVal(fValue,rate,nYears);
    
    //Display the outputs
    
    
    cout <<"The Present Value = $"<<pValue;

    //Complete the program
    return 0;
}

float psntVal(float fValue,float rate,int nYears) {
    
    return fValue / pow((1 + rate/100), nYears);

}