#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> str2num = {
    {'0',13},
    {'1',1},
    {'2',2},
    {'3',3},
    {'4',5},
    {'5',4},
    {'6',4},
    {'7',2},
    {'8',2},
    {'9',2}
};
bool isLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMonthDays(int month, int year){
   int mday[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if(isLeap(year)){
       mday[1] = 29;
   }
   return mday[month - 1];
}

int main(){
    int ans = 0;
    for(int year = 2000;year<=2024;year++){
        for(int month = 1;month<=12;month++){
            for(int day = 1;day<=getMonthDays(month,year);day++){
                if (year > 2024 || (year == 2024 && month > 4) || (year == 2024 && month == 4 && day > 13)) {
                                continue;
                            }
                char buffer[9];
                snprintf(buffer,sizeof(buffer), "%04d%02d%02d", year, month, day);
                string date(buffer);
                int sum = 0;
                for(char c :date){
                    sum += str2num[c];
                }
                if(sum>50){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
