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
 *
 */
#pragma once
#include <iostream>
using namespace std;
#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H
void screenClear();
int tensOfNumberCount(int n);
int *transformHoursMinutesSeconds(int n);
bool isInputCorrect(string input);
int getNumber(string input);
int countOfOnes(int hours, int minutes, int seconds);
#endif