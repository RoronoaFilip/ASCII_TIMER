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
 * File with all Functions that don't fit anywhere else
 *
 */
#include "../Headers/other_functions.h"
#include <iostream>

using namespace std;

void screenClear() {

	// Clear the Console

	cout << "\033[;H"; // Moves Cursor to the top left
	cout << "\033[J"; // Clears the console

	// cout << "\x1B[2J\x1B[H"; // Alternative 
	//system("cls"); // Alternative
	// system("clear"); // Alternative
}
int tensOfNumberCount(const int n) {
	// Return the Count of Tens is the number

	int count = 1;
	for (int i = n; i > 0; i /= 10) {
		count *= 10;
	}
	count /= 10;

	return count;
}
int* transformHoursMinutesSeconds(int n) {
	// Transforming the Input

	int* timeArr = new int[3];
	timeArr[0] = 0; // Hours
	timeArr[1] = 0; // Minutes
	timeArr[2] = 0; // Seconds

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
bool isInputCorrect(char* input) {
	// Validate the Input

	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] < '0' || input[i] > '9') {
			return false;
		}
	}

	return true;
}
int getNumber(char* input) {
	// Transform string to integer

	int number = 0;
	for (int i = 0; input[i] != '\0'; ++i) {
		number = number * 10 + (input[i] - '0');
	}

	return number;
}
int countOfOnes(int hours, int minutes, int seconds) {
	// Get the Count of Ones

	int count = 0;
	while (hours > 0) {
		if (hours % 10 == 1) {
			++count;
		}
		hours /= 10;
	}
	while (minutes > 0) {
		if (minutes % 10 == 1) {
			++count;
		}
		minutes /= 10;
	}
	while (seconds > 0) {
		if (seconds % 10 == 1) {
			++count;
		}
		seconds /= 10;
	}

	return count;
}