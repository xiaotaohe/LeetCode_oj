//���������е�1�ĸ���

#include<iostream>
using namespace std;
//����һ����ÿһ������λ���бȽ�
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
     

//������������λ����
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