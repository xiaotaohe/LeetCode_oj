//方法1
#if 0
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
#endif

//方法2：
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1,str2,ret;
    getline(cin,str1);
    getline(cin,str2);
    size_t find;
    find = str1.find_first_of(str2);
    while(find != string::npos)
    {
        str1.erase(find,1);
        find = str1.find_first_of(str2,find);
    }
    cout<<str1<<endl;
}