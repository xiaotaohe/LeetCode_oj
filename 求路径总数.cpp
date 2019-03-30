#include<iostream>
using namespace std;
int get_path(int n,int m)
{
    if(n>1 && m>1)
        return get_path(n-1,m)+get_path(n,m-1);
    else if((n == 1&&m>=1)||(m == 1&&n>=1))
        return n+m;
    else
        return 0;
}
int main()
{
    int row = 0,col = 0;
    while(cin>>row>>col)
    {
        cout<<get_path(row,col)<<endl;
    }
}