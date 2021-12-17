#include "print_numbers.h"
#include <iostream>
using namespace std;
void print0(int num, int lineNumber) {
    switch (lineNumber) {
    case 1:
    case 11:
        cout << "0000000000 ";
        break;
    default:
        cout << "0        0 ";
        break;
    }
}
void print1(int num, int lineNumber) { cout << "1 "; }
void print2(int num, int lineNumber) {
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "2222222222 ";
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "         2 ";
        break;
    case 7:
    case 8:
    case 9:
    case 10:
        cout << "2          ";
        break;
    }
}
void print3(int num, int lineNumber) {
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "3333333333 ";
        break;
    default:
        cout << "         3 ";
        break;
    }
}