#include<iostream>
#include<string>
using namespace std;
template <class T>
class Matrix
{
private:
	int m, n;
	T a[100][100];
public:
	Matrix(){}
	Matrix(int mm,int nn,T aa[][100])
	{
		int i,j;
		m = mm;
		n = nn;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
				a[i][j] = aa[i][j];
		}
	}
	void zhuangzhi()
	{
		int i,j;
		T tmp[100][100];
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				tmp[i][j] = a[i][j];
		}
		int temp;
		temp = m;
		m = n;
		n = temp;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				a[j][i] = tmp[i][j];
		}
	}
	void print()
	{
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				cout << a[i][j] << ' ';
			}
			cout << a[i][j] << endl;
		}
	}
};

int main()
{
	int T, m,n;
	cin >> T;
	int i,j;
	char a;
	while (T--)
	{
		cin >> a >> m >> n;
		if (a == 'I')
		{
			int b[100][100];
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
					cin>>b[i][j];
			}
			Matrix<int> p(m,n,b);
			p.zhuangzhi();
			p.print();
		}
		if (a == 'C')
		{
			char b[100][100];
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
					cin >> b[i][j];
			}
			Matrix<char> p(m, n, b);
			p.zhuangzhi();
			p.print();
		}
		if (a == 'D')
		{
			double b[100][100];
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
					cin >> b[i][j];
			}
			Matrix<double> p(m, n, b);
			p.zhuangzhi();
			p.print();
		}
	}
	return 0;
}
