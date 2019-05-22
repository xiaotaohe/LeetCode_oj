#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

#if 0
//通过率70%
void to_type(int num,int type,string& str)
{
    if(num == 0)
        return;
    to_type(num/type,type,str);
    if((num%type)>=10)
    {
        char ch = 'A';
        ch += (num%type-10);
        str += ch;
    }
    else
        str += to_string(num%type);
}
int main()
{
    int num,type;
    cin>>num>>type;
    if(num == 0)
        cout<<0;
    else
    {
        string str = "";
        bool flag = false;
        if(num < 0)
        {
            flag = true;
            num = 0-num;
        }
        to_type(num,type,str);
        if(flag)
        {
            string temp; 
            temp.resize(32-str.size(),'0');
            str = temp+str;
            str[0] = '1';
        }
        cout<<str;
    }
    cout<<endl;
    return 0;
}
#endif

#if 0
//通过率70%
char num[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string translation(int m,int n)
{
    string str = "";
    bool flag = false;
    if(m<0)
        flag = true;
    //转换为n进制，逆序
    while(m)
    {
        str += num[m%n];
        m /= n;
    }
    //如果为负数，最高位补1
     if(flag)
    {
         for(int i = str.size();i<=32;i++)
         {
            str += '0';
         }
        str[31] = '1';
    }
    //逆序
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
#endif 