#include <iostream>
#include <string>
using namespace std;


bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInAMonth(short Month , short year ) {

 
    if (isLeapYear(year) && Month == 2) {
        return 29;
    }
     if (!isLeapYear(year) && Month == 2) {
        return 28;
    }
    return ( Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10|| Month == 12) ? 31 : 30;
}
int NumberOfHouresInAMonth(short Month , short year) {
    return NumberOfDaysInAMonth(Month,year) * 24;
}
int NumberOfMinutesInAMonth(short Month , short year) {
    return NumberOfHouresInAMonth(Month,year) * 60;
}
int NumberOfSecondsInAMonth(short Month , short year) {
    return NumberOfMinutesInAMonth(Month,year) * 60;
}
//method abu-hadhoud
short NumberOfDaysInAMonth_MethodAbuHadhoud(short Month , short year) {
    if (Month < 1 || Month > 12)
        return 0;
    
    if (Month == 2)
        return isLeapYear(year) ? 29 : 28;

    short arr12Month[7] = { 1,3,5,7,8,10,12 };

    for (short i = 0; i < 7 ; i++)
    {
        if (arr12Month[i - 1] == Month)
            return 31;
    }
    return 30;

}
int NumberOfHouresInAMonth_abu_hadhoud(short Month, short year) {
    return NumberOfDaysInAMonth_MethodAbuHadhoud(Month, year) * 24;
}
int NumberOfMinutesInAMonth_abu_hadhoud(short Month, short year) {
    return NumberOfHouresInAMonth_abu_hadhoud(Month, year) * 60;
}
int NumberOfSecondsInAMonth_abu_hadhoud(short Month, short year) {
    return NumberOfMinutesInAMonth_abu_hadhoud(Month, year) * 60;
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
 


    cout << "\nNumber of Day     in Month [" << Month << "]  is : "
        << NumberOfDaysInAMonth(Month,year);
    cout << "\nNumber of Houres  in Month [" << Month << "]  is : "
        << NumberOfHouresInAMonth(Month,year);
    cout << "\nNumber of Minutes in Month [" << Month << "]  is : "
        << NumberOfMinutesInAMonth(Month ,year);
    cout << "\nNumber of Seconds in Month [" << Month << "]  is : "
        << NumberOfSecondsInAMonth(Month , year); 
    

    //method abu_hadhoud
    cout << "\n\n\nNumber of Day     in Month [" << Month << "]  is : "
        << NumberOfDaysInAMonth_MethodAbuHadhoud(Month, year);
    cout << "\nNumber of Houres  in Month [" << Month << "]  is : "
        << NumberOfHouresInAMonth_abu_hadhoud(Month,year);
    cout << "\nNumber of Minutes in Month [" << Month << "]  is : "
        << NumberOfMinutesInAMonth_abu_hadhoud(Month ,year);
    cout << "\nNumber of Seconds in Month [" << Month << "]  is : "
        << NumberOfSecondsInAMonth_abu_hadhoud(Month , year);

    system("pause>0");
    return 0;
}

