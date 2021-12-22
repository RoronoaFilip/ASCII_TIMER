#include "print_seconds.h"
#include "../PrintNumbers/print_numbers.h"
void printSeconds(const int seconds, const int lineNumber) {
    bool isItTheSecondDigit = false;
    switch (seconds / 10) {
    case 0:
        print0(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 1:
        print1(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 2:
        print2(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 3:
        print3(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 4:
        print4(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 5:
        print5(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 6:
        print6(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 7:
        print7(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 8:
        print8(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    case 9:
        print9(seconds / 10, lineNumber, isItTheSecondDigit);
        break;
    }
    switch (seconds % 10) {
    case 0:
        print0(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 1:
        print1(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 2:
        print2(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 3:
        print3(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 4:
        print4(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 5:
        print5(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 6:
        print6(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 7:
        print7(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 8:
        print8(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    case 9:
        print9(seconds % 10, lineNumber, isItTheSecondDigit);
        break;
    }
}