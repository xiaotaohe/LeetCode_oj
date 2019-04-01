#include<iostream>
using namespace std;

int fib[10001] = {1,1,2, 3,5 };
//±‰œ‡Ï≥≤®ƒ«∆ı
void init_fib()
{
	for (int i = 2; i<=10000; i++)
		fib[i] = (fib[i - 1] % 10000 + fib[i - 2] % 10000) % 10000;
}
int get_fib(int num)
{
	return fib[num];
}
int main()
{
	int n = 0;
	init_fib();
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			int num = 0;
			cin >> num;
			printf("%04d", get_fib(num));
		}
		cout << endl;
	}
}
