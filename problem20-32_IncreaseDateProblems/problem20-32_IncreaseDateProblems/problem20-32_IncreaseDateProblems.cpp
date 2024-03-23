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

bool IsLastDay(stDate Date) {
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonth(short Month) {
    return   (Month == 12);
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

stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDay(Date))
    {
        if (IsLastMonth(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;

        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
        Date.Day++;

    return Date;
}
stDate IncreaseDateByXDays(short Days , stDate Date) {
    for (short i = 0; i < Days; i++)
    {
     Date =   IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByOneWeek( stDate Date) {
    for (short i = 0; i < 7; i++)
    {
     Date =   IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeek(short Week,stDate Date) {
    for (short i = 0; i < Week; i++)
    {
     Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
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

stDate IncreaseDateByXMonth(short Month ,stDate Date) {
    for (short i = 0; i < Month; i++)
    {
     Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYear(short Numbers ,stDate Date) {
    for (short i = 0; i < Numbers; i++)
    {
        Date = IncreaseDateByOneYear( Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short Years, stDate Date) {
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
    Date.Year += 10;
    return Date;
}
stDate IncreaseDateByXDecades(short Decade ,stDate Date) {
    for (short i = 0; i < Decade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date) {
    Date.Year += Decade * 10;
    return Date;
}
stDate IncreaseDateByOneCentury(stDate Date) {
    Date.Year += 100;
    return Date;
}
stDate IncreaseDateByXCentury(short Numbers ,stDate Date) {
    for (short i = 0; i < Numbers; i++)
    {
        Date = IncreaseDateByOneCentury( Date);
    }
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date) {
    Date.Year += 1000;
    return Date;
}


int main()
{

    stDate Date = ReadFullDate();

    Date = IncreaseDateByOneDay(Date);
    cout << "\n Date after adding One Day  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year; 
    
 Date = IncreaseDateByXDays(10,Date);
    cout << "\n Date after adding 10 Day  is           :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneWeek( Date);
    cout << "\n Date after adding One Week  is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXWeek(10, Date);
    cout << "\n Date after adding 2 Weeks  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

  Date = IncreaseDateByOneMonth( Date);
    cout << "\n Date after adding One Month is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXMonth(5, Date);
    cout << "\n Date after adding 5 Month  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
   
    Date = IncreaseDateByOneYear( Date);
    cout << "\n Date after adding One Year is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXYearsFaster(10, Date);  
    cout << "\n09-Adding 10 Years (faster) is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXYear(10, Date);
    cout << "\n Date after adding 10 Year  is          :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneDecade(Date);
    cout << "\n Date after adding One Decade is        :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXDecades(10, Date);
    cout << "\n Date after adding 10 Decades is        :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXDecadesFaster(10, Date);    
    cout << "\n12-Adding 10 Decade (faster) is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneCentury( Date);
    cout << "\n Date after adding One Year  is         :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;
     
    Date = IncreaseDateByXCentury(10, Date);
    cout << "\n Date after adding 10 century  is       :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;

     Date = IncreaseDateByOneMillennium( Date);
    cout << "\n Date after adding One Mellinerum  is   :  " << Date.Day << "/" << Date.Month << "/" << Date.Year;



    system("pause>0");
    return 0;
}

