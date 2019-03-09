#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//单词翻转逻辑
void _reverse(string& str,int left,int right)
{
    while(left<right)
    {
        swap(str[left],str[right]);
        left++;
        right--;
    }
}
int main()
{
    string str;
    getline(cin,str);
    //整个句子翻转
    reverse(str.begin(),str.end());
    int left = 0;
    //单词逐个翻转
    for(int i = 0;i<str.size();i++)
    {
       if(str[i] == ' ')
       {
           _reverse(str,left,i-1);
           left = i+1;
       }
    }
    reverse(str.begin()+left,str.end());
    cout<<str<<endl;
    return 0;
}