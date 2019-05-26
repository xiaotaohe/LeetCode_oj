#include<iostream>
using namespace std;

int main()
{
    int N = 0;
    cin>>N;
    int left = 0,right = 0,f1 = 0,f2 = 1,f3 = 0;
    while(1)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        if(N>f1)
            left = N - f1;
        else
        {
            right = f1 - N;
            break;
        }
    }
    cout<<min(left,right)<<endl;
    return 0;
}