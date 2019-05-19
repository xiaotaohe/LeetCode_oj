#include<string>
#include<iostream>
using namespace std;

int main()
{
    string ret = "",str1 = "",str2 = "";
    getline(cin,str1);
    getline(cin,str2);
    for(int i = 0;i<str1.size();i++)
    {
        int find = str2.find(str1[i]);
        if(find == string::npos)
            ret += str1[i];
    }
    cout<<ret<<endl;
}