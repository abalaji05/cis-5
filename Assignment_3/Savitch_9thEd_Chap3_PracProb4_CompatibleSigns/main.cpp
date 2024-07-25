/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr, Akshay Balaji
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstring>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string sign1, sign2;
    string element1, element2;
    
    //Initialize or input i.e. set variable values
    cout << "Horoscope Program which examines compatible signs." <<endl;
    cout << "Input 2 signs." << endl;
    cin >> sign1 >> sign2;
    
    //Map inputs -> outputs
    if (sign1 == "Aries" || sign1 == "Leo" || sign1 == "Sagittarius")
        element1 = "Fire";
    if (sign1 == "Taurus" || sign1 == "Virgo" || sign1 == "Capricorn")
        element1 = "Earth";
    if (sign1 == "Gemini" || sign1 == "Libra" || sign1 == "Aquarius")
        element1 = "Air";
    if (sign1 == "Cancer" || sign1 == "Scorpio" || sign1 == "Pisces")
        element1 = "Water";
    if (sign2 == "Aries" || sign2 == "Leo" || sign2 == "Sagittarius")
        element2 = "Fire";
    if (sign2 == "Taurus" || sign2 == "Virgo" || sign2 == "Capricorn")
        element2 = "Earth";
    if (sign2 == "Gemini" || sign2 == "Libra" || sign2 == "Aquarius")
        element2 = "Air";
    if (sign2 == "Cancer" || sign2 == "Scorpio" || sign2 == "Pisces")
        element2 = "Water";
    
    //Display the outputs
    if (element1 == element2)
        cout << sign1 << " and " << sign2 << " are compatible " << element1 << " signs.";
    else
        cout << sign1 << " and " << sign2 << " are not compatible signs.";

    //Exit stage right or left!
    return 0;
}