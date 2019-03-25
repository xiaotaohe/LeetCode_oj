#include<iostream>
using namespace std;
#include<math.h>
//#include<stdlib.h>

//判断一个数是不是素数
bool isprime(int n)
{
	int k = sqrt(n);
	if (n<2)
		return false;
	for (int i = 2; i <= k; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	int x = 0, y = 0;
	while (cin >> n)
	{
		int gap = n;
		for (int i = 2; i<n; i++)
		{
			int len = 0;
			if (isprime(i) && isprime(n - i))
			{
				if (i>n - i)
					len = i - (n - i);
				else
					len = n - i - i;
				if (len < gap)
				{
					x = i;
					y = n - i;
					gap = len;
				}
			}
		}
		if (x>y)
			swap(x, y);
		cout << x << endl;
		cout << y << endl;
	}
}