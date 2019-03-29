#include<iostream>
using namespace std;
#include<string>

void yes(string& str)
{
    int ch[256] = {0};
    for(int i = 0;i<str.size();i++)
    {
        ch[str[i]]++;
    }
    int i = 0;
    for(i = 0;i<str.size();i++)
    {
        if(ch[str[i]] == 1)
            break;
    }
    if(i<str.size())
        cout<<str[i]<<endl;
    else
        cout<<-1<<endl;
}
int main()
{
    string str;
    while(cin>>str)
    {
        yes(str);
    }
    return 0;
}