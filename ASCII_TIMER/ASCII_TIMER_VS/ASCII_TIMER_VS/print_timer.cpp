#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include "end_screen.h"
#include <Windows.h>
#include <iostream>
using namespace std;
void printOnlySeconds(int seconds) {
	const int colorRed = 12;
	int line = 1;
	while (line <= 11) {
		for (int i = 0; i <= 35; ++i) {
			cout << ' ';
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

	int colorA = rand() % 15;
	int colorB = rand() % 15;
	int colorC = rand() % 15;
	int colorD = rand() % 15;
	int colorE = rand() % 15;
	int colorF = rand() % 15;
	int hoursNumberCount = tensOfNumberCount(hours);

	int line = 1;
	while (line <= 11) {
		if (hours > 0) {
			if (hours >= 100)
			{
				cout << "  ";
			}
			else {
				for (int i = 0; i <= 7; ++i) {
					cout << ' ';
				}
			}

			printHours(hours, line, hoursNumberCount, (hours < 10), colorA, colorD);
			printMinutes(minutes, line, colorB, colorE);
			printSeconds(seconds, line, colorC, colorF);
		}
		else if (minutes > 0) { // The hours aren't printed
			for (int i = 0; i <= 18; ++i) {
				cout << ' ';
			}
			if ((minutes < 15) || (minutes == 15 && seconds == 0)) { // All the numbers are colored in yellow
				colorB = colorE = colorC = colorF = colorYellow;
			}
			if ((minutes == 1) && (seconds == 0)) { // All the numbers are colored in red
				colorB = colorE = colorC = colorF = colorRed;
			}

			printMinutes(minutes, line, colorB, colorE);
			printSeconds(seconds, line, colorC, colorF);
		}
		else if (seconds > 0) { // All the numbers are colored in red
			if (seconds <= 10) {
				lessThan10Sec(seconds, n);
			}
			for (int i = 0; i <= 35; ++i) {
				cout << ' ';
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

		for (int i = 1; i <= 5; ++i) {
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