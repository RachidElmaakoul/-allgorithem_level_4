
#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year) {
 return   (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int ReadYear() {
    int year = 0;
    cout << "please enter a year : ";
    cin >> year;
    return year;
}
int main()
{
    int year = ReadYear();

    if (isLeapYear(year))
        cout << "year [" << year << "] is a leap year .";
    else
         cout << "year [" << year << "] is not a leap year .";


   

    system("pause>0");
    return 0;
}

