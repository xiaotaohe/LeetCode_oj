#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#if 0
//1.方法1：自己实现reverse接口
void reverse(string& str,int left,int right)
{
    while(left<right)
    {
        swap(str[left],str[right]);
        left++;
        right--;
    }
}
int main()
{
    string str;
    getline(cin,str);
    reverse(str,0,str.size()-1);
    int begin = 0;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i] == ' ')
        {
            reverse(str,begin,i-1);
            begin = i+1;
        }
    }
    reverse(str,begin,str.size()-1);
    cout<<str<<endl;
    return 0;
}
#endif

//方法2：调用系统接口
int main()
{
    string str;
    getline(cin,str);
    reverse(str.begin(),str.end());
    int begin = 0;
    int end = 0;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i] == ' ')
        {
            end = i;
            reverse(str.begin()+begin,str.begin()+end);
            begin = end+1;
        }
    }
    reverse(str.begin()+begin,str.end());
    cout<<str<<endl;
    return 0;
}