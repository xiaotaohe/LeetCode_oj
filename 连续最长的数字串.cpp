#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str;
	cin>>str;
	int begin = 0;
	int left = 0;
	bool flag = false;
	int max = 0;
	int len = 0;
	for (int i = 0; i<str.size(); i++)
	{
		if (flag == false && str[i] <= '9' && '0' <= str[i])
		{
			flag = true;
			begin = i;
			len++;
			continue;
		}
		else if (str[i] <= '9' && '0' <= str[i])
		{
			len++;
			continue;
		}
		else
		{
			if (len>max)
			{
				max = len;
				left = begin;
			}
			len = 0;
			flag = false;
		}
	}
	//如果最长的在字符串的最后面的话，left和max就没有更新
	if (len > max)
	{
		max = len;
		left = begin;
	}
	for (int i = left; i<left + max; i++)
	{
		cout << str[i];
	}
	cout << endl;
	return 0;
}