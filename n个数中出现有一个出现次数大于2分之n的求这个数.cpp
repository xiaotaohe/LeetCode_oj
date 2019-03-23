#include<iostream>
using namespace std;
#include<vector>

//方法一：hash
//方法二：如下
int main()
{
    //1.将所有出现的数存储在vector里面
    int n = 0;
    vector<int> vec;
    while(cin>>n)
        vec.push_back(n);
    //2.用一个数来记录过半的数，用一个数来记录每个数的变化
    //3.每个数的起始次数为1，遍历整个数组遇到相等的count加加，否则count--；
    //4.当count为零时，temp等于当前遍历数组的位置。
    //因为过半的数的count值最后肯定大于1,只有它的count不可能减减为0，
    //最后temp中存储的便是结果
    int temp = vec[0];
    int count = 1;
    for(int i = 0;i<vec.size();i++)
    {
        if(temp == vec[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            count = 1;
            temp = vec[i];
        }
    }
    cout<<temp<<endl;
    return 0;
}