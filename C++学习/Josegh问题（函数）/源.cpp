#include<iostream>
using namespace std;
void Josegh(int, int);
int main()
{
	int T;
	cin >> T;
	int m, n;
	while (T--)
	{
		cin >> m >> n;
		Josegh(m, n);
	}
}
void Josegh(int m, int n)
{
	int a[30];
	int i, j;
	for (i = 0; i < 30; i++)
		a[i] = i + 1;
	int k = -1;
	int l = 0;
	while (1)
	{
		for (j = 1; j <= n;)
		{
			k = (k + 1) % m;
			if (a[k] != 0)
				j++;
		}
		l++;
		if (l == m)
		{
			cout << a[k] << endl;
			break;
		}
		cout << a[k] << ' ';
		a[k] = 0;

	}
}