//
// Created by BERKE on 8/20/2023.
//

#include "DateUtil.h"

const int dayOfMonths[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const char* months[] = {"","Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik"};


bool isLeapYear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void isLeapYearTest() {
    for (int year = 1900; year < 2200; year++) {
        if (isLeapYear(year)) {
            printf("%d ", year);
        }
    }
}

int getDays(int month, int year)
{
    return isLeapYear(year) && month == 2 ? 29 : dayOfMonths[month];
}

bool isValidDate(int day, int month, int year) {
    return 1 <= day && day <= 31 && 1 <= month && month <= 12 && 1 <= year && year <= 9999 &&
           day <= getDays(month, year);
}

void isValidDateTest() {
    int day, month, year;
    printf("Day?\n");
    scanf("%d", &day);
    printf("Month?\n");
    scanf("%d", &month);
    printf("Year?\n");
    scanf("%d", &year);
    if (isValidDate(day, month, year))
        printf("Gecerli Tarih");
    else
        printf("Gecersiz Tarih");
}

int getTotalDays(int year, int totalDays) {
    for (int y = 1900; y < year; ++y) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    return totalDays;
}

int getDayOfYear(int day, int month, int year) {
    if (!isValidDate(day, month, year)) {
        return -1;
    }

    int total = day;

    switch (month - 1) {
        case 11:
            total += 30;
        case 10:
            total += 31;
        case 9:
            total += 30;
        case 8:
            total += 31;
        case 7:
            total += 31;
        case 6:
            total += 30;
        case 5:
            total += 31;
        case 4:
            total += 30;
        case 3:
            total += 31;
        case 2:
            total += isLeapYear(year) ? 29 : 28;
        case 1:
            total += 31;
    }
    return total;
}

int getDayOfWeek(int day,int month,int year)
{
    int totalDays;

    if(year < 1900 || (totalDays = getDayOfYear(day,month,year)) == -1)
        return -1;
    return getTotalDays(year,totalDays) % 7;
}
void printDateByDayOfWeek(int day,int month,int year,int dayOfWeek)
{
    switch (dayOfWeek) {
        case 0:
            printf("%02d %s %04d Pazar\n",day,months[month],year);
            break;
        case 1:
            printf("%02d %s %04d Pazartesi\n",day,months[month],year);
            break;
        case 2:
            printf("%02d %s %04d Sali\n",day,months[month],year);
            break;
        case 3:
            printf("%02d %s %04d Carsamba\n",day,months[month],year);
            break;
        case 4:
            printf("%02d %s %04d Persembe\n",day,months[month],year);
            break;
        case 5:
            printf("%02d %s %04d Cuma\n",day,months[month],year);
            break;
        case 6:
            printf("%02d %s %04d Cumartesi\n",day,months[month],year);
            break;
    }
}

bool isWeekend(int day,int month,int year)
{
    int dayOfWeek = getDayOfWeek(day,month,year);

    return dayOfWeek == 0 || dayOfWeek == 6;
}

void printDateTR(int day,int month,int year)
{
    int dayOfWeek = getDayOfWeek(day,month,year);

    if(dayOfWeek == -1) {
        printf("Invalid Date");
        return;
    }

    printDateByDayOfWeek(day,month,year,dayOfWeek);

    isWeekend(day,month,year) ? printf("Hafta sonu geldi tekrar yaptin mi Omer?\n") : printf("Hafta Sonu yaklasiyor tekrar yap!!\n");
}

void printDateTRTest()
{
    int day,month,year;
    for(;;) {
        printf("Day?\n");
        scanf("%d", &day);
        printf("Month?\n");
        scanf("%d", &month);
        printf("Year?\n");
        scanf("%d", &year);
        if(!isValidDate(day,month,year)) {
            printf("Gecersiz Tarih");
            break;
        }
        printDateTR(day, month, year);
    }
}

