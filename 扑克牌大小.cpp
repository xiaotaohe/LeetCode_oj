#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main()
{
    string line;
    while(getline(cin,line))
    {
        //处理王炸
        if(line.find("joker JOKER",0) != string::npos)
            cout<<"joker JOKER"<<endl;
        //比较牌面的
        else
        {
            //字符串切分
            int index = line.find('-',0);
            string str1 = line.substr(0,index);
            string str2 = line.substr(index+1);
            int c1 = count(str1.begin(),str1.end(),' ');
            int c2 = count(str2.begin(),str2.end(),' ');
            string str = "345678910JQKA2jokerJOKER";
            if(c1 == c2)
            {
                string first1 = str1.substr(0,str1.find(' '));
                string first2 = str2.substr(0,str2.find(' '));
                int index1 = str.find(first1);
                int index2 = str.find(first2);
                if(index1>index2)
                    cout<<str1<<endl;
                else
                    cout<<str2<<endl;
            }
            else
            {
                if(c1 == 3)
                    cout<<str1<<endl;
                else if(c2 == 3)
                    cout<<str2<<endl;
                else
                    cout<<"ERROR"<<endl;
            }
        }
    }
    return 0;
}