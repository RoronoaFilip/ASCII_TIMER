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
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;
void printOnlySeconds(int seconds) {
    // The Equivelent of printIt()
    const int colorRed = 12;
    int line = 1;
    while (line <= 11) {
        // Centering Whitespaces
        int numberOfOnes = countOfOnes(0, 0, seconds);
        if (numberOfOnes == 0) {
            for (int i = 0; i <= 29; ++i) {
                cout << ' ';
            }
        } else {
            for (int i = 0; i <= 29 + 9 * numberOfOnes; ++i) {
                cout << ' ';
            }
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

        for (int i = 1; i <= 5; ++i) {
            cout << endl;
        }

        Sleep(250);
        screenClear(); // Blink
        Sleep(250);

        for (int i = 1; i <= 7; ++i) {
            cout << endl;
        }

        printOnlySeconds(seconds); // The Printing itself

        for (int i = 1; i <= 5; ++i) {
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
    const int colorYellow = 14; // Value of the Color Yellow
    const int colorRed = 12;    // Value of the Color Red

    const int SIZE = 6;
    int colors[SIZE] = {}; // Array for random Colors

    srand(time(0));
    for (int i = 0; i < 6; ++i) {
        colors[i] += 1 + (rand() % 15); // Never get the Value of black, which is 0
    }

    int hoursNumberCount = tensOfNumberCount(hours);

    int line = 1;
    while (line <= 11) {
        if (hours > 0) {
            // Whitespaces Conditions Beginning (only based on hours)
            int numberOfOnes = countOfOnes(hours, minutes, seconds);
            if (hours >= 100) {
                cout << "  ";
            } else if (numberOfOnes == 0) {
                for (int i = 0; i <= 2; ++i) {
                    cout << ' ';
                }
            } else {
                for (int i = 0; i <= 2 + 9 * numberOfOnes; ++i) {
                    cout << ' ';
                }
            }
            // Whitespaces Conditions End

            printHours(hours, line, hoursNumberCount, (hours < 10), colors[0], colors[1]);
            printMinutes(minutes, line, colors[2], colors[3]);
            printSeconds(seconds, line, colors[4], colors[5]);
        } else if (minutes > 0) { // The hours aren't printed Whitespaces Conditions Beginning (only based on minutes)
            int numberOfOnes = countOfOnes(hours, minutes, seconds);
            if (numberOfOnes == 0) {
                for (int i = 0; i <= 15; ++i) {
                    cout << ' ';
                }
            } else {
                for (int i = 0; i <= 15 + 9 * numberOfOnes; ++i) {
                    cout << ' ';
                }
            }
            // Whitespaces Conditions Beginning

            if ((minutes < 15) || (minutes == 15 && seconds == 0)) { // All the numbers are colored in yellow
                colors[2] = colors[3] = colors[4] = colors[5] = colorYellow;
            }
            if ((minutes == 1) && (seconds == 0)) { // All the numbers are colored in red
                colors[2] = colors[3] = colors[4] = colors[5] = colorRed;
            }

            printMinutes(minutes, line, colors[2], colors[3]);
            printSeconds(seconds, line, colors[4], colors[5]);
        } else if (seconds > 0) { // All the numbers are colored in red
            if (seconds <= 10) {  // Passed onto another Function
                lessThan10Sec(seconds, n);
            }
            // Whitespaces Conditions Beginning (only based on seconds)
            int numberOfOnes = countOfOnes(hours, minutes, seconds);
            if (numberOfOnes == 0) {
                for (int i = 0; i <= 29; ++i) {
                    cout << ' ';
                }
            } else {
                for (int i = 0; i <= 29 + 9 * numberOfOnes; ++i) {
                    cout << ' ';
                }
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
        if (n > 10) {
            for (int i = 1; i <= 7; ++i) { // Centering the Timer
                cout << endl;
            }
        }

        printIt(hours, minutes, seconds, n); // The Printing itself

        for (int i = 1; i <= 4; ++i) {
            cout << endl;
        }

        --seconds;
        --n;

        if (seconds == -1) {
            seconds = 59;
            --minutes;
        }
        if (minutes == -1) {
            minutes = 59;
            --hours;
        }

        Sleep(1000); // Second
        screenClear();
    }
}