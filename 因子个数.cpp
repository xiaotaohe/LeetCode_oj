// write your code here cpp
#include<iostream>
using namespace std;

int main()
{
    int n;
    //�����������
    while(cin>>n)
    {
        int s = 0;
        //�����Ӹ���
        for(int i = 2;i*i<=n;i++)
        {
            //�ҵ�����
            if(n%i == 0)
            {
                //�ҵ����ӵ�
                while(n%i == 0)
                {
                    n /= i;
                }
                s++;
            }
        }
        if(n != 1)
            s++;
        cout<<s<<endl;
    }
    return 0;
}