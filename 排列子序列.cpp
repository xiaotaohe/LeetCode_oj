#if 0
//通过率：80%
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
            //波峰波谷
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

//通过率：100%
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//以波峰波谷为界
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
				//跳过波峰波谷，保证下一个数左右两侧有数据，跳过之前也要保证i++时，
				//不会跳出
				//比如：1（num-3) 2(num-2) 3(num-1)
				//如果 i == num-3,此时跳过1，i = num-2,除了这趟循环 i++，此时 i = num-1
				//导致以num-2为波峰的情况错过
				if (i != num - 3)
					i++;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}