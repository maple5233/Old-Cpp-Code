/*
#include<iostream>
#include<string>
using namespace std;
template <class T>
void sort(T a[], int n)
{
	int i, j;
	T tmp;
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}
int main()
{
	int T, n;
	cin >> T;
	int i;
	char a;
	while (T--)
	{
		cin >> a >> n;
		if (a == 'I')
		{
			int b[100];
			for (i = 0; i < n; i++)
				cin >> b[i];
			sort(b, n);
			for (i = 0; i < n; i++)
			{
				cout << b[i] << ' ';
			}
			cout << endl;
		}
		if (a == 'C')
		{
			char b[100];
			for (i = 0; i < n; i++)
				cin >> b[i];
			sort(b, n);
			for (i = 0; i < n; i++)
			{
				cout << b[i] << ' ';
			}
			cout << endl;
		}
		if (a == 'S')
		{
			string b[100];
			for (i = 0; i < n; i++)
				cin >> b[i];
			sort(b, n);
			for (i = 0; i < n; i++)
			{
				cout << b[i] << ' ';
			}
			cout << endl;
		}
		if (a == 'D')
		{
			double b[100];
			for (i = 0; i < n; i++)
				cin >> b[i];
			sort(b, n);
			for (i = 0; i < n; i++)
			{
				cout << b[i] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
*/