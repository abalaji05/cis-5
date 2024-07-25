/* 
 * Author: Akshay Balaji
 * Created on 7/20/2024 6 p.m.
 * Purpose:  To find factorial for a given integer number
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int fctrl(int);//Function to write for this problem

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int number;
    int value;
    
    //Initialize Variables
    cout << "This program calculates the factorial using a function prototype found in the template for this problem."<< endl;
    cout << "Input the number for the function." << endl;

    cin >> number;
    
    //Process/Map inputs to outputs
    value = fctrl(number);
    
    //Output data
    cout << number<<"! = " << value;
    
    //Exit stage right!
    return 0;
}

int fctrl(int n) {
    int value = 1.0;
    if (n ==0) return value;

    for (int i=1; i<=n; ++i)
        value *= i;

    return value;
    
}