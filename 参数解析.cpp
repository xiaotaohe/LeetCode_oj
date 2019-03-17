#include<iostream>
using namespace std;
#include<string>
#include<vector>

void parse(string& str,vector<string>& v)
{
    //flag 用来标志“”
    bool flag = false;
    int count = 0;
    //code用来存储解析到的单个命令
    string code;
    for(int i = 0;i<str.size();i++)
    {
        //处理有“”的情况
        //在为遇到“”前标记下
        if(str[i] == '"' && flag == false)
        {
            flag = true;
            continue;
        }
        else if(flag == true && str[i] != '"')
        {
            code += str[i];
        }
        //当再次遇到“”时，标记复原将这段解析放入vector，并将标记、code复原
        else if(flag == true && str[i] == '"')
        {
            cout<<code<<endl;
            code = "";
            flag = false;
            
        }
        //2.处理没“”的情况
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
    //名令行解析
    vector<string> v;
    parse(str,v);
    cout<<v.size()<<endl;
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}