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
 * File with a Function that sends for Printing the Digits of the Hours
 *
 */
#include "print_hours.h"
#include "print_numbers.h"
#include <Windows.h>
void printHours(int hours, int lineNumber, int tensOfNumberCount, bool isHoursLessThanTen, int color1, int color2) {
	bool isItTheSecondDigit = false;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE used for coloring of the output

	if (isHoursLessThanTen) { // If hours is a single digit a 0 gets printed before it
		SetConsoleTextAttribute(h, color2);
		print0(0, lineNumber, isItTheSecondDigit);
	}

	if (tensOfNumberCount == 1) { // When hours becomes a single Digit
		isItTheSecondDigit = true;
	}

	SetConsoleTextAttribute(h, color1); // Coloring of the digit

	switch (hours / tensOfNumberCount) { // What Digit gets sent for Printing
	case 0:
		print0(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 1:
		print1(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 2:
		print2(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 3:
		print3(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 4:
		print4(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 5:
		print5(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 6:
		print6(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 7:
		print7(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 8:
		print8(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	case 9:
		print9(hours / tensOfNumberCount, lineNumber, isItTheSecondDigit);
		break;
	}

	if (tensOfNumberCount / 10 != 0) { // If hours is != 0 in the next iteration
		printHours(hours % tensOfNumberCount, lineNumber, tensOfNumberCount / 10, isHoursLessThanTen, color2, color1 - 1);
	} // (The first Digit of Hours gets deleted | The same Line Number | The Number of tens decreases | Is hours a single digit | Coloring Integers)
}