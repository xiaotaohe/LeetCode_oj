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
    //向字符串A的 0~n-1位置插入字符串B
    for(int i = 0;i<A.size();i++)
    {
        C = A;
        C.insert(i,B);
        if(yes(C))
            count++;
    }
    //在字符串最后追加B串，也就是n-1位置之后。
    C = A;
    C += B;
    if(yes(C))
        count++;
    cout<<count<<endl;
    return 0;
}