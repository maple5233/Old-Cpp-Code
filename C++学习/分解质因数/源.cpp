#include<iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int num[100];
	int yinShu[100];
	int i = 0;
	int b = a;
	int k = 0;
	for (i = 0; i < 100; i++)
	{
		num[i] = 0;
		yinShu[i] = 0;
	}
	for (i = 2; ; )
	{
		if (a%i != 0)
		{
			i++;
			continue;
		}
		else
		{
			yinShu[k] = i;
			num[k]++;
			a = a / i;
			if (a == 1)
			{
				k++;
				break;
			}
			if (a%i != 0)
			{
				k++;
				continue;
			}
		}
	}
	cout << b << '=';
	for (i = 0; i < k; i++)
	{
		cout << yinShu[i] << '(' << num[i] << ')';
	}
	cout << endl;
	system("pause");
	return 0;
}