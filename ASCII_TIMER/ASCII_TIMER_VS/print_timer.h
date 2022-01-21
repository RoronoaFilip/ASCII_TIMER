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
 * File with Declarations of Functions with the Algorithm for the Timer
 *
 *
 */
#pragma once
#ifndef PRINT_TIMER_H
#define PRINT_TIMER_H

void printTimer(int hours, int minutes, int seconds, int& n);
void lessThan10Sec(int seconds, int& n);
void printOnlySeconds(int seconds);
void printIt(int hours, int minutes, int seconds, int& n);

#endif