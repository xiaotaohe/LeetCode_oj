#if 0
//ͨ���ʣ�80%
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int num = 0;
    vector<int> v;
    while(cin>>num)
    {
        bool flag = false;
        int count = 0;
        v.resize(num);
        for(int i = 0;i<num;i++)
            cin>>v[i];
        for(int i = 1;i<num-1;i++)
        {
            //���岨��
            if((v[i-1]<v[i]&&v[i]>v[i+1])||(v[i-1]>v[i]&&v[i]<v[i+1]))
            {
                if(i != num-2)
                    i++;
                flag = true;
                count++;
            }
        }
        cout<<count+1<<endl;
    }
    return 0;
}
#endif

//ͨ���ʣ�100%
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//�Բ��岨��Ϊ��
	int num = 0;
	while (cin >> num)
	{
		vector<int> v;
		v.resize(num);
		int count = 1;
        for(int i = 0;i<v.size();i++)
            cin>>v[i];
		for (int i = 1; i < num - 1; i++)
		{
			if ((v[i] < v[i - 1] && v[i] < v[i + 1]) || (v[i] > v[i - 1] && v[i] > v[i + 1]))
			{
				//�������岨�ȣ���֤��һ�����������������ݣ�����֮ǰҲҪ��֤i++ʱ��
				//��������
				//���磺1��num-3) 2(num-2) 3(num-1)
				//��� i == num-3,��ʱ����1��i = num-2,��������ѭ�� i++����ʱ i = num-1
				//������num-2Ϊ�����������
				if (i != num - 3)
					i++;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}