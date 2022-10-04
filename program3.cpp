//Austen Haymond
/*This program will be used to predict the growth of a bank account
due to compunded interest*/

#include <iostream>
using namespace std;
#include <math.h>

//declare function prototypes
double balMultiYear(double rate, double initBal, double threshold, 
double procCharge, double invYears, int table);
double balOneYear(double rate, double initBal, 
double threshold, double procCharge);
double getNumInput(void);
int getBoolChar(void);

int main() {
    double threshold, procCharge, invYears;
    double initBal, intrRate, finalBal;
    int table;
    //set newCalc and newInfo to '1' initially
    int newCalc, newInfo = 1;

    cout << "=======Account Balance Calculator=======" << endl << endl;
    cout << "Use this tool to predict account growth "
    << "from yearly compunded interest" << endl;
    cout << "========================================" << endl;
    
    cout << "Please enter the Bank's annual processing charge: " << endl;
    procCharge = getNumInput();

    cout << "Please enter the Bank's minimum balance threshold: " << endl;
    threshold = getNumInput();
    
    do {
        //allow user to enter investment information, only take positive numbers
        cout << "Please enter the starting account balance: " << endl;
        initBal = getNumInput();

        cout << "Please enter the interest rate as a decimal number: " << endl
        << "(Ex: if rate is 2.5%, enter 0.025" << endl;
        intrRate = getNumInput();

        cout << "Please enter the number of years "
        << "you would like to simulate: " << endl;
        invYears = getNumInput();

        //allow user to choose to display table
        cout << "Would you like to print a table of with each "
        << "year's balance? (y/n)" 
        << endl;
        table = getBoolChar();

        //execute calculations
        cout << "Calculating..." << endl << endl;
        finalBal = balMultiYear(intrRate, initBal, threshold, 
        procCharge, invYears, table);
        cout << endl << "Final Balance: $" << finalBal << endl;
        cout << "==============================================" << endl;
        
        //allow user to execute another calculation
        cout << "Would you like to do another calculation? (y/n)" << endl;
        newCalc = getBoolChar();        
    }

    while (newCalc != 0);

    return 0;
}

//define functions

//compute balance after given years, print table if requested
double balMultiYear(double rate, double initBal, double threshold, 
double procCharge, double invYears, int table) {
    double finalBal = initBal;

    //setup table print if requested
    if (table == 1) {
        cout << "Year|Balance" << endl
             << "----+-----------------------" << endl
             << "0   |$" << finalBal << endl;
    }

    for (int ix = 0; ix < invYears; ix++) {
        finalBal = balOneYear(rate, finalBal, threshold, procCharge);
        //print table
        if (table == 1) {
            //logic if year count is double or triple digits
            if (ix > 98) {
                cout << ix+1 <<" |$" << finalBal << endl;
            }
            else if (ix > 8) {
                cout << ix+1 <<"  |$" << finalBal << endl;
            }
            //else print for single digits
            else {
                cout << ix+1 <<"   |$" << finalBal << endl;
            }
        }
    }

    return finalBal;
}

//compute balance after one year
double balOneYear(double rate, double initBal, 
double threshold, double procCharge) {
double finalBal, interest;

interest = initBal * rate;
finalBal = initBal + interest;

if (finalBal < threshold) {
    finalBal -= procCharge;
}

return finalBal;
}

//input non-negative double, return value
double getNumInput(void) {
    double iNum;

    do {

        cin >> iNum;
        if (iNum < 0) {
            cout << "////ERROR//// Please enter a positive number: " << endl;
        }
    }
    while (iNum < 0);

    return iNum;
}

//input char y/n return 1/0
int getBoolChar(void) {
    char boolChar;

    do {
    
        cin >> boolChar;
        if (boolChar != 'y' && boolChar != 'n') {
            cout << "////ERROR//// Please enter 'y' or 'n': " << endl;
        }
    }
    while (boolChar != 'y' && boolChar != 'n');

    return (boolChar == 'y');
}