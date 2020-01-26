#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;


bool leap_year(int year){
    if(year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    else if (year % 400 == 0){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int year, month, day;
    char blk;
    bool leap;
    int non_leap_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //Take input
    cin >> year >> blk >> month >> blk >> day;
    if (leap_year(year)){
        if (day == leap_month[month - 1] && month != 12){
            month += 1;
            day = 1;
        }
        else if (month == 12 && day == 31) {
            year += 1;
            month = 1;
            day = 1;
        }
        else {
            day += 1;
        }
    }
    else {
        if (day == non_leap_month[month - 1] && month != 12){
            month += 1;
            day = 1;
        }
        else if (month == 12 && day == 31) {
            year += 1;
            month = 1;
            day = 1;
        }
        else {
            day += 1;
        }
    }
    printf("%d-%02d-%02d\n", year, month, day);
    //cout << year << setw(3) << setfill('-') << month << setw(3) << setfill('-') << day << endl;
    return 0;
}
