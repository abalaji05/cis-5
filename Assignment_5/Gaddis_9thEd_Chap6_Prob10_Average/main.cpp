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
void getScre(int &,int &,int &,int &,int &);
float calcAvg(int,int,int,int,int);
int fndLwst(int,int,int,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int scr1, scr2, scr3, scr4, scr5;
    float avg;
    
    //Initialize or input i.e. set variable values
    getScre(scr1, scr2, scr3, scr4, scr5);
    
    //Process
    avg = calcAvg(scr1, scr2, scr3, scr4, scr5);
    
    //Display the outputs
    cout << fixed << setprecision(1);
    cout << "The average test score = "<<avg;

    //Complete the program
    return 0;
}

void getScre(int &scr1,int &scr2,int &scr3,int &scr4,int &scr5) {
    
    cout << "Find the Average of Test Scores"<<endl;
    cout << "by removing the lowest value."<<endl;
    cout << "Input the 5 test scores."<<endl;
    cin >> scr1>>scr2>>scr3>>scr4>>scr5;
}

float calcAvg(int n1,int n2,int n3,int n4,int n5) {

    int low;
    float sum = 0;
    
    low = fndLwst(n1, n2, n3, n4, n5);
    
    if (n1 != low)
        sum += (float) n1;

    if (n2 != low)
        sum += (float) n2;
        
    if (n3 != low)
        sum += n3;

    if (n4 != low)
        sum += n4;

    if (n5 != low)
        sum += n5;
    
    return (float) sum/4.0;    
}

int fndLwst(int n1,int n2,int n3,int n4,int n5) {
    
    int temp;
    
    temp = min(n1, min(n2,n3));
    temp = min(temp, min(n4,n5));

    return temp;
}
