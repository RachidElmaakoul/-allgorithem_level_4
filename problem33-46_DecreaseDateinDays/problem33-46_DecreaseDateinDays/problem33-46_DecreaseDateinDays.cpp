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


stDate DecreaseDateByOneDay(stDate Date) {
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }

    return Date;
}
stDate DecreaseDateByXDays(short Days, stDate Date) {
    for (short i = 0; i < Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
stDate DecreaseDateByOneWeek(stDate Date) {
    for (short i = 0; i < 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeek(short Week, stDate Date) {
    for (short i = 0; i < Week; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate DecreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
    // be 28/2/2022
    short NumberDaysOfCurrentinMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberDaysOfCurrentinMonth)
    {
        Date.Day = NumberDaysOfCurrentinMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonth(short Month, stDate Date) {
    for (short i = 0; i < Month; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate DecreaseDateByOneYear(stDate Date) {
    Date.Year--;
    return Date;
}
stDate DecreaseDateByXYear(short Numbers, stDate Date) {
    for (short i = 0; i < Numbers; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXYearsFaster(short Years, stDate Date) {
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
    Date.Year -= 10;
    return Date;
}
stDate DecreaseDateByXDecades(short Decade, stDate Date) {
    for (short i = 0; i < Decade * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date) {
    Date.Year -= Decade * 10;
    return Date;
}
stDate DecreaseDateByOneCentury(stDate Date) {
    Date.Year -= 100;
    return Date;
}
stDate DecreaseDateByXCentury(short Numbers, stDate Date) {
    for (short i = 0; i < Numbers; i++)
    {
        Date = DecreaseDateByOneCentury(Date);
    }
    return Date;
}
stDate DecreaseDateByOneMillennium(stDate Date) {
    Date.Year -= 1000;
    return Date;
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

    stDate Date = ReadFullDate();

    Date = DecreaseDateByOneDay(Date);
    cout << "\n Date after substruction   One Day is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDays(10, Date);
    cout << "\n Date after substruction  10 Day   is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n Date after substruction  One Week is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXWeek(10, Date);
    cout << "\n Date after substruction 10 Weeks  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n Date after substruction  One Month is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXMonth(5, Date);
    cout << "\n Date after substruction  5 Month  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneYear(Date);
    cout << "\n Date after substruction  One Year is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYearsFaster(10, Date);
    cout << "\n09-substruction  10 Years (faster) is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXYear(10, Date);
    cout << "\n Date after substruction  10 Year  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n Date after substruction  One Decade is        :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecades(10, Date);
    cout << "\n Date after substruction  10 Decades is        :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXDecadesFaster(10, Date);
    cout << "\n12-substruction  10 Decade (faster) is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneCentury(Date);
    cout << "\n Date after substruction  One Century is       :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n Date after substruction  One Mellinerum  is   :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;



    system("pause>0");
    return 0;
}

