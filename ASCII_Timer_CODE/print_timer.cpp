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
 * File with Functions with the Algorithm for the Timer
 * (Centering | Sending for Print | What gets sent for Print)
 *
 */
#include "end_screen.h"
#include "other_functions.h"
#include "send_time_for_print.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;

const int colorYellow = 14; // Value of the Color Yellow
const int colorRed = 12;    // Value of the Color Red

void printOnlySeconds(int seconds) {
    // The same as printIt()

    int hours = 0;   // The Hours are already 0
    int minutes = 0; // The Minutes are already 0

    int line = 1;
    while (line <= 11) {
        // Centering Whitespaces
        int numberOfOnes = countOfOnes(hours, minutes, seconds);
        for (int i = 1; i <= 29 + (9 / 2 * numberOfOnes); ++i) {
            cout << ' ';
        }

        printSeconds(seconds, line, colorRed, colorRed); // Send for Print

        ++line;
        cout << endl;
    }
}
void lessThan10Sec(int seconds, int n) {
    // Less than 10 Seconds because of Blinking
    while (n >= 0) {
        for (int i = 1; i <= 7; ++i) { // Centering
            cout << endl;
        }

        printOnlySeconds(seconds); // The Printing itself

        for (int i = 2; i <= 7; ++i) {
            cout << endl;
        }

        Sleep(250);
        screenClear(); // Blink
        Sleep(250);

        for (int i = 1; i <= 7; ++i) {
            cout << endl;
        }

        printOnlySeconds(seconds); // The Printing itself

        for (int i = 2; i <= 7; ++i) {
            cout << endl;
        }

        Sleep(250);
        screenClear(); // Blink
        Sleep(250);

        --seconds;
        --n;

        if (n == 0) {     // Timer is 0
            cout << '\a'; // Sound
            screenClear();
            endScreen(); // Print the End Screen
        }
    }
}
void printIt(int hours, int minutes, int seconds, int n) {

    const int SIZE = 6;
    int colors[SIZE] = {}; // Array for random Colors

    srand(time(NULL));
    for (int i = 0; i < 6; ++i) {
        colors[i] += 1 + (rand() % 15); // Never get the Value of black, which is 0
    }

    int hoursNumberCount = tensOfNumberCount(hours); // Number of tens (Tens, Hundreds, Thousands)

    int line = 1;
    while (line <= 11) {
        if (hours > 0) {
            int numberOfOnes = countOfOnes(hours, minutes, seconds);

            // Whitespaces Conditions Beginning
            if (hours >= 100) {
                cout << "  ";
            } else {
                for (int i = 1; i <= 2 + (9 / 2 * numberOfOnes); ++i) {
                    cout << ' ';
                }
            }
            // Whitespaces Conditions End

            printHours(hours, line, hoursNumberCount, (hours < 10), colors[0], colors[1]);
            printMinutes(minutes, line, colors[2], colors[3]);
            printSeconds(seconds, line, colors[4], colors[5]);
        } else if (minutes > 0) { // The hours aren't printed

            int numberOfOnes = countOfOnes(hours, minutes, seconds);

            // Whitespaces Conditions Beginning
            for (int i = 1; i <= 15 + (9 / 2 * numberOfOnes); ++i) {
                cout << ' ';
            }
            // Whitespaces Conditions End

            if (minutes < 15) { // All the numbers are colored in yellow
                colors[2] = colors[3] = colors[4] = colors[5] = colorYellow;
            }

            printMinutes(minutes, line, colors[2], colors[3]);
            printSeconds(seconds, line, colors[4], colors[5]);
        } else if (seconds > 0) { // All the numbers are colored in red

            if (seconds < 10) { // Passed onto another Function
                lessThan10Sec(seconds, n);
            }

            // Whitespaces Conditions Beginning
            int numberOfOnes = countOfOnes(hours, minutes, seconds);
            for (int i = 1; i <= 29 + (9 / 2 * numberOfOnes); ++i) {
                cout << ' ';
            }
            // Whitespaces Conditions End

            printSeconds(seconds, line, colorRed, colorRed);
        }

        ++line;
        cout << endl;
    }
}
void printTimer(int hours, int minutes, int seconds, int n) {
    while (n >= 0) {
        if (n >= 10) {
            for (int i = 1; i <= 7; ++i) { // Centering the Timer
                cout << endl;
            }
        }

        printIt(hours, minutes, seconds, n); // The Printing itself

        for (int i = 2; i <= 7; ++i) {
            cout << endl;
        }

        --seconds;
        --n;

        if (seconds == -1) { // Reset Seconds
            seconds = 59;
            --minutes;
        }
        if (minutes == -1) { // Reset Minutes
            minutes = 59;
            --hours;
        }

        Sleep(1000); // Second
        screenClear();
    }
    // When Sleep(1000) - Behind with 4 Min 45 Sec after 1 Hour
    // When Sleep(900) - Ahead with 1 Min 30 Sec after 1 Hour
    // When Sleep(870) - Ahead with 1 Min 10 Sec after 1 Hour
}