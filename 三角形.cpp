#include<iostream>
using namespace std;
#include<string>
#include<algorithm>


//获取两数之间的最大值，如果相等返回任意一个，在这里返回第二个
string get_max(string& a,string& b)
{
    //分为两种情况
    //1.长度
    //2.字符串大小
    if(a.size()>b.size())
        return a;
    else if(a.size()<b.size())
        return b;
    else if(a>b)
        return a;
    return b;
}
//两数相加
string add(string a,string b)
{
    //默认a最长
    if(a.size()<b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int index = 0;
    //flag处理进位
    int flag = 0;
    while(index<b.size())
    {
        if(a[index]-'0'+b[index]-'0'+flag>9)
        {
            a[index] = (a[index]-'0'+b[index]-'0'+flag)-10+'0';
            flag = 1;
        }
        else
        {
            a[index] = (a[index]-'0'+b[index]-'0'+flag)+'0';
            flag = 0;
        }
        index++;
    }
    while(flag)
    {
        if(index<a.size())
        {
            if(a[index]-'0'+flag>9)
            {
                a[index] = (a[index]-'0'+flag)-10+'0';
                flag = 1;
            }
            else
            {
                a[index] = (a[index]-'0'+flag)+'0';
                flag = 0;
            }
            index++;
        }
        else
            break;
    }
    if(flag)
        a.push_back('1');
    reverse(a.begin(),a.end());
    return a;
}
int main()
{
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        //选出三个中的最大值
        string _max = get_max(a,b);
        _max = get_max(c,_max);
        string sum;
        //除去最大值，其余两数之和为最小的两条边之和
        if(_max == a)
            sum = add(b,c);
        else if(_max == b)
            sum = add(a,c);
        else
            sum = add(a,b);
        if(_max != get_max(_max,sum))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}