#include "print_minutes.h"
#include "print_numbers.h"
#include <Windows.h>
void printMinutes(const int minutes, const int lineNumber, const int color1, const int color2) {
	bool isItTheSecondDigit = false;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color1);

	switch (minutes / 10) {
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
	switch (minutes % 10) {
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