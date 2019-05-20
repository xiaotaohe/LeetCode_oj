#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int num = 0;
    vector<int> v;
    while(cin>>num)
    {
        bool flag = false;
        int count = 0;
        v.resize(num);
        for(int i = 0;i<num;i++)
            cin>>v[i];
        for(int i = 1;i<num-1;i++)
        {
            //²¨·å²¨¹È
            if((v[i-1]<v[i]&&v[i]>v[i+1])||(v[i-1]>v[i]&&v[i]<v[i+1]))
            {
                if(i != num-2)
                    i++;
                flag = true;
                count++;
            }
        }
        cout<<count+1<<endl;
    }
    return 0;
}