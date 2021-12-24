#include "../OtherFunctions/other_functions.cpp"
#include <iostream>
using namespace std;

int main() {
    int n; // Seconds
    cin >> n;
    screenClear();
    int *timePtr = transformHoursMinutesSeconds(n);
    int hours = timePtr[0];
    int minutes = timePtr[1];
    int seconds = timePtr[2];

    printTimer(hours, minutes, seconds, n);

    return 0;
}