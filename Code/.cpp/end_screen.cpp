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
 * File with all Functions for the End Screen
 *
 */
#include "../.h/end_screen.h"
#include "../.h/home_screen.h"
#include "../.h/other_functions.h"
#include "../.h/send_time_for_print.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void printEndScreen(bool invalidEntry) {
	// Printing the End Screen

	for (int i = 1; i <= 7; ++i) {
		cout << endl;
	}

	int hours = 0; // The Hours are already 0
	int minutes = 0; // The Minutes are already 0
	int seconds = 0; // The Seconds are already 0


	int line = 1;
	while (line != 12) { // Print 00:00:00 centered in red
		cout << ' ' << ' ';
		printHours(hours, line, 1, (hours < 10), colorRed, colorRed);
		printMinutes(minutes, line, colorRed, colorRed);
		printSeconds(seconds, line, colorRed, colorRed);
		++line;
		cout << endl;
	}

	cout << endl;

	SetConsoleTextAttribute(h, colorWhite);

	for (int i = 1; i <= 25; ++i) { // Print a Menu
		cout << ' ';
	}
	cout << "To return to Home Screen type: 1" << endl;
	for (int i = 1; i <= 32; ++i) {
		cout << ' ';
	}
	cout << "To exit type: 0" << endl;

	if (!invalidEntry) { // Print this if there isn't an invalid Entry
		for (int i = 1; i <= 34; ++i) {
			cout << ' ';
		}
		cout << "Your Entry: ";
	}
	if (invalidEntry) { // Print this if there is an invalid Entry
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
int endScreen(bool invalidEntry) {

	printEndScreen(invalidEntry); // Print the End Screen

	char input[charSize]; // A String to determine if the Input is valid
	cin.getline(input, charSize + 1);

	if (!isInputCorrect(input)) { // Print the End Screen with an Invalid Entry Text
		screenClear();
		invalidEntry = true;
		return endScreen(invalidEntry);
	}

	int num = getNumber(input); // Transform string to integer

	if (num == 1 || num == 0) {
		screenClear();
		return num;
	}
	else {
		screenClear();
		invalidEntry = true;
		return endScreen(invalidEntry); // Print the End Screen with an Invalid Entry Text
	}
}