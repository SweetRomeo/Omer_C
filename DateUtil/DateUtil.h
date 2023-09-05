//
// Created by BERKE on 8/20/2023.
//
//multiable including guard

#ifndef UNTITLED4_DATEUTIL_H
#define UNTITLED4_DATEUTIL_H
#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year);
void isLeapYearTest();
bool isValidDate(int day,int month,int year);
void isValidDateTest();
int getTotalDays(int year,int totalDays);
int getDayOfYear(int day,int month,int year);
void printDateByDayOfWeek(int day,int month,int year,int dayOfWeek);
void printDateTR(int day,int month,int year);
int getDayOfWeek(int day,int month,int year);
void printDateTRTest(void);
#endif //UNTITLED4_DATEUTIL_H
