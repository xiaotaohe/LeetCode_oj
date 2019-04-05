// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
    int n;
    //多次输入用例
    while(cin>>n)
    {
        int s = 0;
        //找因子个数
        for(int i = 2;i*i<=n;i++)
        {
            //找到因子
            if(n%i == 0)
            {
                //找到因子的
                while(n%i == 0)
                {
                    n /= i;
                }
                s++;
            }
        }
        if(n != 1)
            s++;
        cout<<s<<endl;
    }
    return 0;
}