/* 
 * Author: Akshay Balaji
 * Created on 7/20/2024 6.15 p.m.
 * Purpose: To find if a number is prime or not 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int);//Determine if the input number is prime.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int number;
    bool isprime;
    
    //Initialize Variables
    cout << "Input a number to test if Prime."<<endl;
    cin >> number;
    
    //Process/Map inputs to outputs
    isprime = isPrime(number);
    
    //Output data
    if (isprime)
        cout << number <<" is prime.";
    else
        cout << number <<" is not prime.";
    //Exit stage right!
    return 0;
}

bool isPrime(int n) {

  bool is_prime = true;
  
  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  // loop to check if n is prime
  for (int i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }
  
  return is_prime;
}