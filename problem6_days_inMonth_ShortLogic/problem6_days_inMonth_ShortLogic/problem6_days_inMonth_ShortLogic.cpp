#include <iostream>
#include <string>
using namespace std;


bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(short Month, short year) {
    if (Month < 1 || Month > 12 )
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}


short ReadMonth() {
    short Month;
    cout << "please enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadYear() {
    short Year;
    cout << "please enter a year : ";
    cin >> Year;
    return Year;
}

int main()
{
    short year = ReadYear();
    short Month = ReadMonth();



    cout << "\nNumber of Day in Month [" << Month << "]  is : "
        << NumberOfDaysInAMonth(Month, year);
 

    system("pause>0");
    return 0;
}

