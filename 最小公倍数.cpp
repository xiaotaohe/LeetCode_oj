#include<iostream>
using namespace std;

int main()
{
    int n = 0,m = 0;
    cin>>n>>m;
    //求两个数的公倍数
    //1. 获取 n*m的值 R;
    //2. 如果 n == m;算法结束，公倍数 = R/m;
    //3. 若 m>n 重置 m = m - n; 否则 n = n - m;
    //4. 重复 步骤3，直到 n == m;公倍数 = R/m;
    int r = n*m;
    while(n != m)
    {
        if(n>m)
            n = n -m;
        else
            m = m -n;
    }
    cout<<r/m<<endl;
}