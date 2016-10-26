#include<iostream>
#include<iomanip>
using namespace std;
double pj(int m);
double zg(int n);
double cz[5][4];
int main()
{
	int T;
	int i, j;
	cin >> T;
	while (T--)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 4; j++)
				cin >> cz[i][j];
		}
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pj(0);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pj(1);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pj(2);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pj(3);
		cout << endl;
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << zg(0);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << zg(1);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << zg(2);
		cout << setw(8) << setiosflags(ios::fixed) << setprecision(2) << zg(3);
		cout << endl;
	}
	return 0;
}
double zg(int m)
{
	double max = 0;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (cz[i][m]>max)
			max = cz[i][m];
	}
	return max;
}
double pj(int n)
{
	int i;
	double s=0,ave = 0;
	for (i = 0; i < 5; i++)
	{
		s = s + cz[i][n];
	}
	ave = s / 5;
	return ave;
}