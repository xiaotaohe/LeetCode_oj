// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    char ch[26] = {'V','W','X','Y','Z','A','B','C','D','E',
                   'F','G','H','I','J','K','L','M','N','O',
                   'P','Q','R','S','T','U'};
    string str;
    while(getline(cin,str))
    {
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] == ' ')
                continue;
            else
                str[i] = ch[str[i]-'A'];
        }
        cout<<str<<endl;
    }
    return 0;
}