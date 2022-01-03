#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void screenClear() {
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#else
	for (int i = 0; i <= 200; ++i) {
		cout << endl;
	}
#endif
}
int tensOfNumberCount(const int n) {
	int count = 1;
	for (int i = n; i > 0; i /= 10) {
		count *= 10;
	}
	count /= 10;
	return count;
}
int* transformHoursMinutesSeconds(int n) {
	int* timeArr = new int[3];
	timeArr[0] = 0;
	timeArr[1] = 0;
	timeArr[2] = 0;
	if (n < 60) {
		timeArr[2] = n;
	}
	else {
		for (int i = n; i > 0; i -= 60) {
			if (n >= 60) {
				++timeArr[1];
			}
			n -= 60;
			if (timeArr[1] == 60) {
				timeArr[1] = 0;
				++timeArr[0];
			}
		}
		if (n != 0) {
			timeArr[2] = 60 + n;
		}
	}
	return timeArr;
}
void printTimer() {
	int n;    // Seconds
	cin >> n; // TODO Make this long long and fix it in all files
	screenClear();
	int* timePtr = transformHoursMinutesSeconds(n);
	int hours = timePtr[0];
	int minutes = timePtr[1];
	int seconds = timePtr[2];

	printTimer(hours, minutes, seconds, n);
}
void printEndMessage() {
	const int colorWhite = 15;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colorWhite);
	cout << "To return to Home Screen type: 1" << endl;
	cout << "To exit type: 0" << endl;
}
void whenTimerIsZero() {
	const int colorRed = 12;
	cout << '\a';
	screenClear();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	int line = 1;
	while (line != 12) {
		for (int i = 0; i <= 7; ++i) {
			cout << ' ';
		}
		printHours(0, line, 1, true, colorRed, colorRed);
		printMinutes(0, line, colorRed, colorRed);
		printSeconds(0, line, colorRed, colorRed);
		++line;
		cout << endl;
	}
	cout << endl;
	printEndMessage();
	int r = 0;
	cin >> r;
	if (r == 1) {
		screenClear();
		printTimer();
	}
	if (r == 0) {
		screenClear();
		exit(0);
	}
}
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
			whenTimerIsZero();
		}
	}
}
void printTimer(int hours, int minutes, int seconds, int n) {
	const int colorYellow = 14; // Value of the Color Yellow
	const int colorRed = 12;    // Value of the Color Red
	while (n >= 0) {
		if (n > 10) {
			for (int i = 1; i <= 7; ++i) {
				cout << endl;
			}
		}
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
				for (int i = 0; i <= 7; ++i) {
					cout << ' ';
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
				if (seconds == 10) {
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