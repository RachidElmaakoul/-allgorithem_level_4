#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


struct stDateAbu_Hadhoud {
    int Day;
    int Month;
    int Year;
};
struct stDate {
    string Day;
    string Month;
    string Year;
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
stDate StringToDate(vector <string> vString) {
    stDate Date;
 
        Date.Day = vString[0];
        Date.Month = vString[1];
        Date.Year = vString[2];
    
  return Date;
}
string DateToString(   stDate Date , string Delim) {
    string String;
 
    String += Date.Day + Delim;
    String += Date.Month + Delim;
    String += Date.Year ;
    
  return String;
}
//Method abu-Hahoud
stDateAbu_Hadhoud StringToDate1(string DateString) {
    stDateAbu_Hadhoud Date;
    vector <string> vDate;

    vDate = splitString(DateString, "/");

        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
    
  return Date;
}
string DateToString1(stDateAbu_Hadhoud Date ) {
  return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
string ReadString() {
    string Text;
    cout << "please enter Date : ";
    getline(cin, Text);
    return Text;
}

int main()
{
    string Text = ReadString();
    stDateAbu_Hadhoud Date1 = StringToDate1(Text);

    vector <string> vDate;
    vDate = splitString(Text, "/");
    stDate Date = StringToDate(vDate);

  
    cout << "Day   : "<< Date.Day << "\n";
    cout << "Month : "<<  Date.Month << "\n";
    cout << "Year  : "<< Date.Year << "\n";  
      cout << "\n\nYou Entered : " << DateToString(Date, "/");
    
    
     //method abu-hadhoud
    cout << "\n\n\nDay   : "<< Date1.Day << "\n";
    cout << "Month : "<<  Date1.Month << "\n";
    cout << "Year  : "<< Date1.Year << "\n";
    cout << "\n\nYou Entered : " << DateToString1(Date1);

    system("pause>0");
    return 0;
}

