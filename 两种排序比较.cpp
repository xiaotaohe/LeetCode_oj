#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin>>n;
    vector<string> v;
    vector<int> v1;
    vector<string> v2;
    v.resize(n);
    v1.resize(n);//�洢
    v2.resize(n);
    bool len = true;
    bool lex = true;
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
        v2[i] = v[i];//���浥������
        v1[i] = v[i].size();//���浥������
    }
    //�Գ�������
    sort(v1.begin(),v1.end());
    //��ԭ��Ƚ�
    for(int i = 0;i<n;i++)
    {
        if(v1[i] != v[i].size())
            len = false;
    }
    //�����е�������
    sort(v2.begin(),v2.end());
    //��ԭ��Ƚ�
    for(int i = 0;i<n;i++)
    {
        if(v2[i] != v[i])
            lex = false;
    }
    if(len&&lex)
        cout<<"both"<<endl;
    else if(len)
        cout<<"lengths"<<endl;
    else if(lex)
        cout<<"lexicographically"<<endl;
    else
        cout<<"none"<<endl;
    return 0; 
}