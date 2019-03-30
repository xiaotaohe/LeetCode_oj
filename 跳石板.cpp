
//��̬�滮
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
            //�жϷ�ƽ����ʱ������һ��
            if(num/i != i)
                div.push_back(num/i);
        }
    }
}
int jump(int n,int m)
{
    //�������浽����һ���������Ĳ���
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
        //������һ������С����
        for(int j = 0;j<div.size();j++)
        {
            //����һ���Ѿ���ǰ���пɴ�ʱ����ʱֻ������Ƿ�Ϊ��С
            //0��ʾǰ��û�пɴ�ģ������ɴ�
            if(div[j]+i<=m)
                stepnum[div[j]+i] = min(stepnum[div[j]+i],stepnum[i]+1);
        }
    }
    //���Ϊ���ɴ����λ�õ�ֵ��Ϊ-1
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



//���������
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