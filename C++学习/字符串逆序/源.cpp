#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int T;
	cin >> T;
	string a;
	int strLength,i;
	while (T--)
	{
		cin >> a;
		stack<char> b;
		strLength = a.length();
		for (i = 0; i < strLength; i++)
		{
			b.push(a[i]);
		}
		for (i = 0; i < strLength; i++)
		{
			cout << b.top();
			b.pop();
		}
		cout << endl;
	}
	return 0;
}