// problem16_increaseDateByOneDay.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
#include <string>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};

bool IsLeapYear(short Year) {
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}
short NumberOfDaysInMonth(short Year, short Month) {

    if (Month < 1 || Month > 12) {
        return 0;
    }

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDay(stDate Date) {
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonth(short Month) {
    return   (Month == 12);
}


short ReadDay() {
    short Day;
    cout << "\nplease enter a Day : ";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Month;
    cout << "please enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadYear() {
    short year;
    cout << "please enter a year : ";
    cin >> year;
    return year;
}

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stDate IncreaseDateByOneDay(stDate Date) {



    if (IsLastDay(Date))
    {
        if (IsLastMonth(Date.Month)) {
  Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
          
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
        Date.Day++;
    
    return Date;
}



int main()
{

    stDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);

    cout << " Date after adding One Day  is :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
}

