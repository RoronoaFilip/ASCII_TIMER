#include "other_functions.h"
#include "print_timer.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;
void printT(int line, int color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	switch (line) {
	case 1:
		cout << "TTTTTTTTTTT  ";
		break;
	default:
		cout << "     T       ";
	}
}
void printI(int color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	cout << "I  ";
}
void printM(int line, int color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	switch (line) {
	case 1:
		cout << "M         M  ";
		break;
	case 2:
		cout << "M M     M M  ";
		break;
	case 3:
		cout << "M  M   M  M  ";
		break;
	case 4:
		cout << "M   M M   M  ";
		break;
	case 5:
		cout << "M    M    M  ";
		break;
	default:
		cout << "M         M  ";
		break;
	}
}
void printE(int line, int color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	switch (line) {
	case 1:
	case 6:
	case 11:
		cout << "EEEEEEEEE  ";
		break;
	default:
		cout << "E          ";
		break;
	}
}
void printR(int line, int color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
	switch (line) {
	case 1:
		cout << "RRRR";
		break;
	case 2:
	case 5:
		cout << "R   R";
		break;
	case 3:
	case 4:
		cout << "R    R";
		break;
	case 6:
		cout << "RRRR";
		break;
	case 7:
		cout << "R R";
		break;
	case 8:
		cout << "R  R";
		break;
	case 9:
		cout << "R   R";
		break;
	case 10:
		cout << "R    R";
		break;
	case 11:
		cout << "R     R";
		break;
	}
}
void printHomeScreenAndMenu() { // TODO Add a Menu
	const int colorSize = 5;
	int colors[colorSize] = {};

	srand(time(0));
	for (int i = 0; i < colorSize; ++i) {
		colors[i] = 1 + (rand() % 15);
	}

	for (int i = 1; i <= 3; ++i) {
		cout << endl;
	}

	int line = 1;
	while (line <= 11) {
		for (int i = 1; i <= 16; ++i) {
			cout << ' ';
		}

		printT(line, colors[0]);
		printI(colors[1]);
		printM(line, colors[2]);
		printE(line, colors[3]);
		printR(line, colors[4]);

		cout << endl;
		++line;
	}
}
void homeScreen() {
	printHomeScreenAndMenu();

	const int colorWhite = 15;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, colorWhite);

	int n;    // Seconds
	cin >> n; // TODO Make this long long and fix it in all files

	screenClear(); // TODO Make the Menu interactive like the End Screen

	int* timePtr = transformHoursMinutesSeconds(n);
	int hours = timePtr[0];
	int minutes = timePtr[1];
	int seconds = timePtr[2];

	printTimer(hours, minutes, seconds, n);
}