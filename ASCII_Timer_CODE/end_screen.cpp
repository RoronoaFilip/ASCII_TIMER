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
 * File with all Functions for the End Screen
 *
 */
#include "end_screen.h"
#include "home_screen.h"
#include "other_functions.h"
#include "send_time_for_print.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;

void printEndScreen(bool invalidEntry) {
    // Printing the End Screen
    const int colorWhite = 15;
    const int colorRed = 12;
    const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 1; i <= 7; ++i) {
        cout << endl;
    }

    int line = 1;
    while (line != 12) { // Print 00:00:00 centered in red
        cout << ' ' << ' ';
        printHours(0, line, 1, true, colorRed, colorRed);
        printMinutes(0, line, colorRed, colorRed);
        printSeconds(0, line, colorRed, colorRed);
        ++line;
        cout << endl;
    }
    cout << endl;

    SetConsoleTextAttribute(h, colorWhite);

    for (int i = 1; i <= 25; ++i) { // Print a Menu
        cout << ' ';
    }
    cout << "To return to Home Screen type: 1" << endl;
    for (int i = 1; i <= 32; ++i) {
        cout << ' ';
    }
    cout << "To exit type: 0" << endl;

    if (!invalidEntry) { // Print this if there isn't an invalid Entry
        for (int i = 1; i <= 34; ++i) {
            cout << ' ';
        }
        cout << "Your Entry: ";
    }
    if (invalidEntry) { // Print this if there is an invalid Entry
        cout << endl;
        for (int i = 1; i <= 24; ++i) {
            cout << ' ';
        }
        cout << "Invalid entry! Please try again!" << endl;
        for (int i = 1; i <= 34; ++i) {
            cout << ' ';
        }
        cout << "Your Entry: ";
    }
}
void endScreen(bool invalidEntry) {

    printEndScreen(invalidEntry); // Print the End Screen

    char input[100]; // A String to determine if the Input is valid
    cin.getline(input, 101);

    if (!isInputCorrect(input)) { // Print the End Screen with an Invalid Entry Text
        screenClear();
        endScreen(true);
    }

    int num = getNumber(input); // Transform string to integer

    if (num == 1) {
        screenClear();
        homeScreen();
    } else if (num == 0) {
        screenClear();
        exit(0);
    } else {
        screenClear();
        endScreen(true); // Print the End Screen with an Invalid Entry Text
    }
}