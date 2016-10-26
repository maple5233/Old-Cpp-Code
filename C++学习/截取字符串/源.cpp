#include<iostream>
#include<cstring>
using namespace std;
int substr(char str1[], char str2[], int index)
{
	int j = 0, l;
	l = strlen(str1);
	if (index >= 0 && index<l)
	{
		while (str1[index] != '\0')
		{
			str2[j] = str1[index];
			j++;
			index++;
		}
		str2[j] = '\0';
		cout << str2 << endl;
		return 1;
	}
	else
	{
		cout << "IndexError" << endl;
		return 0;
	}
}

int main()
{
	int t, n;
	char str1[30], str2[30];
	cin >> t;
	while (t--)
	{
		getchar();
		gets(str1);
		cin >> n;
		substr(str1, str2, n);
	}
	return 0;
}
