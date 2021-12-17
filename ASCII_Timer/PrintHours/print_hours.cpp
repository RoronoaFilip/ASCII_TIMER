#include "print_hours.h"
#include "../PrintNumbers/print_numbers.h"
void printHours(int hours, int lineNumber) {
    switch (hours) {
    case 0:
        print0(hours, lineNumber);
        break;
    case 1:
        print1(hours, lineNumber);
        break;
    case 2:
        print2(hours, lineNumber);
        break;
    case 3:
        print3(hours, lineNumber);
        break;
    }
}