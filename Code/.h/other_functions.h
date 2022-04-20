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
 * File with Declarations of the Functions that don't fit anywhere else
 * This File also contains all the global Constants
 *
 */
#pragma once
#include<Windows.h>

using namespace std;

#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

const int charSize = 100; // For the Input 
const int colorYellow = 14; // Value of the Color Yellow
const int colorRed = 12; // Value of the Color Red
const int colorWhite = 15; // Value of the Color White
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // For Coloring

void screenClear();
int tensOfNumberCount(int n);
int* transformHoursMinutesSeconds(int n);
bool isInputCorrect(char* input);
int getNumber(char* input);
int countOfOnes(int hours, int minutes, int seconds);

#endif