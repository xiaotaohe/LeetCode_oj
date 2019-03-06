#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char num[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string translation(int m,int n)
{
    string str = "";
    bool flag = false;
    if(m<0)
        flag = true;
    //ת��Ϊn���ƣ�����
    while(m)
    {
        str += num[m%n];
        m /= n;
    }
    //���Ϊ���������λ��1
     if(flag)
    {
         for(int i = str.size();i<=32;i++)
         {
            str += '0';
         }
        str[31] = '1';
    }
    //����
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    long long m = 0,n = 0;
    string str;
    scanf("%d%d",&m,&n);
    if(m == 0)
    {
        cout<<""<<endl;
        return 0;
    }
    str = translation(m,n);
    cout<<str<<endl;
    return 0;
}