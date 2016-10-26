#include<iostream>
using namespace std;
int zdgys(int a, int b);
int main()
{
	int T;
	cin >> T;
	while (T--)
	{ 
		int m, n,c,d;
		cin >> m >> n;
		c=zdgys(m, n);
		d = m*n / c;
		cout << c<<" " << d;
	}
	return 0;
}
int zdgys(int a, int b)
{ 
	if (b != 0)
		return zdgys(b, a%b);
	else 
	   return a;
}