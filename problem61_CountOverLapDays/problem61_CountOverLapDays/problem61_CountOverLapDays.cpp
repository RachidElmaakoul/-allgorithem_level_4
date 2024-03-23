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

enum enDateCompare {
    before = -1, Equal = 0, After = 1
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

bool IsDate1BeforDate2(stDate& Date1, stDate& Date2) {

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return !(IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
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
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) { 
    int Days = 0;
    while (IsDate1BeforDate2(Date1, Date2)) {
    Days++; Date1 = IncreaseDateByOneDay(Date1); 
    } 
    return IncludeEndDay ? ++Days : Days;
}

enDateCompare CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;

    return enDateCompare::before;
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) { 
    if (CompareDates(Period2.EndPeriod, Period1.StartPeriod) == enDateCompare::before || CompareDates(Period2.StartPeriod, Period1.EndPeriod) == enDateCompare::After)
        return false;
    else
        return true;
}
bool isDateInPeriod(stDate Date, stPeriod Period) {
    return !(CompareDates(Date, Period.StartPeriod) == enDateCompare::before || CompareDates(Date, Period.EndPeriod) == enDateCompare::After);
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false) {
    return GetDifferenceInDays(Period.StartPeriod, Period.EndPeriod, IncludeEndDate);
}
int CountOverlapDays(stPeriod Period1, stPeriod Period2) { 
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    if (Period1Length < Period2Length) {
        while (IsDate1BeforDate2(Period1.StartPeriod, Period1.EndPeriod)) {
            if (isDateInPeriod(Period1.StartPeriod, Period2))
                OverlapDays++; 
            
        Period1.StartPeriod = IncreaseDateByOneDay(Period1.StartPeriod);
        } 
    } else {
        while (IsDate1BeforDate2(Period2.StartPeriod, Period2.EndPeriod)) {
            if (isDateInPeriod(Period2.StartPeriod, Period1))
                OverlapDays++; 
        Period2.StartPeriod = IncreaseDateByOneDay(Period2.StartPeriod);
        }
    }
    return OverlapDays;
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
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Date2 : ";
    stPeriod Period2 = ReadPeriod();


 cout << "\nOverLap Days count Is : " << CountOverlapDays(Period1 , Period2);
    
 



    system("pause>0");
    return 0;
}

