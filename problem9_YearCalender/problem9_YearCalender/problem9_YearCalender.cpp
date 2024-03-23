#include <iostream>
#include <string>
using namespace std;


int DayOfWeekOrder(short day, short Month, short Year) {
    int a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder) {

    string NameDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDays[DayOfWeekOrder];
}
string NameMonths(short NumberOfMonth) {

    string NameDays[12] = { "Jan","Feb","March","April","May","Jone","July" ,"Aug","Sep","Oct","Nov","Dec" };
    return NameDays[NumberOfMonth];
}
bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 == 0);
}
short NumberOfDaysInAMonth(short Month, short year) {
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
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
void PrintMonthCalendar(short Year, short Month) {
    int DaysOfMonth, Current;

    Current = DayOfWeekOrder(1, Month, Year);
    DaysOfMonth = NumberOfDaysInAMonth(Month, Year);

    printf("\n________________%s_________________\n\n", NameMonths(Month - 1).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    short i;
    for (i = 0; i < Current; i++)
        printf("     ");
    for (short j = 1; j <= DaysOfMonth; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n_________________________________\n");
}

void PrintCalendarYear(short Year) {
        printf("\n___________________________________\n\n");
        printf("           Calendar - %d\n",Year);
        printf("______________________________________\n");
  for (short i = 1; i <= 12; i++)
         PrintMonthCalendar(Year, i);
   
}

int main()
{
    short Year = ReadYear();
    cout << "\n\n";
    PrintCalendarYear(Year);



    system("pause>0");
    return 0;
}

