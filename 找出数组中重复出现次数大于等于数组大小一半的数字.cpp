#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int num = 0;
    while(cin>>num)
    {
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    num = 1;
    int temp = v[0];
    for(int i = 1;i<v.size();i++)
    {
        if(num >= v.size()/2)
            break;
        else if(temp != v[i])
        {
            num = 1;
            temp = v[i];
        }
        else
            num++;
    }
    cout<<temp<<endl;
}