#include<iostream>
#include<cstring>
using namespace std;
bool hw(char s[])
{
	char st[1000];
	int i, l;
	l = strlen(s);
	for (i = 0; i<l; i++)
		st[i] = s[l - i - 1];
	st[l] = 0;
	if (strcmp(s, st) == 0)
		return true;
	else
		return false;
}
int main()
{
	int t;
	char s[1000];
	cin >> t;
	while (t--)
	{
		cin >> s;
		if (hw(s))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
