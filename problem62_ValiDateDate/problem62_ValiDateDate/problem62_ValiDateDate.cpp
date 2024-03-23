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

bool IsVaLidateDate(stDate Date) {
    if (Date.Day < 1 || Date.Day > 31)
        return false;
    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year)) {
            if (Date.Day > 29)
                return false;
        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }

    short DayInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > DayInMonth)
        return false;

   
    return true;
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
    cout << "\nEnter Date : ";
    stDate Date = ReadFullDate();

        if (IsVaLidateDate(Date))
        cout << "\nYes, Date is a Valide Date ; ";
    else
        cout << "\nNo, Date is a Not Valide Date ; ";

    



   





    system("pause>0");
    return 0;
}

