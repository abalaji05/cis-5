/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //format
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float balance;
    int nchecks;
    float tfee;
    float mfee;
    float cfee;
    float lfee;
    float nbalance;
    bool bflag;
    
    
    //Initialize or input i.e. set variable values
    cout<<"Monthly Bank Fees"<<endl;
    cout<<"Input Current Bank Balance and Number of Checks"<<endl;
    cin>>balance>>nchecks;
    if(nchecks<0)
        cout<<"The number of checks cannot be negative"<<endl;
    else if (balance<0)
        cout<<"The account is overdrawn"<<endl;
        
    else{
        mfee = 10.00;
        lfee = 15.00;
        bflag = false;
        
        
        //Map inputs -> outputs
        if(nchecks<20){
            cfee = 0.10*nchecks;
        }
        else if(nchecks>=20&&nchecks<=39)
            cfee = 0.08*nchecks;
        else if(nchecks>=40&&nchecks<=59)
            cfee = 0.06*nchecks;
        else if(nchecks>=60)
            cfee = 0.04*nchecks;
        
        tfee = mfee + cfee;
        if((balance-tfee)<400){
            bflag = true;
            tfee += lfee;
            
        }
             
        nbalance = balance - tfee;
        //Display the outputs
        cout<<fixed;
        cout<<"Balance     "<<"$"<<setw(9)<<setprecision(2)<<balance<<endl;
        cout<<"Check Fee   "<<"$"<<setw(9)<<setprecision(2)<<cfee<<endl;
        cout<<"Monthly Fee "<<"$"<<setw(9)<<setprecision(2)<<mfee<<endl;
        if(bflag)
            cout<<"Low Balance "<<"$"<<setw(9)<<setprecision(2)<<lfee<<endl;
        cout << "New Balance "<<"$"<<setw(9)<<setprecision(2)<<nbalance;
        
    }
    
    
    //Exit stage right or left!
    return 0;
}