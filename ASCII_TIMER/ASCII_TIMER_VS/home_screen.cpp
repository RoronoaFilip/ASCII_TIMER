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
 * File with all Functions for the Home Screen
 *
 *
 */
#include "other_functions.h"
#include "print_timer.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;

const int colorWhite = 15;
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void printT(int line, int color) {
	// Pattern of 'T'
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
	// Pattern of 'I'
	SetConsoleTextAttribute(h, color);
	cout << "I  ";
}
void printM(int line, int color) {
	// Pattern of 'M'
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
	// Pattern of 'E'
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
	// Pattern of 'R'
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
void printHomeScreenAndMenu(bool InvalidEntry) {
	// Printing the Home Screen and Menu

	const int colorSize = 5;
	int colors[colorSize] = {}; // Array for random Colors

	srand(time(NULL));
	for (int i = 0; i < colorSize; ++i) {
		colors[i] = 1 + (rand() % 15); // The Elements never get the Value of the Color black, which is 0
	}

	for (int i = 1; i <= 4; ++i) {
		cout << endl;
	}

	// "TIMER" Text
	int line = 1;
	while (line <= 11) {
		for (int i = 1; i <= 16; ++i) {
			cout << ' ';
		}

		// Each Letter is colored randomly
		printT(line, colors[0]);
		printI(colors[1]);
		printM(line, colors[2]);
		printE(line, colors[3]);
		printR(line, colors[4]);

		cout << endl;
		++line;
	}

	// The Menu
	SetConsoleTextAttribute(h, colorWhite); // Now everything is white
	cout << endl;
	cout << endl;
	cout << endl;

	for (int i = 1; i <= 32; ++i) {
		cout << ' ';
	}

	cout << "Input Menu:";
	cout << endl;

	for (int i = 1; i <= 20; ++i) {
		cout << ' ';
	}

	cout << "> Enter an Amount of Time in Seconds";
	cout << endl;

	for (int i = 1; i <= 22; ++i) {
		cout << ' ';
	}

	cout << "> To exit the Program enter '0' ";
	cout << endl;

	if (!InvalidEntry) { // Print this if there isn't an invalid Entry
		for (int i = 1; i <= 32; ++i) {
			cout << ' ';
		}
		cout << "Your Input: ";
	}
	if (InvalidEntry) { // Print this if there is an invalid Entry
		cout << endl;
		for (int i = 1; i <= 22; ++i) {
			cout << ' ';
		}
		cout << "Invalid Entry! Please try again!";

		cout << endl;
		for (int i = 1; i <= 32; ++i) {
			cout << ' ';
		}
		cout << "Your Input: ";
	}
}
void homeScreen(bool InvalidEntry = false) {
	screenClear();

	printHomeScreenAndMenu(InvalidEntry); // Print "Text" and the Menu

	SetConsoleTextAttribute(h, colorWhite);

	char input[100]; // A String to determine if the Input is valid
	cin.getline(input, 101);

	if (!isInputCorrect(input)) { // Home Screen is printed with Invalid Entry Text
		screenClear();
		homeScreen(true);
	}

	int n = getNumber(input); // Transform string to integer

	if (n == 0) { // Exit Value
		screenClear();
		exit(0);
	}

	screenClear();

	int* timePtr = transformHoursMinutesSeconds(n); // Transform to hours|minutes|seconds
	int hours = timePtr[0];
	int minutes = timePtr[1];
	int seconds = timePtr[2];

	printTimer(hours, minutes, seconds, n);
}