// write your code here cpp
#include<iostream>
using namespace std;
#include<string>

long long get_num(long long n)
{
    if(n<=9)
        return n;
    long long temp = 0;
    while(n)
    {
        temp += n%10;
        n = n/10;
    }
    return get_num(temp);
}
int main()
{
   long long n = 0;
    string str;
    while(cin>>str)
    {
       n = 0;
       for(int i = 0;i<str.size();i++)
           n += str[i]-'0';
        cout<<get_num(n)<<endl;
    }
    return 0;
}