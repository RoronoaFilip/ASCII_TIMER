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
 * File with Declarations of the Functions for the Home Screen
 *
 */
#pragma once
#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

int homeScreen(bool InvalidEntry = false);
void printHomeScreenAndMenu(bool InvalidEntry);
void printT(int line, int color);
void printI(int color);
void printM(int line, int color);
void printE(int line, int color);
void printR(int line, int color);

#endif