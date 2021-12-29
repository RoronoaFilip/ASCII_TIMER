#include "print_hours.h"
#include "print_numbers.h"
void printHours(int hours, int lineNumber, int tensOfNumberCount, bool isHoursLessThanTen) {
	bool isItTheSecondDigit = false;
	if (isHoursLessThanTen) {
		print0(0, lineNumber, isItTheSecondDigit);
	}
	if (tensOfNumberCount == 1) {
		isItTheSecondDigit = true;
	}
	switch (hours / tensOfNumberCount) {
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
	if (tensOfNumberCount / 10 != 0) {
		printHours(hours % tensOfNumberCount, lineNumber, tensOfNumberCount / 10, isHoursLessThanTen);
	}
}