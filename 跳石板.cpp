
//动态规划
#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<climits>
void divnum(vector<int>& div,int num)
{
    for(int i = 2;i<=sqrt(num);i++)
    {
        if(num%i == 0)
        {
            div.push_back(i);
            //判断非平方数时加上另一半
            if(num/i != i)
                div.push_back(num/i);
        }
    }
}
int jump(int n,int m)
{
    //用来保存到达这一点至少跳的步数
    vector<int> stepnum(m+1,INT_MAX);
    stepnum[n] = 0;
    if(n == m)
        return 0;
    for(int i = n;i<=m;i++)
    {
        if(stepnum[i] == INT_MAX)
            continue;
        vector<int> div;
        divnum(div,i);
        //更新下一跳的最小步数
        for(int j = 0;j<div.size();j++)
        {
            //当下一跳已经在前面有可达时，此时只需更新是否为最小
            //0表示前面没有可达的，及不可达
            if(div[j]+i<=m)
                stepnum[div[j]+i] = min(stepnum[div[j]+i],stepnum[i]+1);
        }
    }
    //如果为不可达，将该位置的值改为-1
    if(stepnum[m] == INT_MAX)
        return -1;
    else
        return stepnum[m];
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<jump(n,m)<<endl;
    return 0;
}



//大神的做法
#if 0
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    while(cin>>N>>M){
        vector<int> steps(M+1,INT_MAX);
        steps[N] = 0;
        for(int i=N;i<=M;i++){
            if(steps[i] == INT_MAX){
                continue;
            }
            for(int j=2;(j*j)<=i;j++){
                if(i%j == 0){
                    if(i+j <= M){
                        steps[i+j] = min(steps[i]+1,steps[i+j]);
                    }
                    if(i+(i/j) <= M){
                        steps[i+(i/j)] = min(steps[i]+1,steps[i+(i/j)]);
                    }

                }

            }
        }
        if(steps[M] == INT_MAX){
            steps[M] = -1;
        }
        cout<<steps[M]<<endl;
    }
    return 0;
}
#endif