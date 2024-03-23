//

#include <iostream>
using namespace std;
void LeapYear(int Year) {
	if (Year % 400 == 0)
		cout << "\nYes, Year [" << Year << "] is a Leap Year .\n";
	 else if (Year % 4 == 0 && Year % 100 != 0)
		cout << "\nYes, Year [" << Year << "] is a Leap Year .\n";
	else
		cout << "Yes, Year [" << Year << "] is Not a Leap Year .\n";
}

//method abo_hadhoud
bool IsLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	
	 else if (year % 100 == 0)
		return false;
	
	 else if (year % 4 == 0) 
		return true;

	 else
		return false;
}
int ReadYear() {
	int Year = 0;
	cout << "Please enter a Year : ";
	cin >> Year;
	return Year;
}
int main()
{
	int year = ReadYear();
	LeapYear(year);

	if (IsLeapYear(year))
		cout << "\nYes, Year [" << year << "] is a Leap Year .\n";
	
	else
		cout << "Yes, Year [" << year << "] is Not a Leap Year .\n";

	system("pause>0");
	return 0;

}

