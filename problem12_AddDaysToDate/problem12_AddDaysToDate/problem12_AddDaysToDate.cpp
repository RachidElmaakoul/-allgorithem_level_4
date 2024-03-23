#include <iostream>
#include <string>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};

bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 == 0);
}
short NumberOfDaysInAMonth(short Month, short year) {
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short PrintToTalDayFromBeginingOfYear(short Month, short Day, short Year) {
    short TotalDay = 0;
    for (short i = 1; i <= Month - 1; i++)
        TotalDay += NumberOfDaysInAMonth(i, Year);

    TotalDay += Day;
    return TotalDay;
}


stDate DateAddDays(short Days, stDate Date) {
    short RemainingDays = Days + PrintToTalDayFromBeginingOfYear(Date.Month, Date.Day, Date.Year);

    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
   MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    
    return Date;
}



short ReadDay() {
    short Day;
    cout << "please enter a Day : ";
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


short AddDaysToDate() {
    short AddDays = 0;
    cout << "enter How many days to add : ";
    cin >> AddDays;
    return AddDays;
}




int main()
{
  
    stDate Date = ReadFullDate();
      short Days = AddDaysToDate();
 
Date = DateAddDays(Days, Date);
    cout << "\n\nDate After Adding [" << Days << "] Days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
}

