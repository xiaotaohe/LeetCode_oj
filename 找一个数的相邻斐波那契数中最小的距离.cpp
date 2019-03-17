#include<iostream>
using namespace std;

int main()
{
    int N,left,right,f1 = 0, f2 = 1,f3;
    cin>>N;
    //找N左右两边，并更新与左右的差值，直到找到右边相邻的便退出，选出左右相邻的最下差值。
    while(1)
    {
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
        if(N>f1)
            left = N-f1;
        else
        {
            right = f1 - N;
            break;
        }
    }
    cout<<min(left,right)<<endl;
    return 0;
}