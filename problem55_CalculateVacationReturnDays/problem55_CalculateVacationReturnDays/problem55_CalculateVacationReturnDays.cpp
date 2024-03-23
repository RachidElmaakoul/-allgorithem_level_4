


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
int DayOfWeekOrder(short day, short Month, short Year) {
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
int DayOfWeekOrder(stDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder) {

    string NameDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDays[DayOfWeekOrder];
}
bool IsWeekEnd(stDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    return   (DayIndex == 0 || DayIndex == 6);
}
bool IsBusinessDay(stDate Date) {
    return   !IsWeekEnd(Date);
}
int GetDifferenceInDays(stDate Date, stDate Date1, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1LessThenDate2(Date, Date1)) {
        if (IsWeekEnd(Date))
            Days++;

        Date = IncreaseDateByOneDay(Date);
    }
    return IncludeEndDay ? ++Days : Days;
}
short ReadDay() {
    short Day;
    cout << "please enter a Day   : ";
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
    cout << "please enter a year  : ";
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
// Method Abu-Hadhoud
stDate CalculateNumberOfVacation(stDate DateFrom, short VacationDays) {
    short WeekendCounter = 0;

      
    for (short i = 1; i < VacationDays + WeekendCounter; i++)
    {
        if (IsWeekEnd(DateFrom))
        {
            WeekendCounter++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

 
    return  DateFrom;
}
short ReadNumberVacation() {
    short Days = 0;
    cout << "\nPlease enter Vacation Day : ";
    cin >> Days;
    return Days;
}
int main()
{
    cout << "\nVacation Started : \n";
    stDate DateFrom = ReadFullDate();

  
    short VacationDays =  ReadNumberVacation();

    stDate ReturnDays =  CalculateNumberOfVacation(DateFrom, VacationDays);

    cout << "\nReturn Date : " << DayShortName(DayOfWeekOrder(ReturnDays));
    cout << " , " << ReturnDays.Day << "/" << ReturnDays.Month << "/" << ReturnDays.Year;




   





    system("pause>0");
    return 0;
}

