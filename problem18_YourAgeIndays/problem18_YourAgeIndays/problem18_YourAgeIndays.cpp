#pragma warning(disable : 4996)// you should pud this if was program befor a 2020

#include <iostream>
#include <string>
#include <ctime>
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


bool IsDate1LessThenDate2(stDate Date1, stDate Date2) {
    if (Date1.Month < Date2.Month || Date1.Day < Date2.Day || Date1.Year < Date2.Year)
        return true;

    return false;
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
int GetDifferenceInDays(stDate Date, stDate Date1, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1LessThenDate2(Date, Date1)) {
        Days++;
        Date = IncreaseDateByOneDay(Date);
    }
    return IncludeEndDay ? ++Days : Days;
}
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stDate GetSystemDate() {
    stDate Date1;

    time_t t = time(0);
    tm* Now = localtime(&t);

    Date1.Year = Now->tm_year + 1900;
    Date1.Month = Now->tm_mon + 1;
    Date1.Day = Now->tm_mday;
    return Date1;
}

int main()
{
    cout << "Please enter your Date1 Birth : \n ";
    stDate Date = ReadFullDate();
    stDate Date1 = GetSystemDate();



    cout << "\nYour Age is : " << GetDifferenceInDays(Date, Date1)  << " Day(s)";

    system("pause>0");
    return 0;
}

