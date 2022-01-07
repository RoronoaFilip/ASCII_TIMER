#include "other_functions.h"
#include "print_timer.h"
#include <iostream>
using namespace std;
void printT(int line) {
    switch (line) {
    case 1:
        cout << "TTTTTTTTTTT  ";
        break;
    default:
        cout << "     T       ";
    }
}
void printI() { cout << "I  "; }
void printM(int line) {
    switch (line) {
    case 1:
        cout << "M         M  ";
        break;
    case 2:
        cout << "M M     M M  ";
        break;
    case 3:
        cout << "M  M   M  M  ";
        break;
    case 4:
        cout << "M   M M   M  ";
        break;
    case 5:
        cout << "M    M    M  ";
        break;
    default:
        cout << "M         M  ";
        break;
    }
}
void printE(int line) {
    switch (line) {
    case 1:
    case 6:
    case 11:
        cout << "EEEEEEEEE  ";
        break;
    default:
        cout << "E          ";
        break;
    }
}
void printR(int line) {
    switch (line) {
    case 1:
        cout << "RRRR";
        break;
    case 2:
    case 5:
        cout << "R   R";
        break;
    case 3:
    case 4:
        cout << "R    R";
        break;
    case 6:
        cout << "RRRR";
        break;
    case 7:
        cout << "R R";
        break;
    case 8:
        cout << "R  R";
        break;
    case 9:
        cout << "R   R";
        break;
    case 10:
        cout << "R    R";
        break;
    case 11:
        cout << "R     R";
        break;
    }
}
void printHomeScreenAndMenu() { // TODO Add a Menu
    int line = 1;
    while (line <= 11) {
        for (int i = 1; i <= 16; ++i) {
            cout << ' ';
        }
        printT(line);
        printI();
        printM(line);
        printE(line);
        printR(line);
        cout << endl;
        ++line;
    }
}
void homeScreen() {
    printHomeScreenAndMenu();
    int n;         // Seconds
    cin >> n;      // TODO Make this long long and fix it in all files
    screenClear(); // TODO Make the Menu interactive like the End Screen
    int *timePtr = transformHoursMinutesSeconds(n);
    int hours = timePtr[0];
    int minutes = timePtr[1];
    int seconds = timePtr[2];

    printTimer(hours, minutes, seconds, n);
}