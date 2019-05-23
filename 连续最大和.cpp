#include<iostream>
using namespace std;
#include<vector>

#if 0
//1.暴力求解，跑过70%，还有一部分case原因是超时
int main()
{
    vector<int> v;
    int num = 0;
    cin>>num;
    v.resize(num);
    for(int i = 0;i<num;i++)
        cin>>v[i];
    int max_count = v[0];
    int count = 0;
    for(int i = 0;i<v.size();i++)
    {
        for(int j = 0;j<=i;j++)
        {
            count = 0;
            for(int z = j;z<=i;z++)
                count+=v[z];
            if(count>max_count)
                max_count = count;
        }
    }
    cout<<max_count<<endl;
}
#endif

//2.采取动态规划
int main()
{
    int num = 0;
    cin>>num;
    vector<int> v(num,0),dp(v);
    for(int i = 0;i<v.size();i++)
        cin>>v[i];
    int max = dp[0] = v[0];
    for(int i = 1;i<v.size();i++)
    {
        if(v[i]+dp[i-1]>v[i])
            dp[i] = v[i]+dp[i-1];
        else
            dp[i] = v[i];
        if(max<dp[i])
            max = dp[i];
    }
    cout<<max<<endl;
    return 0;
}
    

