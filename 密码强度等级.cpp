#include<iostream>
using namespace std;
#include<string>

int grade = 0;
//������
void length(string& str)
{
    if(str.size()<=4)
        grade += 5;
    else if(str.size()<=7 && str.size()>=5)
        grade += 10;
    else
        grade += 25;
}
//�������
void charactor_num(string& str,int& num)
{
    for(size_t i = 0;i<str.size();i++)
    {
        //��ȥ��ĸ ���֣������Ķ��Ƿ���
        if(!(str[i]>='A'&&str[i]<='Z')&&
           !(str[i]>='a'&&str[i]<='z')&&
           !(str[i]>='0'&&str[i]<='9'))
            num++;
    }
    if(num == 1)
        grade += 10;
    else
        grade += 25;
}
//�����Сд��ĸ,����
void gid_small_charactor(string& str,int& big,int& small,int& num)
{
    for(size_t i = 0;i<str.size();i++)
    {
        if(str[i]<='Z'&&str[i]>='A')
            big++;
        else if(str[i]<='z'&&str[i]>='a')
            small++;
        else if(str[i]<='9'&&str[i]>='0')
            num++;
    }
    if(big == 0 && small == 0)
        grade += 0;
    if(big || small)
    {
        if(big&&small)
            grade += 20;
        else
            grade += 10;
    }
    if(num == 1)
        grade += 10;
    if(num>1)
        grade += 20;
}
int main()
{
    string str;
    while(cin>>str)
    {
        grade = 0;
        //���������ɸ����ֺ�������
        //���ţ����֣���С��ĸ
        int character = 0,num = 0,big = 0,small = 0;
        //���볤�ȱ�׼�ĵ÷�
        length(str);
        charactor_num(str,character);
        gid_small_charactor(str,big,small,num);
        //������
        if(character||num||big||small)
        {
            //��Сд��ĸ�����֣�����
            if(small&&big&&num&&character)
                grade += 5;
            else if((small || big) && num && character)
                grade += 3;
            else if((small || big) && num)
                grade += 2;
        }
        //����ȼ�
        if(grade>=90)
            cout<<"VERY_SECURE"<<endl;
        else if(grade>=80)
            cout<<"SECURE"<<endl;
        else if(grade>=70)
            cout<<"VERY_STRONG"<<endl;
        else if(grade>=60)
            cout<<"STRONG"<<endl;
        else if(grade>=50)
            cout<<"AVERAGE"<<endl;
        else if(grade>=25)
            cout<<"WEAK"<<endl;
        else
            cout<<"VERY_WEAK"<<endl;
    }
    return 0;
}