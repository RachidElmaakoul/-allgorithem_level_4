// prblem14_Date1IsEqualDate2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <string>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};

bool CheckDate1EqualDate2(stDate Date1, stDate Date2) {

    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
}

//mathod abu-hadhoud
bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
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

    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (CheckDate1EqualDate2(Date1, Date2))
        cout << "\n\nYes , Date1 is Equal Date2 ";
    else
        cout << "\n\nNo , Date1 is Not Equal Date2 ";

    
    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\n\nYes , Date1 is Equal Date2 ";
    else
        cout << "\n\nNo , Date1 is Not Equal Date2 ";





    system("pause>0");
    return 0;
}

