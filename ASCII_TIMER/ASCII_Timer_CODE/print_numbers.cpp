#include "print_numbers.h"
#include <iostream>
#include <Windows.h>
using namespace std;
const int colorGrey = 15;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void print0(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 11:
		cout << "0000000000 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
	case 7:
		cout << "0        0 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey); SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "0        0 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print1(int num, int lineNumber, bool isItTheSecondDigit) {
	cout << "1 ";
	if ((lineNumber == 4 || lineNumber == 7) && isItTheSecondDigit) {
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
	}
	else if (isItTheSecondDigit) {
		cout << "  ";
	}
}
void print2(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "2222222222 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 2:
	case 3:
	case 5:
		cout << "         2 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
		cout << "         2 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 7:
		cout << "2          ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 8:
	case 9:
	case 10:
		cout << "2          ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print3(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "3333333333 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
	case 7:
		cout << "         3 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "         3 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print4(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 2:
	case 3:
	case 5:
		cout << "4        4 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 6:
		cout << "4444444444 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
		cout << "4        4 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 7:
		cout << "         4 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "         4 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print5(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "5555555555 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 2:
	case 3:
	case 5:
		cout << "5          ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
		cout << "5          ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 7:
		cout << "         5 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "         5 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print6(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "6666666666 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 2:
	case 3:
	case 5:
		cout << "6          ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
		cout << "6          ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 7:
		cout << "6        6 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "6        6 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print7(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
		cout << "7777777777 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
	case 7:
		cout << "         7 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "         7 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print8(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "8888888888 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
	case 7:
		cout << "8        8 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "8        8 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}
void print9(int num, int lineNumber, bool isItTheSecondDigit) {
	switch (lineNumber) {
	case 1:
	case 6:
	case 11:
		cout << "9999999999 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 2:
	case 3:
	case 5:
		cout << "9        9 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	case 4:
		cout << "9        9 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	case 7:
		cout << "         9 ";
		if (isItTheSecondDigit) {
			SetConsoleTextAttribute(h, colorGrey);
			cout << "# ";
		}
		break;
	default:
		cout << "         9 ";
		if (isItTheSecondDigit) {
			cout << "  ";
		}
		break;
	}
}