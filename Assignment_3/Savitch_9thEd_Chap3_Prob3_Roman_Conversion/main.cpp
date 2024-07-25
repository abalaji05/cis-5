/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring>  // String Library

using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int ayear;
    int arabic;
    int n1000,n100,n10,n1;
    string ryear ="";
    
    //Initialize or input i.e. set variable values
    cout << "Arabic to Roman numeral conversion." <<endl;
    cout << "Input the integer to convert."<<endl;
    cin >> ayear;
    
    if (ayear <1000 || ayear > 3000) 
        cout << ayear << " is Out of Range!";
    else {
        //Map inputs -> outputs
        arabic = ayear;
        n1000 = ayear / 1000;
        arabic -= n1000 * 1000;
        n100 = arabic / 100;
        arabic -= n100 * 100;
        n10 = arabic / 10;
        arabic -= n10 * 10;
        n1 = arabic;
        
        switch (n1000) {
            case 3:
                ryear += "MMM";
                break;
            case 2:
                ryear += "MM";
                break;
            case 1:
                ryear += "M";
                break;
        }
        switch (n100) {
            case 9:
                ryear += "CM";
                break;
            case 8:
                ryear += "DCCC";
                break;
            case 7:
                ryear += "DCC";
                break;
            case 6:
                ryear += "DC";
                break;
            case 5:
                ryear += "D";
                break;
            case 4:
                ryear += "CD";
                break;
            case 3:
                ryear += "CCC";
                break;
            case 2:
                ryear += "CC";
                break;
            case 1:
                ryear += "C";
                break;
        }
        switch (n10) {
            case 9:
                ryear += "XC";
                break;
            case 8:
                ryear += "LXXX";
                break;
            case 7:
                ryear += "LXX";
                break;
            case 6:
                ryear += "LX";
                break;
            case 5:
                ryear += "L";
                break;
            case 4:
                ryear += "XL";
                break;
            case 3:
                ryear += "XXX";
                break;
            case 2:
                ryear += "XX";
                break;
            case 1:
                ryear += "X";
                break;
        }
        switch (n1) {
            case 9:
                ryear += "IX";
                break;
            case 8:
                ryear += "VIII";
                break;
            case 7:
                ryear += "VII";
                break;
            case 6:
                ryear += "VI";
                break;
            case 5:
                ryear += "V";
                break;
            case 4:
                ryear += "IV";
                break;
            case 3:
                ryear += "III";
                break;
            case 2:
                ryear += "II";
                break;
            case 1:
                ryear += "I";
                break;
        }
        
        
        //Display the outputs
        cout << ayear << " is equal to " << ryear;
    }


    //Exit stage right or left!
    return 0;
}