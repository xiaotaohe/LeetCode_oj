#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
void compare(vector<string>& v,bool& length,bool& lex)
{
    for(int i = 1;i<v.size();i++)
    {
        //1.ÅÐ¶ÏÊÇ·ñÎª×ÖµäÅÅÐò
        if(v[i-1]>v[i])
            lex = false;
        //2.ÅÐ¶ÏÊÇ·ñÎª³¤¶ÈÅÅÐò
        if(v[i-1].length()>v[i].length())
            length = false;
    }
}
int main()
{
    int num = 0;
    vector<string> v;
    cin>>num;
    v.resize(num);
    for(int i = 0;i<num;i++)
        cin>>v[i];
    bool length = true;
    bool lex = true;
    compare(v,length,lex);
    if(length == true && lex == true)
        cout<<"both"<<endl;
    else if(length)
        cout<<"lengths"<<endl;
    else if(lex)
        cout<<"lexicographically"<<endl;
    else
        cout<<"none"<<endl;
    return 0;
}