#include<iostream>
using namespace std;
#include<vector>

//����һ��hash
//������������
int main()
{
    //1.�����г��ֵ����洢��vector����
    int n = 0;
    vector<int> vec;
    while(cin>>n)
        vec.push_back(n);
    //2.��һ��������¼�����������һ��������¼ÿ�����ı仯
    //3.ÿ��������ʼ����Ϊ1��������������������ȵ�count�Ӽӣ�����count--��
    //4.��countΪ��ʱ��temp���ڵ�ǰ���������λ�á�
    //��Ϊ���������countֵ���϶�����1,ֻ������count�����ܼ���Ϊ0��
    //���temp�д洢�ı��ǽ��
    int temp = vec[0];
    int count = 1;
    for(int i = 0;i<vec.size();i++)
    {
        if(temp == vec[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            count = 1;
            temp = vec[i];
        }
    }
    cout<<temp<<endl;
    return 0;
}