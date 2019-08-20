#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin>>v[i];
    int sum = v[0];
    int max = v[0];
    for(int i = 1;i<n;i++)
    {
        if(sum>=0)
            sum += v[i];
        else
            sum = v[i];
         if(sum > max)
                max = sum;
    }
    cout<<max<<endl;
}
