#include<iostream>
using namespace std;
int ZHS(int, int);
int main()
{
	int t;
	cin >> t;
	int m, n;
	while (t--)
	{
		cin >> m >> n;
		cout << ZHS(m, n) << endl;
	}
	return 0;
}
int ZHS(int m, int n)
{
	int i, c, M = 1, N = 1, MN = 1;
	for (i = 1; i <= n; i++)
		N = N*i;
	for (i = 1; i <= m; i++)
		M = M*i;
	for (i = 1; i <= m - n; i++)
		MN = MN*i;
	c = M / (N*MN);
	return c;
}