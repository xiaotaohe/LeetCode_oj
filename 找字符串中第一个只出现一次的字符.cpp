#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        bool flag = false;
        int ch[256] = {0};
        for(int i = 0;i<str.size();i++)
            ch[(unsigned char)str[i]]++;
        for(int i = 0;i<str.size();i++)
        {
            if(ch[(unsigned char)str[i]] == 1)
            {
                cout<<str[i]<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}