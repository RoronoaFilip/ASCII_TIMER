#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include <Windows.h>
#include <iostream>
using namespace std;
void printTimer() {
	int n; // Seconds
	cin >> n;
	screenClear();
	int* timePtr = transformHoursMinutesSeconds(n);
	int hours = timePtr[0];
	int minutes = timePtr[1];
	int seconds = timePtr[2];

	printTimer(hours, minutes, seconds, n);
}
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
	int timeArr[3] = {};
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
void printEndMessage() {
	cout << "To return to Home Screen type: 1" << endl;
	cout << "To exit type: 0" << endl;
}
void whenTimerIsZero() {
	cout << '\a';
	screenClear();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	int r = 0;
	int line = 1;
	while (line != 12) {
		for (int i = 0; i <= 7; ++i) {
			cout << ' ';
		}
		printHours(0, line, 1, true);
		printMinutes(0, line);
		printSeconds(0, line);
		++line;
		cout << endl;
	}
	cout << endl;
	printEndMessage();
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
void printTimer(int hours, int minutes, int seconds, int n) {
	while (n >= 0) {
		//TODO do the coloring
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
			}
			else if (minutes > 0) {
				for (int i = 0; i <= 18; ++i) {
					cout << ' ';
				}
				printMinutes(minutes, line);
				printSeconds(seconds, line);
			}
			else if (seconds > 0) {
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
		if (n == 0) {
			whenTimerIsZero();
		}
		screenClear();
	}
}