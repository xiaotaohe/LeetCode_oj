#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}