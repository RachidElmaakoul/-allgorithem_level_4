// problem15_LastDay-LastMonth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



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
    return (Date.Day == NumberOfDaysInMonth(Date.Year,Date.Month));
}

bool IsLastMonth(short Month) {
    return   (Month == 12) ;
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





int main()
{

    stDate Date = ReadFullDate();

       if (IsLastDay(Date))
        cout << "\nYes , Day  is Last Day in Month ";
    else
        cout << "\n\No , Day  is Not Last Day In Month ";



    if (IsLastMonth(Date.Month))
        cout << "\n\nYes , Month  is Last Month In Year ";
    else
        cout << "\n\No , Month  is Not Last Month In Year ";


    system("pause>0");
    return 0;
}

