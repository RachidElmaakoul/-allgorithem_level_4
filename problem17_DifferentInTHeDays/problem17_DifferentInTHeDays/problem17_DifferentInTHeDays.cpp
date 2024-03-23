


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
int GetDifferenceInDays(stDate Date , stDate Date1 ,bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1LessThenDate2(Date, Date1)) {
        Days++;
        Date = IncreaseDateByOneDay(Date);
    }
    return IncludeEndDay ? ++Days : Days;
}


int main()
{
    stDate Date = ReadFullDate();
    stDate Date1 = ReadFullDate();


cout << "\nDifference is : " << GetDifferenceInDays(Date, Date1) << "Day(s)";
cout << "\nDifference (Include end Day ) is : " << GetDifferenceInDays(Date, Date1,true) << "Day(s)";

    system("pause>0");
    return 0;
}

