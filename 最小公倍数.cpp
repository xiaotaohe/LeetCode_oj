#include<iostream>
using namespace std;

int main()
{
    int n = 0,m = 0;
    cin>>n>>m;
    //���������Ĺ�����
    //1. ��ȡ n*m��ֵ R;
    //2. ��� n == m;�㷨������������ = R/m;
    //3. �� m>n ���� m = m - n; ���� n = n - m;
    //4. �ظ� ����3��ֱ�� n == m;������ = R/m;
    int r = n*m;
    while(n != m)
    {
        if(n>m)
            n = n -m;
        else
            m = m -n;
    }
    cout<<r/m<<endl;
}