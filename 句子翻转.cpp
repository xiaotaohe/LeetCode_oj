#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    //整个句子翻转
    reverse(str.begin(),str.end());
    
    //单词逐个翻转
    string :: iterator start = str.begin();
    string :: iterator end = str.begin();
    while(start != str.end())
    {
        end = start;
        while(end != str.end() && *end != ' ')
            end++;
        reverse(start,end);
        if(end != str.end())
            start = end+1;
        else
            start = end;
    }
    cout<<str<<endl;
    return 0;
}