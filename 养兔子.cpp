// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
    //±äÏàì³²¨ÄÇÆõ
    long long n = 0;
    while(cin>>n)
    {
        if(n<=2)
        {
            if(n==0)
            {
                cout<<1<<endl;
                continue;
            }
            cout<<n<<endl;
            continue;
        }
        long long f1 = 1,f2 = 1,f3 = 0;
        for(int i = 2;i<=n;i++)
        {
            f3 = f1+f2;
            f1 = f2;
            f2 = f3;
        }
        cout<<f3<<endl;
    }
    return 0;
}