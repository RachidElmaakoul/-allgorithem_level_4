#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


struct stDate {
    int Day;
    int Month;
    int Year;
};

vector <string> splitString(string s1, string delim) {
    vector <string> SplitString;
    string word; // defind a string variable 
    short pos = 0;
    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, pos);
        if (word != "")
        {
            SplitString.push_back(word);
        }
        s1.erase(0, pos + delim.length()); // erase() until positon and move to next word.
    }
    if (s1 != "")
    {
        //cout << s1 << endl; //it print last word of the string
        SplitString.push_back(s1);
    }
    return SplitString;
}

stDate StringToDate(string DateString) {
    stDate Date;
    vector <string> vDate;

    vDate = splitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}
string DateToString(stDate Date) { 
    return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year); 
}

string ReplaceWordInString(string s1 , string stringToreplace,string sReplaceto) {

    short pos = s1.find(stringToreplace);

    while (pos != std::string::npos)
    {
        s1 = s1.replace(pos, stringToreplace.length(),sReplaceto);
         pos = s1.find(stringToreplace);
    }
    return s1;
}

string FormateDate(stDate Date,string FormatDate = "dd/mm/yyyy") {
    string FormatDateToString = "";

    FormatDateToString = ReplaceWordInString(FormatDate, "dd", to_string(Date.Day));
    FormatDateToString = ReplaceWordInString(FormatDateToString, "mm", to_string(Date.Month));
    FormatDateToString = ReplaceWordInString(FormatDateToString, "yyyy", to_string(Date.Year));
    return FormatDateToString;
}
//
//void PrintFormatDate(stDate Date) {
//    cout << endl << to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
//    cout << endl << to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year);
//    cout << endl << to_string(Date.Year) + "/" + to_string(Date.Month) + "/" + to_string(Date.Day);
//    cout << endl << to_string(Date.Day) + "-" + to_string(Date.Month) + "-" + to_string(Date.Year);
//    cout << endl << to_string(Date.Year) + "-" + to_string(Date.Month) + "-" + to_string(Date.Day);
//    cout << "\nDay : " << to_string(Date.Day) + ", Month : " + to_string(Date.Month) + ", Year : " + to_string(Date.Year);
//
//}
string ReadString() {
    string Text;
    cout << "please enter Date : ";
    getline(cin >> ws, Text);
    return Text;
}

int main()
{
    string Text = ReadString();
    stDate Date = StringToDate(Text);
  
    //PrintFormatDate(Date);
    cout << "\n" << FormateDate(Date) << "\n"; 
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";   
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";  
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n"; 
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";   
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;
}

