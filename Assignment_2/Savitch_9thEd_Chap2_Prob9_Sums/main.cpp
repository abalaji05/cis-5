/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int a,b,c,d,e,f,g,h,i,j; // input variables
    int ns,ps,ts; // sums
    
    //Initialize or input i.e. set variable values
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    cin >> a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
    
    //Map inputs -> outputs
    ns = 0;
    ps = 0;
    ts = 0;
    
    if (a < 0)
        ns = ns + a;
    else
        ps = ps + a;
        
    if (b < 0)
        ns = ns + b;
    else
        ps = ps + b;
        
    if (c < 0)
        ns = ns + c;
    else
        ps = ps + c;

    if (d < 0)
        ns = ns + d;
    else
        ps = ps + d;

    if (e < 0)
        ns = ns + e;
    else
        ps = ps + e;

    if (f < 0)
        ns = ns + f;
    else
        ps = ps + f;

    if (g < 0)
        ns = ns + g;
    else
        ps = ps + g;

    if (h < 0)
        ns = ns + h;
    else
        ps = ps + h;

    if (i < 0)
        ns = ns + i;
    else
        ps = ps + i;

    if (j < 0)
        ns = ns + j;
    else
        ps = ps + j;
        
    ts = ns + ps;
    
    //Display the outputs
    cout << "Negative sum = " << setw(3) << ns << endl;
    cout << "Positive sum = " << setw(3) << ps <<endl;
    cout << "Total sum    = " << setw(3) << ts;
 

    //Exit stage right or left!
    return 0;
}