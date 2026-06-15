// ============================================================
// Name    : Andy Nguyen
// Course  : COSC 1437 — Programming Fundamentals II
// Date    : 6/14/26
// Program : Chapter 6 Major Project
// ============================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// prototypes

void mathSummary(double x);
double calcTax(double income, double rate);
void printHeader(string courseTitle);
void displayResult(string label, double value);
void convertTime(int totalSeconds, int &minutes, int &seconds);

/* count calls 

A static variable is initialized once and keeps its value,
while a regular local variable resets each time

*/

void countCalls();

void displayBox(int width);
void displayBox(int width, int height);

double calcShipping(double weight, double ratePerPound = 1.50, double baseFee = 5.00);

int main() {

    // Part 1: Predefined Functions Warm-Up
    mathSummary(9.75);
    mathSummary(-4.2);

    // Part 2: Value-Returning Function
    double income, rate;
    cout << "Enter gross income: ";
    cin >> income;
    cout << "Enter tax rate (e.g., 0.25): ";
    cin >> rate;

    double taxOwed = calcTax(income, rate);

    // Part 3: Void Functions
    printHeader("Tax Calculation Results");
    displayResult("Tax Owed", taxOwed);

    // Part 4: Value vs. Reference Parameters
    int totalSeconds, minutes, seconds;
    cout << "Enter total seconds: ";
    cin >> totalSeconds;

    convertTime(totalSeconds, minutes, seconds);

    displayResult("Minutes", minutes);
    displayResult("Seconds", seconds);

    // Part 5: Scope and Static Variables
    countCalls();
    countCalls();
    countCalls();
    countCalls();

    // Part 6: Function Overloading
    displayBox(5);
    displayBox(7, 3);

    // Part 7: Default Parameters
    double ship1 = calcShipping(10, 2.0, 8.0);
    double ship2 = calcShipping(10, 2.0);
    double ship3 = calcShipping(10);

    displayResult("Shipping (all)", ship1);
    displayResult("Shipping (weight and rate)", ship2);
    displayResult("Shipping (weight only)", ship3);

    return 0;
}

// Part 1: Predefined Functions
void mathSummary(double x) {
    cout << fixed << setprecision(2);
    cout << endl << "Math Summary for x = " << x << endl;
    cout << "Square root: " << sqrt(x) << endl;
    cout << "x^3: " << pow(x, 3) << endl;
    cout << "Ceiling: " << ceil(x) << endl;
    cout << "Floor: " << floor(x) << endl;
    cout << "Absolute value of (x * -1): " << abs(x * -1) << endl;
}

// Part 2: Value-Returning Function
double calcTax(double income, double rate) {
    return income * rate;
}

// Part 3: Void Functions
void printHeader(string courseTitle) {
    cout << endl << "----------------------------------------" << endl;
    cout << "          " << courseTitle << endl;
    cout << endl << "----------------------------------------" << endl;
}

void displayResult(string label, double value) {
    cout << left << setw(20) << label << ": "
         << fixed << setprecision(2) << value << endl;
}


// Part 4: Value vs. Reference Parameters
void convertTime(int totalSeconds, int &minutes, int &seconds) {
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

// Part 5: Scope and Static Variables
void countCalls() {
    static int count = 0;
    count++;
    cout << "countCalls has been called " << count << " time(s)" << endl;
}

// Part 6: Function Overloading
void displayBox(int width) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void displayBox(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Part 7: Default Parameters
double calcShipping(double weight, double ratePerPound, double baseFee) {
    return baseFee + (weight * ratePerPound);
}

/* Inputs + Outputs

@andynguyen2121 ➜ /workspaces/assignment6 (main) $ g++ main.cpp 
@andynguyen2121 ➜ /workspaces/assignment6 (main) $ ./a.out 

Math Summary for x = 9.75
Square root: 3.12
x^3: 926.86
Ceiling: 10.00
Floor: 9.00
Absolute value of (x * -1): 9.75

Math Summary for x = -4.20
Square root: -nan
x^3: -74.09
Ceiling: -4.00
Floor: -5.00
Absolute value of (x * -1): 4.20
Enter gross income: 50000
Enter tax rate (e.g., 0.25): .22

----------------------------------------
          Tax Calculation Results

----------------------------------------
Tax Owed            : 11000.00
Enter total seconds: 135
Minutes             : 2.00
Seconds             : 15.00
countCalls has been called 1 time(s)
countCalls has been called 2 time(s)
countCalls has been called 3 time(s)
countCalls has been called 4 time(s)
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * * * 
* * * * * * * 
* * * * * * * 
Shipping (all)      : 28.00
Shipping (weight and rate): 25.00
Shipping (weight only): 20.00

*/