#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//���ʷ�ת�߼�
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
    //�������ӷ�ת
    reverse(str.begin(),str.end());
    int left = 0;
    //���������ת
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