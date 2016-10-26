#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[11];
void sort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i<n; i++)
	{
		for (j = 0; j<n - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void reverse(int a[], int n)
{
	int i, t;
	for (i = 0; i<n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

int find(int a[], int n, int value)
{
	int i;
	for (i = 0; i<n; i++)
	{
		if (a[i] == value)
			return i;
	}
	return -1;
}

void display(int a[], int n)
{
	int i;
	for (i = 0; i<n - 1; i++)
		cout << a[i] << ' ';
	cout << a[i] << endl;
}

int main()
{
	int n, i, t, p, l, b[10];
	cin >> t;
	while (t--)
	{
		for (i = 0; i<10; i++)
			cin >> a[i];
		cin >> n;
		p = find(a, 10, n);
		if (n % 2 != 0 && p != -1)
		{
			for (i = p; i<9; i++)
				a[i] = a[i + 1];
			sort(a, 9);
			display(a, 9);
		}
		else if (n % 2 == 0 && p == -1)
		{
			a[10] = n;
			sort(a, 11);
			reverse(a, 11);
			display(a, 11);
		}
		else
		{
			sort(a, 10);
			reverse(a, 10);
			l = 0;
			for (i = 0; i<10; i++)
			{
				if (a[i] % 2 != 0)
				{
					b[l] = a[i];
					l++;
				}
			}
			for (i = 0; i<10; i++)
			{
				if (a[i] % 2 == 0)
				{
					b[l] = a[i];
					l++;
				}
			}
			for (i = 0; i<9; i++)
				cout << b[i] << ' ';
			cout << b[i] << endl;



		}
	}

	return 0;
}


