#include<iostream>
using namespace std;
#include<vector>

//辗转相除求最大公约数
int get_num(int c,int b)
{
    if(c<b)
        swap(c,b);
    while(c%b)
    {
        int temp = c%b;
        c = b;
        b = temp;
    }
    return b;
}

//获取最终的结果
int get_now_num(vector<int>& v,int c)
{
    for(int i = 0;i<v.size();i++)
    {
        if(v[i]<=c)
            c += v[i];
        else
            c += get_num(c,v[i]);
    }
    return c;
}

int main()
{
    int group = 0, c = 0;
    while(cin>>group>>c)
    {
        vector<int> v;
        v.resize(group);
        for(int i = 0;i<group;i++)
            cin>>v[i];
        cout<<get_now_num(v,c)<<endl;
    }
    return 0;
}
