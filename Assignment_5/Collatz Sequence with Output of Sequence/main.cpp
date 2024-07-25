/* 
 * Author: Akshay Balaji
 * Created on 7/20/2024 6.35 p.m.
 * Purpose:  Output collatz sequence and length.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int collatzseq(int);//3n+1 sequence

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n,ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatz(n);
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
    
    //Exit stage right!
    return 0;
}

int collatzseq(int n) {
    int ccount = 1;
    
    cout << n;
    while (n > 1) {
        cout <<", ";
        if (n%2 == 0)
            n /= 2;
        else {
            n *= 3;
            n += 1;
        }
        cout << n;
        ccount += 1;
    }
    cout <<endl;
    
    return ccount;
}
