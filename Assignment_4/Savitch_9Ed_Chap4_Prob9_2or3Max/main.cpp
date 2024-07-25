/* 
 * File:   
 * Author: akshay balaji
 * Created on 
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
float largest(float n1, float n2){
    if(n1>n2)
        return n1;
    else
        return n2;
}
float largest(float n1 , float n2 , float n3){
    if(n1>n2) {
        if (n1 > n3)
            return n1;
        else
            return n3;
    }
    else {
        if (n2 > n3)
            return n2;
        else
            return n3;
    }
}
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float n1;
    float n2;
    float n3;
    float maxn;
    
    
    //Initialize or input i.e. set variable values
    cout<<"Enter first number:"<<endl<<endl;
    cin>>n1;
    cout<<"Enter Second number:"<<endl<<endl;
    cin>>n2;
    cout<<"Enter third number:"<<endl<<endl;
    cin>>n3;
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout<<"Largest number from two parameter function:"<<endl<<largest(n1,n2)<<endl<<endl;
    
    cout<<"Largest number from three parameter function:"<<endl<<largest(n1,n2,n3)<<endl;

    //Exit stage right or left!
    return 0;
}