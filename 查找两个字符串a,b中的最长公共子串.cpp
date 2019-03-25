#include<iostream>
using namespace std;
#include<string>

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        //默认str1最长
        if(str1.size()<str2.size())
           swap(str1,str2);
        //暴力匹配
        int max = 0;
        int len = 0;
        string ret = "";
        for(int i = 0;i<str2.size();i++)
        {
            for(int j = i+1;j<=str2.size();j++)
            {
                string str3 = str2.substr(i,j-i);
                if(str1.find(str3,0) != string::npos)
                    len = j - i;
                if(len>max)
                {
                    ret = str3;
                    max = len;
                }
            }
        }
        cout<<ret<<endl;
    }
   
    return 0;
}