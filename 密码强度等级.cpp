#include<iostream>
using namespace std;
#include<string>

int grade = 0;
//处理长度
void length(string& str)
{
    if(str.size()<=4)
        grade += 5;
    else if(str.size()<=7 && str.size()>=5)
        grade += 10;
    else
        grade += 25;
}
//处理符号
void charactor_num(string& str,int& num)
{
    for(size_t i = 0;i<str.size();i++)
    {
        //除去字母 数字；其他的都是符号
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
//处理大小写字母,数字
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
        //奖励部分由个部分函数带出
        //符号，数字，大小字母
        int character = 0,num = 0,big = 0,small = 0;
        //密码长度标准的得分
        length(str);
        charactor_num(str,character);
        gid_small_charactor(str,big,small,num);
        //处理奖励
        if(character||num||big||small)
        {
            //大小写字母，数字，符号
            if(small&&big&&num&&character)
                grade += 5;
            else if((small || big) && num && character)
                grade += 3;
            else if((small || big) && num)
                grade += 2;
        }
        //处理等级
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