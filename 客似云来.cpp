// write your code here cpp

#include<iostream>
using namespace std;

int main()
{
    int from = 0,to = 0;
    while(cin>>from>>to)
    {
        long long num = 0;
        if(from == 1)
            num = 1;
        long long f1 = 0,f2 = 1,f3 = 0;
        for(int i = 2;i<=to;i++)
        {
            f3 = f1+f2;
            f1 = f2;
            f2 = f3;
            if(from<=i)
                num += f3;
        }
        cout<<num<<endl;
    }
}