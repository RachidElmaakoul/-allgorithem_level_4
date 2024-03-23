#pragma warning(disable : 4996)// you should pud this if was program befor a 2020


#include <iostream>
#include <string>
using namespace std;

struct stDate {
    short Day ;
    short Month ;
    short Year ;
};
bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 == 0);
}

bool IsDate1BeforeDate2(stDate Date, stDate Date1) {
    return  (Date.Year < Date1.Year) ? true : ((Date.Year == Date1.Year) ?(Date.Month < Date1.Month ? true :(Date.Month == Date1.Month ? Date.Day < Date1.Day : false)) : false);
}

short NumberOfDaysInAMonth(short Month, short year) {
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
return (Month == 12);
 }

 stDate IncreaseDateByOneDay(stDate Date) {
     if (IsLastDayInMonth(Date)) { 
         if (IsLastMonthInYear(Date.Month)) {
             Date.Month = 1; 
             Date.Day = 1;
             Date.Year++;
         } 
         else {
             Date.Day = 1;
             Date.Month++;
         }
     } 
     else {
         Date.Day++;
     } 
     return Date; 
}
int GetDifferenceInDays(stDate Date, stDate Date1, bool IncludeEndDay = false) { 
    int Days = 0;
    while (IsDate1BeforeDate2(Date, Date1)) {
    Days++; 
    Date = IncreaseDateByOneDay(Date);
    }
    return IncludeEndDay ? ++Days : Days; 
}

int DayOfWeekOrder(short day, short Month, short Year) {
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
int DayOfWeekOrder(stDate Date) {
    return DayOfWeekOrder(Date.Day,Date.Month,Date.Year);
}

string DayShortName(short DayOfWeekOrder) {

    string NameDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDays[DayOfWeekOrder];
}

stDate GetSystemDate() {
    stDate Date;

    time_t t = time(0);
    tm* Now = localtime(&t);

    Date.Year = Now->tm_year + 1900;
    Date.Month = Now->tm_mon + 1;
    Date.Day = Now->tm_mday;
    return Date;
}

bool IsEndOfWeek(stDate Date ) {
    short DayIndex = DayOfWeekOrder(Date);
    return   DayIndex == 0;
}
bool IsWeekEnd(stDate Date ) {
    short DayIndex = DayOfWeekOrder(Date);
    return   (DayIndex == 0 || DayIndex == 6);
}
bool IsBusinessDay(stDate Date ) {
 /*   short DayIndex = DayOfWeekOrder(Date);
    return   (DayIndex < 6 || DayIndex >0);*/

    //shorter method is to invert the IsWeekEnd: this will save updating code.
    return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(stDate Date) {
    /*short Counter = 0;
    while (!IsEndOfWeek(Date)){
        Counter++;
        Date.Day++;
    }
    return Counter;*/

    //shorter method and better
    return  6 - DayOfWeekOrder(Date) ;
}
short DaysUntilTheEndOfMonth(stDate Date) {
   /* short Counter = 0;
    while (Date.Day != NumberOfDaysInAMonth(Date.Month,Date.Year)){
  
        Date.Day++;
        Counter++;
    }
    return Counter;*/

    //Method Abu-Hadhoud
    stDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date,EndOfMonthDate,true);
}
short DaysUntilTheEndOfYear(stDate Date) {
   /* short TotalDay = 0;
    for (short i = Month - 1; i < 12 ; i++)
        TotalDay += NumberOfDaysInAMonth(i, Year);

    TotalDay -= Day;
    return TotalDay;*/

    //Method Abu-Hadhoud
    stDate EndOfMonthDate;

    EndOfMonthDate.Day = 31;
    EndOfMonthDate.Month = 12;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}


int main()
{
 

    stDate Date = GetSystemDate();
   

    cout << "Today Is " << DayShortName(Date.Day) << " , " <<  Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nis it End Of Week?";
    if (IsEndOfWeek(Date))
        cout << "\nYes, End Of Week";
    else 
        cout << "\nNo, Not End Of Week";
    
    
    cout << "\n\nis it WeekEnd?";
    if (IsWeekEnd(Date))
        cout << "\nYes, it is a WeekEnd";
    else 
        cout << "\nNo, Not a WeekEnd";
    

     cout << "\n\nis it Business Day?";
    if (IsBusinessDay(Date))
        cout << "\nYes, it is a Business Day";
    else 
        cout << "\nNo, Not a Business Day";
    



    
    cout << "\n\n\n Days Until The end Of Week : " << DaysUntilTheEndOfWeek(Date) << " Day(s)";
    cout << "\n\n Days Until The end of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s)";
    cout << "\n\n Days Until The end of Year : " << DaysUntilTheEndOfYear(Date) << " Day(s)";

    

    system("pause>0");
    return 0;
}

