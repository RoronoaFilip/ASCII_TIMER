#include "other_functions.h"
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
bool isInputCorrect(string input) {

	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] == ' ') {
			continue;
		}
		if (input[i] < '0' || input[i] > '9') {
			return false;
		}
	}
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] >= '0' && input[i] <= '9') {
			return true;
		}
	}
	return false;
}
int getNumber(string input) {
	int number = 0;
	for (int i = 0; input[i] != '\0'; ++i) {
		if (input[i] == ' ') {
			continue;
		}
		number = number * 10 + (input[i] - '0');
	}
	return number;
}