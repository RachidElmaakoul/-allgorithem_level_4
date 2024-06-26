

#include <iostream>
#include <string>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};

enum enDateCompare {
    befor = -1, Equal = 0, After = 1
};

bool IsDate1BeforDate2MethodTwo(stDate& Date1, stDate& Date2) {

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return !(IsDate1BeforDate2MethodTwo(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enDateCompare ComparesDates(stDate Date1,stDate Date2) {
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;

    return enDateCompare::befor;
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
    cout << "\nEnter Date1 : ";
    stDate Date1 = ReadFullDate();
    cout << "\nEnter Date2 : ";
    stDate Date2 = ReadFullDate();


        cout << "\n\nCompare Result  : " << ComparesDates(Date1,Date2);



    system("pause>0");
    return 0;
}

