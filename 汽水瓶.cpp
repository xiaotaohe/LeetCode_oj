#include<iostream>
using namespace std;


int total(int table)
{
    int exchange = 0;
    while(table>=3)
    {
        //���õ���ˮ�����ܿ�ƿ������3
        exchange += table/3;
        //ʣ���ƿ������ ������ˮ��+�ϴ�ʣ�����ˮƿ
        table = table/3+table%3;
    }
    //������������ƿ�ӿ������ϰ��һ������ȡһƿ
    if(table%3 == 2)
        exchange += 1;
    return exchange;
}
int main()
{
    int table = 0;
    while(cin>>table)
    {
        if(total(table) == 0)
            continue;
        cout<<total(table)<<endl;
    }
    return 0;
}