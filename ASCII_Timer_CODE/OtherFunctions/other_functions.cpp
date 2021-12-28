#include "other_functions.hpp"
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
int tensOfNumberCount(int n) {
    int count = 1;
    for (int i = n; i > 0; i /= 10) {
        count *= 10;
    }
    count /= 10;
    return count;
}