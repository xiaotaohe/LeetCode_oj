#include<iostream>
using namespace std;
#include<vector>

//求最大公约数
//使用辗转相除法
int GCD(int a,int b)
{
    while(b)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int n = 0,a = 0;
    while(cin>>n>>a)
    {
        vector<int> v;
        v.resize(n);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
            if(a>v[i])
                a += v[i];
            else
                a += GCD(a,v[i]);
        }
        cout<<a<<endl;
    }
    return 0;
}