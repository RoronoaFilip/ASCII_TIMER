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
 * File with main()
 * The Home Screen gets printed
 *
 */
#include "../.h/home_screen.h"

int main() {

	int value = homeScreen(); // Print the Home Screen

	if (value != 0) {
		while (value != 0) {
			value = homeScreen(); // Print the Home Screen
		}
	}

	return 0;
}