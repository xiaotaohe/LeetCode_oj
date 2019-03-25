#include<iostream>
using namespace std;


int total(int table)
{
    int exchange = 0;
    while(table>=3)
    {
        //换得得汽水等于总空瓶数出以3
        exchange += table/3;
        //剩余空瓶数等于 换得汽水数+上次剩余得汽水瓶
        table = table/3+table%3;
    }
    //如果最后还有两个瓶子可以问老板借一个，换取一瓶
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