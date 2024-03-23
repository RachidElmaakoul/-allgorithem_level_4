#include <iostream>
#include <string>
using namespace std;


struct stDate {
    short Day;
    short Month;
    short Year;
};
struct stPeriod {
    stDate StartPeriod;
    stDate EndPeriod;
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

bool IsDate1BeforDate2MethodTwo(stDate& Date1, stDate& Date2) {

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

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
    while (IsDate1BeforDate2MethodTwo(Date, Date1)) {
            Days++;

        Date = IncreaseDateByOneDay(Date);
    }
    return IncludeEndDay ? ++Days : Days;
}

int getPeriodLengthInDay(stPeriod Period , bool IncludeEnddate = false) {
    return GetDifferenceInDays(Period.StartPeriod, Period.EndPeriod, IncludeEnddate);
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

stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter start Date : ";
    Period.StartPeriod = ReadFullDate();
    cout << "\nEnter End Date : ";
    Period.EndPeriod = ReadFullDate();

    return Period;
}

int main()
{
    cout << "\nEnter Date1 : ";
    stPeriod Period = ReadPeriod();

        
   cout << "\nPeriod Length is : " << getPeriodLengthInDay(Period);
   cout << "\nPeriod Length is (Include End Date) : " << getPeriodLengthInDay(Period, true);
  
    

    system("pause>0");
    return 0;
}

