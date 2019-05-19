#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int n = 0;
    while(cin>>n)
    {
        vector<int> v;
        long num = 0;
        v.resize(n*3);
        for(int i = 0;i < n*3;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
       for(int i = n;i<3*n;i += 2)
           num += v[i];
        cout<<num<<endl;
    }
}