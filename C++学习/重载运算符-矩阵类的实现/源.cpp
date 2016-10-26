#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class myMatrix
{
private:
	int size;
	int p[20][20];
public:
	myMatrix(int s = 0)
	{ 
		size = s; 
		int i, j;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				p[i][j]=0;
		}
	}
	friend myMatrix operator* (const myMatrix& a, const myMatrix& b);
	void get()
	{
		int i, j;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				cin >> p[i][j];
		}
	}
	void out()
	{
		int i, j;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size-1; j++)
			{
				cout << p[i][j] << " ";
			}
			cout << p[i][j] << endl;
		}
	}
};
myMatrix operator* (const myMatrix& a, const myMatrix& b)
{
	int i, j, k;
	myMatrix c(a.size);
	for (i = 0; i < c.size; i++)
	{
		for (j = 0; j < c.size; j++)
		{
			for (k = 0; k < c.size; k++)
				c.p[i][j] = a.p[i][k] * b.p[k][j];
		}
	}
	return c;
}
int main()
{
	int t,n,i;
	cin >> t>>n;
	myMatrix *a[10];
	for (i = 0; i < t; i++)
	{
		a[i] = new myMatrix(n);
	}
	myMatrix an(n);
	for (i = 0; i < t;i++)
	{
	     a[i]->get();
	}
	for (i = 0; i < t; i++)
	{
		an = an*(*a[i]);
	}
	an.out();
	system("pause");
	return 0;
}