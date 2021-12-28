#include "other_functions.hpp"
#include "print_hours.hpp"
#include "print_minutes.hpp"
#include "print_numbers.hpp"
#include "print_seconds.hpp"
#include <Windows.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n; // Seconds
    cin >> n;
    screenClear();
    int copyOfn = n;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    if (n < 60) {
        seconds = n;
    } else {
        for (int i = n; i > 0; i -= 60) {
            if (copyOfn >= 60) {
                ++minutes;
            }
            copyOfn -= 60;
            if (minutes == 60) {
                minutes = 0;
                ++hours;
            }
        }
        if (copyOfn != 0) {
            seconds = 60 + copyOfn;
        }
    }
    while (n >= 0) { // TODO Move this while other_functions
        // TODO Color the numbers randomly
        int line = 1;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        int hoursNumberCount = tensOfNumberCount(hours);
        while (line != 12) {
            if (hours > 0) {
                for (int i = 0; i <= 7; ++i) {
                    cout << ' ';
                }
                printHours(hours, line, hoursNumberCount, (hours < 10) ? true : false);
                printMinutes(minutes, line);
                printSeconds(seconds, line);
            } else if (minutes > 0) {
                for (int i = 0; i <= 18; ++i) {
                    cout << ' ';
                }
                printMinutes(minutes, line);
                printSeconds(seconds, line);
            } else if (seconds > 0) {
                for (int i = 0; i <= 35; ++i) {
                    cout << ' ';
                }
                printSeconds(seconds, line);
            }
            ++line;
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
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
        Sleep(1000);
        screenClear();
    }
    return 0;
}