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
	const int colorRed = 12;
	int line = 1;
	while (line <= 11) {
		if (seconds == 10) {
			for (int i = 0; i <= 38; ++i) {
				cout << ' ';
			}
		}
		else {
			for (int i = 0; i <= 29; ++i) {
				cout << ' ';
			}
		}

		printSeconds(seconds, line, colorRed, colorRed);
		++line;
		cout << endl;
	}
}
void lessThan10Sec(int seconds, int n) {

	while (n >= 0) {
		for (int i = 1; i <= 7; ++i) {
			cout << endl;
		}

		printOnlySeconds(seconds);
		for (int i = 1; i <= 5; ++i) {
			cout << endl;
		}

		Sleep(250);
		screenClear();
		Sleep(250);

		for (int i = 1; i <= 7; ++i) {
			cout << endl;
		}
		printOnlySeconds(seconds);
		for (int i = 1; i <= 5; ++i) {
			cout << endl;
		}

		Sleep(250);
		screenClear();
		Sleep(250);

		--seconds;
		--n;

		if (n == 0) {
			cout << '\a';
			screenClear();
			endScreen(false);
		}
	}
}
void printIt(int hours, int minutes, int seconds, int n) {
	const int colorYellow = 14; // Value of the Color Yellow
	const int colorRed = 12;    // Value of the Color Red

	const int SIZE = 6;
	int colors[SIZE] = {};

	srand(time(0));
	for (int i = 0; i < 6; ++i) {
		colors[i] += 1 + (rand() % 15);
	}

	int hoursNumberCount = tensOfNumberCount(hours);

	int line = 1;
	while (line <= 11) {
		if (hours > 0) {
			if (hours >= 100) {// Whitespaces
				cout << "  ";
			}
			else if (hours == 1) {
				for (int i = 0; i <= 11; ++i) {
					cout << ' ';
				}
			}
			else if (hours < 10) {
				for (int i = 0; i <= 2; ++i) {
					cout << ' ';
				}
			}
			else if (hours == 11) {
				for (int i = 0; i <= 20; ++i) {
					cout << ' ';
				}
			}
			else if (hours / hoursNumberCount == 1 || (hours / (hoursNumberCount / 10)) % 10 == 1) {// If one of the digits is 1
				for (int i = 0; i <= 11; ++i) {
					cout << ' ';
				}
			}
			else {
				for (int i = 0; i <= 2; ++i) {
					cout << ' ';
				}
			}

			printHours(hours, line, hoursNumberCount, (hours < 10), colors[0], colors[1]);
			printMinutes(minutes, line, colors[2], colors[3]);
			printSeconds(seconds, line, colors[4], colors[5]);
		}
		else if (minutes > 0) { // The hours aren't printed

			if (minutes / 10 == 1 && minutes % 10 == 1) {
				for (int i = 0; i <= 33; ++i) {
					cout << ' ';
				}
			}
			else if (minutes / 10 == 1 || minutes % 10 == 1) {
				for (int i = 0; i <= 24; ++i) {
					cout << ' ';
				}
			}
			else {
				for (int i = 0; i <= 15; ++i) {
					cout << ' ';
				}
			}

			if ((minutes < 15) || (minutes == 15 && seconds == 0)) { // All the numbers are colored in yellow
				colors[2] = colors[3] = colors[4] = colors[5] = colorYellow;
			}
			if ((minutes == 1) && (seconds == 0)) { // All the numbers are colored in red
				colors[2] = colors[3] = colors[4] = colors[5] = colorRed;
			}

			printMinutes(minutes, line, colors[2], colors[3]);
			printSeconds(seconds, line, colors[4], colors[5]);
		}
		else if (seconds > 0) { // All the numbers are colored in red
			if (seconds <= 10) {
				lessThan10Sec(seconds, n);
			}
			if (seconds >= 10 && seconds < 20) {
				for (int i = 0; i <= 38; ++i) {
					cout << ' ';
				}
			}
			else {
				for (int i = 0; i <= 29; ++i) {
					cout << ' ';
				}
			}

			printSeconds(seconds, line, colorRed, colorRed);
		}

		++line;
		cout << endl;
	}
}
void printTimer(int hours, int minutes, int seconds, int n) {
	while (n >= 0) {
		if (n > 10) {
			for (int i = 1; i <= 7; ++i) {
				cout << endl;
			}
		}

		printIt(hours, minutes, seconds, n);

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

		Sleep(1000);
		screenClear();
	}
}