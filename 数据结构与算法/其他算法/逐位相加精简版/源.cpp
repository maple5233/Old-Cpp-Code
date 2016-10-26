/*实现的功能是输入一个数然后将其拆分相加，不断循环拆分相加 直至为个位数。
例如输入63的输出结果是9 （6+3=9） 输入87的输出结果是6（8+7=15 1+5=6） 输入666的输出结果是9*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	unsigned int i;
	while (1)
	{
		int sum = 0;
		cin >> a;
		for (i = 0; i < a.length(); i++)
		{
			sum = sum + int(a[i] - '0');
		}
		cout << --sum % 9 + 1 << endl;
	}
	system("pause");
	return 0;
}