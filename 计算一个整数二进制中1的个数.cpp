//计算数字中的1的个数

#include<iostream>
using namespace std;
//方法一：对每一个比特位进行比较
/*void findNumberOf1(int num)
{
    int count = 0;
     for(int i = 0;i<32;i++)
     {
         if(num&1)
             count++;
         num >>= 1;
     }
    cout<<count<<endl;
}*/
     

//方法二：经典位操作
void findNumberOf1(int num)
{
    int count = 0;
     while(num)
     {
         count++;
         num &= (num-1);
     }
    cout<<count<<endl;
}

int main(){
    int intnum;
    while(cin>>intnum){
        findNumberOf1(intnum);
    }   
    return 0;
}