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
 * File with a Functions that send for Printing the Digits of the Hours, Minutes and Seconds
 *
 */
#include "send_time_for_print.h"
#include "print_numbers.h"
#include <Windows.h>

const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE used for coloring of the output

void printHours(int hours, int lineNumber, int tensOfNumberCount, bool isHoursLessThanTen, int color1, int color2) {
	bool isItTheLastDigit = false;

	if (isHoursLessThanTen) { // If hours is a single digit a 0 gets printed before it
		SetConsoleTextAttribute(h, color2);
		print0(0, lineNumber, isItTheLastDigit);
	}

	if (tensOfNumberCount == 1) { // When hours becomes a single Digit
		isItTheLastDigit = true;
	}

	SetConsoleTextAttribute(h, color1); // Coloring of the digit

	switch (hours / tensOfNumberCount) { // What Digit gets sent for Printing
	case 0:
		print0(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 1:
		print1(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 2:
		print2(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 3:
		print3(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 4:
		print4(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 5:
		print5(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 6:
		print6(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 7:
		print7(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 8:
		print8(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	case 9:
		print9(hours / tensOfNumberCount, lineNumber, isItTheLastDigit);
		break;
	}

	if (tensOfNumberCount / 10 != 0) { // If hours is != 0 in the next iteration
		printHours(hours % tensOfNumberCount, lineNumber, tensOfNumberCount / 10, isHoursLessThanTen, color2, color1 - 1);
	} // (The first Digit of Hours gets deleted | The same Line Number | The Number of tens decreases | Is hours a single digit | Coloring Integers)
}
void printMinutes(const int minutes, const int lineNumber, const int color1, const int color2) {
	bool isItTheSecondDigit = false;

	SetConsoleTextAttribute(h, color1);

	switch (minutes / 10) { // Send the first Digit // Never Print # after it
	case 0:
		print0(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 1:
		print1(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 2:
		print2(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 3:
		print3(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 4:
		print4(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 5:
		print5(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 6:
		print6(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 7:
		print7(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 8:
		print8(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	case 9:
		print9(minutes / 10, lineNumber, isItTheSecondDigit);
		break;
	}

	isItTheSecondDigit = true;
	SetConsoleTextAttribute(h, color2);

	switch (minutes % 10) { // Send the seconds Digit // Always Print # after it
	case 0:
		print0(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 1:
		print1(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 2:
		print2(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 3:
		print3(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 4:
		print4(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 5:
		print5(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 6:
		print6(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 7:
		print7(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 8:
		print8(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	case 9:
		print9(minutes % 10, lineNumber, isItTheSecondDigit);
		break;
	}
}
void printSeconds(const int seconds, const int lineNumber, const int color1, const int color2) {
	bool isItTheSecondDigit = false;

	SetConsoleTextAttribute(h, color1);

	switch (seconds / 10) {
	case 0:
		print0(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 1:
		print1(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 2:
		print2(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 3:
		print3(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 4:
		print4(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 5:
		print5(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 6:
		print6(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 7:
		print7(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 8:
		print8(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	case 9:
		print9(seconds / 10, lineNumber, isItTheSecondDigit);
		break;
	}

	SetConsoleTextAttribute(h, color2);

	switch (seconds % 10) {
	case 0:
		print0(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 1:
		print1(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 2:
		print2(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 3:
		print3(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 4:
		print4(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 5:
		print5(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 6:
		print6(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 7:
		print7(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 8:
		print8(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	case 9:
		print9(seconds % 10, lineNumber, isItTheSecondDigit);
		break;
	}
}