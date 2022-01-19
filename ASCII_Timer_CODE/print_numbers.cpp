/**
 *
 * Solution to course project # 9
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @compiler VC
 *
 * File with the Functions that print the sent Digit
 * Every number={0,1,2,3,4,5,6,7,8,9} has a different Pattern based on the Line Number
 *
 * What gets printed is:
 * 1. The Number sent from print_hours.cpp, print_minutes.cpp or print_seconds.cpp
 * 2. Based of the curent Line in the Printing Process
 *
 */
#include "print_numbers.h"
#include <Windows.h>
#include <iostream>
using namespace std;

const int colorWhite = 15;
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void print0(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 0
    switch (lineNumber) {
    case 1:
    case 11:
        cout << "0000000000  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
    case 7:
        cout << "0        0  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "0        0  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print1(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 1
    cout << "1  ";
    if ((lineNumber == 4 || lineNumber == 7) && isItTheSecondDigit) {
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
    } else if (isItTheSecondDigit) {
        cout << "   ";
    }
}
void print2(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 2
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "2222222222  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 2:
    case 3:
    case 5:
        cout << "         2  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
        cout << "         2  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 7:
        cout << "2           ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 8:
    case 9:
    case 10:
        cout << "2           ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print3(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 3
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "3333333333  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
    case 7:
        cout << "         3  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "         3  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print4(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 4
    switch (lineNumber) {
    case 1:
    case 2:
    case 3:
    case 5:
        cout << "4        4  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 6:
        cout << "4444444444  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
        cout << "4        4  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 7:
        cout << "         4  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "         4  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print5(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 5
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "5555555555  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 2:
    case 3:
    case 5:
        cout << "5           ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
        cout << "5           ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 7:
        cout << "         5  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "         5  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print6(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 6
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "6666666666  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 2:
    case 3:
    case 5:
        cout << "6           ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
        cout << "6           ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 7:
        cout << "6        6  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "6        6  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print7(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 7
    switch (lineNumber) {
    case 1:
        cout << "7777777777  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
    case 7:
        cout << "         7  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "         7  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print8(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 8
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "8888888888  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
    case 7:
        cout << "8        8  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "8        8  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}
void print9(int num, int lineNumber, bool isItTheSecondDigit) {
    // Pattern of the digit 9
    switch (lineNumber) {
    case 1:
    case 6:
    case 11:
        cout << "9999999999  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 2:
    case 3:
    case 5:
        cout << "9        9  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    case 4:
        cout << "9        9  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    case 7:
        cout << "         9  ";
        if (isItTheSecondDigit) {
            SetConsoleTextAttribute(h, colorWhite);
            cout << "#  ";
        }
        break;
    default:
        cout << "         9  ";
        if (isItTheSecondDigit) {
            cout << "   ";
        }
        break;
    }
}