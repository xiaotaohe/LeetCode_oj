#include<iostream>
using namespace std;
#include<algorithm>
#include<string>

bool yes(string& str)
{
    string str1 = str;
    reverse(str.begin(),str.end());
    if(str == str1)
        return true;
    else
        return false;
}
int main()
{
    string A;
    string B;
    string C;
    cin>>A;
    cin>>B;
    int count = 0;
    //���ַ���A�� 0~n-1λ�ò����ַ���B
    for(int i = 0;i<A.size();i++)
    {
        C = A;
        C.insert(i,B);
        if(yes(C))
            count++;
    }
    //���ַ������׷��B����Ҳ����n-1λ��֮��
    C = A;
    C += B;
    if(yes(C))
        count++;
    cout<<count<<endl;
    return 0;
}