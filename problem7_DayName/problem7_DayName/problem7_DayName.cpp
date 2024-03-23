#include <iostream>
#include <string>
using namespace std;



int DayOfWeekOrder(short day,short Month , short Year) {
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
   return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
//Method abu_hadhoud
string DayShortName(short DayOfWeekOrder) {

    string NameDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDays[DayOfWeekOrder];
}

short ReadYear() {
    short year;
    cout << "please enter a year : ";
    cin >> year;
    return year;
}
short ReadMonth() {
    short Month;
    cout << "please enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadDay() {
    short Day;
    cout << "please enter a Day : ";
    cin >> Day;
    return Day;
}

void printDate(short Year,short Month , short Day) {

    string NameDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

    cout << "Date      : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order :  " << DayOfWeekOrder(Day, Month, Year) << endl;
    cout << "Name Day  : " << NameDays[DayOfWeekOrder(Day,Month,Year)] << endl;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\n\n";
    printDate(Year, Month, Day);

    //method Abu_hadhoud
    cout << "\n\nMethod abu_hadhoud\n";
    cout << "Date      : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order :  " << DayOfWeekOrder(Day, Month, Year) << endl;
    cout << "Name Day  : " << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;

    system("pause>0");
    return 0;
}

