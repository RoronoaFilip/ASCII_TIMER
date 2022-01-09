#include "other_functions.h"
#include "print_timer.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;
void printT(int line, int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    switch (line) {
    case 1:
        cout << "TTTTTTTTTTT  ";
        break;
    default:
        cout << "     T       ";
    }
}
void printI(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    cout << "I  ";
}
void printM(int line, int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
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
void printE(int line, int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
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
void printR(int line, int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
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
void printHomeScreenAndMenu(bool InvalidEntry) { // TODO Add a Menu
    const int colorWhite = 15;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    const int colorSize = 5;
    int colors[colorSize] = {};

    srand(time(nullptr));
    for (int i = 0; i < colorSize; ++i) { // Random Colors
        colors[i] = 1 + (rand() % 15);
    }

    for (int i = 1; i <= 3; ++i) {
        cout << endl;
    }

    // "TIMER" Text
    int line = 1;
    while (line <= 11) {
        for (int i = 1; i <= 16; ++i) {
            cout << ' ';
        }

        printT(line, colors[0]);
        printI(colors[1]);
        printM(line, colors[2]);
        printE(line, colors[3]);
        printR(line, colors[4]);

        cout << endl;
        ++line;
    }

    // MENU
    SetConsoleTextAttribute(h, colorWhite);
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 32; ++i) {
        cout << ' ';
    }

    cout << "Input Menu:";
    cout << endl;

    for (int i = 1; i <= 20; ++i) {
        cout << ' ';
    }

    cout << "> Enter an Amount of Time in Seconds";
    cout << endl;

    for (int i = 1; i <= 22; ++i) {
        cout << ' ';
    }

    cout << "> To exit the Program enter '0' ";
    cout << endl;

    if (!InvalidEntry) {
        for (int i = 1; i <= 32; ++i) {
            cout << ' ';
        }
        cout << "Your Input: ";
    }
    if (InvalidEntry) {
        cout << endl;
        for (int i = 1; i <= 22; ++i) {
            cout << ' ';
        }
        cout << "Invalid Entry! Please try again!";

        cout << endl;
        for (int i = 1; i <= 32; ++i) {
            cout << ' ';
        }
        cout << "Your Input: ";
    }
}
void homeScreen(bool InvalidEntry = false) {
    printHomeScreenAndMenu(InvalidEntry);

    const int colorWhite = 15;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, colorWhite);

    int n; // Seconds //TODO Make this a string and validate entries!!!
    cin >> n;
    if (n == 0) {
        screenClear();
        exit(0);
    }
    if (n < 0) {
        screenClear();
        homeScreen(true);
    }

    screenClear();

    int *timePtr = transformHoursMinutesSeconds(n);
    int hours = timePtr[0];
    int minutes = timePtr[1];
    int seconds = timePtr[2];

    printTimer(hours, minutes, seconds, n);
}