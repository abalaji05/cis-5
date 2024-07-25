/* 
 * File:   main.cpp
 * Author: Akshay Balaji
 * Created: 7/21/2024
 * Purpose:  To fill a two dimensional array of 6 rows and 6 columns for dice combination products.
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6;

//Function Prototypes
void fillTbl(int [][COLS],int);
void prntTbl(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int ROWS=6;
    int tablProd[ROWS][COLS];
    
    //Initialize or input i.e. set variable values
    fillTbl(tablProd,ROWS);
    
    //Display the outputs
    prntTbl(tablProd,ROWS);

    //Exit stage right or left!
    return 0;
}

void fillTbl(int tablProd[][COLS], int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            tablProd[row][col] = (row + 1) * (col + 1);
        }
    }
}

void prntTbl(const int tablProd[][COLS], int rows) {
    
    int cols = COLS;
    
    // print column header
    cout << "Think of this as a Product/Muliplication Table" << endl;
    cout <<"           C o l u m n s" <<endl;
    
    cout << "     |";
    for (int i = 0; i < rows; i++) {
        cout << setw(4) << i+1;
    }
    cout << endl;
    cout << "----------------------------------"<<endl;
    
    // print row header and products
    for (int row = 0; row < rows; row++){
        if (row == 0 || row == 5)
            cout <<setw(4)<<row+1<<" |";
        else if (row == 1)
            cout << "R"<<setw(3)<<row+1<<" |";
        else if (row == 2)
            cout << "O"<<setw(3)<<row+1<<" |";
        else if (row == 3)
            cout << "W"<<setw(3)<<row+1<<" |";
        else if (row == 4)
            cout << "S"<<setw(3)<<row+1<<" |";
        for (int col = 0; col < cols; col++) {
            cout <<setw(4)<< tablProd[row][col];
        }
        cout <<endl;
    }
}
