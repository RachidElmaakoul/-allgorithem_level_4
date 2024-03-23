#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short ReadYear() {
    short Year;
    cout << "please enter a year : ";
    cin >> Year;
    return Year;
}
short NumberOfDaysInAYear(short Year) {
    return (isLeapYear(Year)) ? 366 : 365;
}
int NumberOfHouresInAYear(short Year) {
    return NumberOfDaysInAYear( Year) * 24;
}
int NumberOfMinutesInAYear(short Year) {
    return NumberOfHouresInAYear( Year) * 60;
}
int NumberOfSecondsInAYear(short Year) {
        return NumberOfMinutesInAYear( Year) * 60;
}

int main()
{
    short Year = ReadYear();
    short NormalYear = 365;

    if (isLeapYear(Year))
    {
        NormalYear++;
    }
    cout << "\nNumber of Day     in Year [" << Year << "]  is : " << NormalYear;
    cout << "\nNumber of Houres  in Year [" << Year << "]  is : " << NormalYear * 24;
    cout << "\nNumber of Minutes in Year [" << Year << "]  is : " << NormalYear * 24 * 60;
    cout << "\nNumber of Seconds in Year [" << Year << "]  is : " << NormalYear * 24 * 60 *60;
      

        cout << endl << "\n\n";

        //method abu-hadhoud
        cout << "\nNumber of Day     in Year [" << Year << "]  is : " 
            << NumberOfDaysInAYear(Year);
        cout << "\nNumber of Houres  in Year [" << Year << "]  is : "
            << NumberOfHouresInAYear(Year);
        cout << "\nNumber of Minutes in Year [" << Year << "]  is : "
            << NumberOfMinutesInAYear(Year);
        cout << "\nNumber of Seconds in Year [" << Year << "]  is : "
            << NumberOfSecondsInAYear(Year) ;

    system("pause>0");
    return 0;
}

