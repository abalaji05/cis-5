/* 
 * Author: Akshay Balaji
 * Created on 07/20/2024 5.30 p.m.
 * Purpose: To find minmax of three given integers using passing by reference 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void minmax(int,int,int,int&,int&);//Function to find the min and max

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int num1, num2,num3;
    int minnum, maxnum;
    
    //Initialize Variables
    cout << "Input 3 numbers"<<endl;
    cin >> num1 >> num2 >> num3;
    
    //Process/Map inputs to outputs
    minmax(num1, num2, num3, minnum, maxnum);
    
    //Output data
    cout << "Min = " << minnum << endl;
    cout << "Max = " << maxnum;
    
    //Exit stage right!
    return 0;
}

void minmax(int num1, int num2, int num3, int &minnum1, int &maxnum1) {
    
    minnum1 = min(num1, min(num2,num3));
    maxnum1 = max(num1, max(num2,num3));
    
}