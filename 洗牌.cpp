#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//洗牌的逻辑代码
void shuffle(vector<int>& v,int left,int right)
{
    vector<int> temp;
    int _right = (left+right)/2+1;
    int _left = left;
    while(_right<=right)
    {
        temp.push_back(v[_left]);
        temp.push_back(v[_right]);
        _left++;
        _right++;
    }
    for(int i = 0;i<temp.size();i++)
    {
        v[left++] = temp[i];
    }
    //reverse(v.begin()+left,v.begin()+right);
}

//主函数
int main()
{
    int group_num = 0;
    cin>>group_num;
    int left = 0;
    int right = 0;
    vector<int> v;
    for(int i = 0;i<group_num;i++)
    {
        int n = 0;
        int k = 0;
        cin>>n;
        cin>>k;
        left = right;
        right += 2*n;
        for(int i = 0;i<2*n;i++)
        {
           int temp = 0;
            cin>>temp;
            v.push_back(temp);
        }
        for(int i = 0;i<k;i++)
        {
            shuffle(v,left,right-1);
        }
        //输出
        for(int i = left;i<right-1;i++)
            cout<<v[i]<<" ";
        cout<<v[right-1]<<endl;
    }
    return 0;
}