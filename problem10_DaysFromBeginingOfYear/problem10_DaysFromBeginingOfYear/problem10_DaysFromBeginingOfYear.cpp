#include <iostream>
#include <string>
using namespace std;




bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 == 0);
}
short NumberOfDaysInAMonth(short Month, short year) {
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
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

//short PrintToTalDayFromBeginingOfYear(short Month,short Day,short Year) {
//    short TotalDay = 0;
//    for (short i = 1; i <= Month; i++)
//    {
//        if (i != Month)
//            TotalDay += NumberOfDaysInAMonth(i,Year);
//    }
//    return TotalDay + Day;
//}
//method abu-hadhoud
short PrintToTalDayFromBeginingOfYear(short Month,short Day,short Year) {
    short TotalDay = 0;
    for (short i = 1; i <= Month - 1; i++)
            TotalDay += NumberOfDaysInAMonth(i,Year);
    
     TotalDay += Day;
     return TotalDay;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

cout << "\n\nNumber of Days From The Begining Of The Year is : "
   << PrintToTalDayFromBeginingOfYear(Month,Day,Year);



    system("pause>0");
    return 0;
}

