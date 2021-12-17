#include <iostream>
using namespace std;
int main() {
    int n; // Seconds
    cin >> n;
    int copyOfn = n;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    if (n < 60) {
        seconds = n;
    } else {
        for (int i = n; i > 0; i -= 60) {
            if (copyOfn >= 60) {
                ++minutes;
            }
            copyOfn -= 60;
            if (minutes == 60) {
                minutes = 0;
                ++hours;
            }
        }
        if (copyOfn != 0) {
            seconds = 60 + copyOfn;
        }
    }
    cout << hours << " " << minutes << " " << seconds;
    // TODO Create a function that prints the numbers
    return 0;
}