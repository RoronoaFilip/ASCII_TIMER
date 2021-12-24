#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_numbers.h"
#include "print_seconds.h"
#include <Windows.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	int n; // Seconds
	cin >> n;
	screenClear();
	int* timePtr = transformHoursMinutesSeconds(n);
	int hours = timePtr[0];
	int minutes = timePtr[1];
	int seconds = timePtr[2];

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
		screenClear();
	}
	return 0;
}