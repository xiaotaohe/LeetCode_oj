#include<iostream>
using namespace std;
#include<string>
#include<vector>

void parse(string& str,vector<string>& v)
{
    //flag ������־����
    bool flag = false;
    int count = 0;
    //code�����洢�������ĵ�������
    string code;
    for(int i = 0;i<str.size();i++)
    {
        //�����С��������
        //��Ϊ��������ǰ�����
        if(str[i] == '"' && flag == false)
        {
            flag = true;
            continue;
        }
        else if(flag == true && str[i] != '"')
        {
            code += str[i];
        }
        //���ٴ���������ʱ����Ǹ�ԭ����ν�������vector��������ǡ�code��ԭ
        else if(flag == true && str[i] == '"')
        {
            cout<<code<<endl;
            code = "";
            flag = false;
            
        }
        //2.����û���������
        else if(flag == false && str[i] != ' ')
        {
            code += str[i];
            continue;
        }
        else if(flag == false && str[i] == ' ')
        {
            v.push_back(code);
            code = "";
        }
    }
    if(!code.empty())
        v.push_back(code);
}
int main()
{
    string str;
    getline(cin,str);
    //�����н���
    vector<string> v;
    parse(str,v);
    cout<<v.size()<<endl;
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}