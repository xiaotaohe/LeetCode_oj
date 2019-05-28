#include<iostream>
using namespace std;
#if 0
//最小公倍数，辗转相减法
int main()
{
    int r = 0,n = 0,m = 0;
    cin>>n>>m;
    r = n*m;
    while(n!=m)
    {
        if(n>m)
            n = n - m;
        else 
            m = m - n;
    }
    cout<<r/n<<endl;
}
#endif
//2.辗转相除法
int main()
{
    int r = 0,n = 0,m = 0;
    cin>>n>>m;
    r = n*m;
    if(n<m)
        swap(n,m);
    while(n%m)
    {
        n = n%m;
        swap(n,m);
    }
    cout<<r/m<<endl;
}
