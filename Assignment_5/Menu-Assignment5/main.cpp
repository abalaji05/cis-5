/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created on 7/21/2024 12:45 p.m.
 * Purpose:  Menu to be used in the Midterm, future homework and the Final
 *           Add System Libraries and Functions as needed.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
unsigned short  getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void minmax(int, int, int, int&, int&);
int fctrl(int);
bool isPrime(int);
int collatz(int);
int collatzseq(int);
bool isValidTime(int, int, char);
void calculateNewTime(int, int, char, int);
void getInput(int& hours, int& minutes);
void convertTime(int, int, int&, int&, char&);
void outputResult(int, int, int, int, char);
bool isValidTimeSimple(int, int);
float psntVal(float,float,int);
void getScre(int &,int &,int &,int &,int &);
float calcAvg(int,int,int,int,int);
int fndLwst(int,int,int,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set a Random number seed here.
    
    //Declare Main variables here.
    unsigned short inN;
    
    //Loop on each problem
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            case 8:    problem8();break;
            case 9:    problem9();break;
            default:   def(inN);
	}
    }while(inN<10 && inN > 0);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1"<<endl;
    cout<<"Type 2 to execute Problem 2"<<endl;
    cout<<"Type 3 to execute Problem 3"<<endl;
    cout<<"Type 4 to execute Problem 4"<<endl;
    cout<<"Type 5 to execute Problem 5"<<endl;
    cout<<"Type 6 to execute Problem 6"<<endl;
    cout<<"Type 7 to execute Problem 7"<<endl;
    cout<<"Type 8 to execute Problem 8"<<endl;
    cout<<"Type 9 to execute Problem 8"<<endl;
    cout<<"Type anything else to exit."<<endl<<endl;
}

unsigned short getN(){
    unsigned short inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

// used in problem 1
void minmax(int num1, int num2, int num3, int &minnum1, int &maxnum1) {
    
    minnum1 = min(num1, min(num2,num3));
    maxnum1 = max(num1, max(num2,num3));
    
}

// used in problem 2
int fctrl(int n) {
    int value = 1.0;
    if (n ==0) return value;

    for (int i=1; i<=n; ++i)
        value *= i;

    return value;   
}

// used in problem 3
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

// used in problem 4
int collatz(int n) {
    int ccount = 1;
    
    while (n > 1) {
        if (n%2 == 0)
            n /= 2;
        else {
            n *= 3;
            n += 1;
        }
        ccount += 1;
    }
    
    return ccount;
}

// used in problem 5
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

// used in problem 6
bool isValidTime(int hours, int minutes, char ampm) {
    ampm = tolower(ampm); // Convert to lowercase for uniformity
    if (hours < 0 || hours > 12) {
        return false;
    }
    if (minutes < 0 || minutes >= 60) {
        return false;
    }
    if (ampm != 'a' && ampm != 'p') {
        return false;
    }
    return true;
}

void calculateNewTime(int hours, int minutes, char ampm, int waitTime) {
    int originalHours = hours;
    int originalMinutes = minutes;
    char originalAmpm = ampm;

    // Convert 12-hour time to 24-hour time for easier calculation
    ampm = tolower(ampm); // Convert to lowercase for uniformity
    if (hours == 0) {
        hours = 12; // Handle 0 as 12 in 12-hour format
    }
    if (ampm == 'p' && hours != 12) {
        hours += 12;
    }
    if (ampm == 'a' && hours == 12) {
        hours = 0;
    }

    // Add the waiting time
    minutes += waitTime;
    hours += minutes / 60;
    minutes = minutes % 60;
    hours = hours % 24;

    // Convert back to 12-hour time
    string newAmpm = "AM";
    if (hours >= 12) {
        newAmpm = "PM";
    }
    if (hours > 12) {
        hours -= 12;
    }
    if (hours == 0) {
        hours = 12;
    }

    // Print the result
    cout << "Current time = " << setw(2) << setfill('0') << originalHours << ":"
         << setw(2) << setfill('0') << originalMinutes << " "
         << (originalAmpm == 'a' || originalAmpm == 'A' ? "AM" : "PM") << endl;
    cout << "Time after waiting period = " << setw(2) << setfill('0') << hours << ":"
         << setw(2) << setfill('0') << minutes << " " << newAmpm << endl;
    cout << endl;
}

// used in problem 7
void getInput(int& hours, int& minutes) {
    char colon;
    cin >> hours >> colon >> minutes;
}

void convertTime(int hours, int minutes, int& convertedHours, int& convertedMinutes, char& period) {
    if (hours == 0) {
        convertedHours = 12;
        period = 'A';
    } else if (hours == 12) {
        convertedHours = 12;
        period = 'P';
    } else if (hours > 12) {
        convertedHours = hours - 12;
        period = 'P';
    } else {
        convertedHours = hours;
        period = 'A';
    }

    convertedMinutes = minutes;
}

void outputResult(int hours, int minutes, int convertedHours, int convertedMinutes, char period) {
    cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " = "
         << convertedHours << ":" << setw(2) << setfill('0') << convertedMinutes << " " << period << "M" << endl;
}

bool isValidTimeSimple(int hours, int minutes) {
    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59);
}

