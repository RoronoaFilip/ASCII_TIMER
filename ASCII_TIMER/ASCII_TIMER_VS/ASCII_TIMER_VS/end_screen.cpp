#include "other_functions.h"
#include "print_hours.h"
#include "print_minutes.h"
#include "print_seconds.h"
#include "end_screen.h"
#include "home_screen.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

void printEndScreen(bool invalidEntry) {
	const int colorWhite = 15;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colorWhite);

	for (int i = 1; i <= 25; ++i) {
		cout << ' ';
	}
	cout << "To return to Home Screen type: 1" << endl;
	for (int i = 1; i <= 32; ++i) {
		cout << ' ';
	}
	cout << "To exit type: 0" << endl;
	if (!invalidEntry) {
		for (int i = 1; i <= 34; ++i) {
			cout << ' ';
		}
		cout << "Your Entry: ";
	}
	if (invalidEntry) {
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
	const int colorRed = 12;

	for (int i = 1; i <= 7; ++i) {
		cout << endl;
	}

	int line = 1;
	while (line != 12) {
		for (int i = 0; i <= 2; ++i) {
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

	string input;
	getline(cin, input);
	if (!isInputCorrect(input)) {
		screenClear();
		endScreen(true);
	}

	int num = getNumber(input);
	if (num == 1) {
		screenClear();
		homeScreen();
	}
	else if (num == 0) {
		screenClear();
		exit(0);
	}
	else {
		screenClear();
		endScreen(true);
	}
}