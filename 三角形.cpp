#include<iostream>
using namespace std;
#include<string>
#include<algorithm>


//��ȡ����֮������ֵ�������ȷ�������һ���������ﷵ�صڶ���
string get_max(string& a,string& b)
{
    //��Ϊ�������
    //1.����
    //2.�ַ�����С
    if(a.size()>b.size())
        return a;
    else if(a.size()<b.size())
        return b;
    else if(a>b)
        return a;
    return b;
}
//�������
string add(string a,string b)
{
    //Ĭ��a�
    if(a.size()<b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int index = 0;
    //flag�����λ
    int flag = 0;
    while(index<b.size())
    {
        if(a[index]-'0'+b[index]-'0'+flag>9)
        {
            a[index] = (a[index]-'0'+b[index]-'0'+flag)-10+'0';
            flag = 1;
        }
        else
        {
            a[index] = (a[index]-'0'+b[index]-'0'+flag)+'0';
            flag = 0;
        }
        index++;
    }
    while(flag)
    {
        if(index<a.size())
        {
            if(a[index]-'0'+flag>9)
            {
                a[index] = (a[index]-'0'+flag)-10+'0';
                flag = 1;
            }
            else
            {
                a[index] = (a[index]-'0'+flag)+'0';
                flag = 0;
            }
            index++;
        }
        else
            break;
    }
    if(flag)
        a.push_back('1');
    reverse(a.begin(),a.end());
    return a;
}
int main()
{
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        //ѡ�������е����ֵ
        string _max = get_max(a,b);
        _max = get_max(c,_max);
        string sum;
        //��ȥ���ֵ����������֮��Ϊ��С��������֮��
        if(_max == a)
            sum = add(b,c);
        else if(_max == b)
            sum = add(a,c);
        else
            sum = add(a,b);
        if(_max != get_max(_max,sum))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}