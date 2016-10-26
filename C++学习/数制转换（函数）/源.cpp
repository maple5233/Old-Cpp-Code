#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
long change(char s[])
{
	long n, i, t, l;
	l = strlen(s);
	n = 0;
	for (i = 0; i<l; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
			t = s[i] - '0' + 0;
		else
			t = s[i] - 'A' + 10;
		n = n + t*pow(16, l - i - 1);
	}
	return n;
}
int main()
{
	int t;
	long n;
	char s[100];
	cin >> t;
	while (t--)
	{
		cin >> s;
		n = change(s);
		cout << n << endl;
	}
	return 0;

}
