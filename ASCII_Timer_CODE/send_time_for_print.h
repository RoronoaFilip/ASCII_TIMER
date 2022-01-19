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
 * File with the Declaration of the Functions that send for Printing the Digits of the Hours, Minutes and Seconds
 *
 */
#pragma once
#ifndef TIME_H
#define TIME_H

void printHours(int hours, int lineNumber, int tensOfNumberCount, bool isHoursLessThanTen, int color1, int color2);
void printMinutes(const int minutes, const int lineNumber, const int color1, const int color2);
void printSeconds(const int seconds, const int lineNumber, int color1, int color2);

#endif