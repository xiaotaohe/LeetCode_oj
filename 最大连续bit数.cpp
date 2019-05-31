#include<iostream>
using namespace std;

int get_num(int num)
{
    int max = 0;
    int count = 0;
    bool flag = false;
    while(num)
    {
        if(flag == false && num%2 == 1)
        {
            if(count>max)
                max = count;
            count = 1;
            flag = true;
        }
        else if(flag == true && num%2 == 1)
        {
            count++;
        }
        else if(num%2 == 0)
            flag = false;
        num /= 2;
    }
    if(count>max)
        max = count;
    return max;
}
int main()
{
    int num = 0;
    while(cin>>num)
    {
        //获取最大连续的1的个数
        cout<<get_num(num)<<endl;
    }
    return 0;
}