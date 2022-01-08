#include "print_seconds.h"
#include "print_numbers.h"
#include <Windows.h>
void printSeconds(const int seconds, const int lineNumber, int color1, int color2) {
	bool isItTheSecondDigit = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
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