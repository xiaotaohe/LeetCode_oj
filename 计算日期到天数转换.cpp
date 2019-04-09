#include<iostream>
using namespace std;
int iConverDateToDay(int year,int month,int day)
{
//判断年月的合法性
    int num = 0;
    if(year<0 || month<0 || month>12)
        return -1;
    int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        bool leap = false;
    //判断是否为闰年
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
        leap = true;
    if(leap)
        monthday[2] = 29;
    //判断天数的合法性
    if(day<0 || day>monthday[month])
        return -1;
    for(int i = 1;i<month;i++)
    {
        num += monthday[i];
    } 
    num += day;
    cout<<num<<endl;
    return 0;
}
int main()
{
    int year,month,day;
    while(cin>>year>>month>>day)
    {
        iConverDateToDay(year,month,day);
    }
    return 0;
}