// used in problem 8
float psntVal(float fValue,float rate,int nYears) {    
    return fValue / pow((1 + rate/100), nYears);
}

// used in problem 9
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

void problem1(){
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
}

void problem2(){
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
}

void problem3(){
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
}

void problem4(){
    //Declare Variables
    int n;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            collatz(n)<<" steps";
}

void problem5(){
    //Declare Variables
    int n,ns;
    
    //Initialize Variables
    cout<<"Collatz Conjecture Test"<<endl;
    cout<<"Input a sequence start"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    ns=collatzseq(n);
    
    //Output data
    cout<<"Sequence start of "<<n<<" cycles to 1 in "<<
            ns<<" steps";
}

void problem6(){
    int hours, minutes, waitTime;
    char ampm, again;

    do {
        do {
            cout << "Enter hour:" << endl;
            cin >> hours;
            cout << endl;

            cout << "Enter minutes:" << endl;
            cin >> minutes;
            cout << endl;

            cout << "Enter A for AM, P for PM:" << endl;
            cin >> ampm;
            cout << endl;

            if (!isValidTime(hours, minutes, ampm)) {
                cout << "Invalid time input. Please try again." << endl;
            }
        } while (!isValidTime(hours, minutes, ampm));

        cout << "Enter waiting time:" << endl;
        cin >> waitTime;
        cout << endl;

        calculateNewTime(hours, minutes, ampm, waitTime);

        cout << "Again:" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y')
            cout << endl;
    } while (again == 'y' || again == 'Y');
}

void problem7(){
    int hours, minutes;
    char again;

    cout << "Military Time Converter to Standard Time" << endl;

    cout << "Input Military Time hh:mm" << endl;
    
    do {
        getInput(hours, minutes);

        if (isValidTimeSimple(hours, minutes)) {
            int convertedHours, convertedMinutes;
            char period;
            convertTime(hours, minutes, convertedHours, convertedMinutes, period);
            outputResult(hours, minutes, convertedHours, convertedMinutes, period);
        } else {
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << " is not a valid time" << endl;
        }

        cout << "Would you like to convert another time (y/n)" << endl;
        cin >> again;
        again = tolower(again);
    } while (again == 'y');
}

void problem8(){
    //Set the random number seed
    
    //Declare Variables
    float pValue, fValue;
    int nYears;
    float rate;
    
    //Initialize or input i.e. set variable values
    cout << "This is a Present Value Computation"<<endl;
    
    cout << "Input the Future Value in Dollars" <<endl;
    cin >> fValue;
    cout << "Input the Number of Years" <<endl;
    cin >> nYears;
    cout << "Input the Interest Rate %/yr"<<endl;
    cin >> rate;
    
    
    //Process
    cout << fixed << setprecision(2);
    
    pValue = psntVal(fValue,rate,nYears);
    
    //Display the outputs
    
    
    cout <<"The Present Value = $"<<pValue;
}

void problem9(){
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
}