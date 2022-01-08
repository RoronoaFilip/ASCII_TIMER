#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include "end_screen.h"
#include "home_screen.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void printEndScreen(bool invalidEntry) {
	const int colorWhite = 15;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colorWhite);
	cout << "To return to Home Screen type: 1" << endl;
	cout << "To exit type: 0" << endl;
	if (invalidEntry) {
		cout << "Invalid entry! Please try again: ";
	}
}
void endScreen(bool invalidEntry) {
	const int colorRed = 12;

	for (int i = 1; i <= 7; ++i) {
		cout << endl;
	}

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
	printEndScreen(invalidEntry);

	int r = 0;
	cin >> r;
	if (r == 1) {
		screenClear();
		homeScreen();
	}
	else if (r == 0) {
		screenClear();
		exit(0);
	}
	else {
		screenClear();
		endScreen(true);
	}
}