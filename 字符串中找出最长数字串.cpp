#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int ret_pos = 0;
    int pos = 0;
    int max = 0;
    int num = 0;
    bool flag = false;
    bool has_num = false;
    for(int i = 0;i<str.size();i++)
    {
        if(str[i]<='9'&&'0'<=str[i])
        {
            if(flag == false)
            {
                pos = i;
                flag = true;
            }
            has_num = true;
            num++;
        }
        else
        {
            flag = false;
            if(num>max)
            {
                max = num;
                num = 0;
                ret_pos = pos;
            }
            num = 0;
        }
    }
    //�������1.û�����ִ� 2.�������ȫ�����֣���ʱposû�и��� 3.�������
    if(!has_num)
        cout<<endl;
    else if(flag == true && max < num)
        cout<<str.substr(pos,num)<<endl;
    else
        cout<<str.substr(ret_pos,max)<<endl;
    
}