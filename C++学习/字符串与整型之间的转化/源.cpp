#include<iostream>
#include<cstring>
using namespace std;
bool checkString(char s[])
{
	int i, length;
	length = strlen(s);
	for (i = 0; i < length; i++)
	{
		if ((s[i]<'0') || s[i]>'9')
			return false;
	}
	return true;
}
int stringToInt(char s[])
{
	int i, value=0,length;
	length = strlen(s);
	for (i = 0; i < length; i++)
	{
		value *= 10;
		value += s[i] - '0';
	}
	return value;
}
void intToString(int num,char* s)
{
	int tmp;
	int numTmp=num,numLength=0;
	while (numTmp!=0)
	{
		numTmp = numTmp / 10;
		numLength++;
	}//获取数字长度

	s[numLength] = 0;//初始化字符串
	while (num!=0)
	{
		tmp = num % 10;
		num = num / 10;
		s[numLength - 1] = tmp + '0';
		numLength--;
	}
}
int main()
{
	char s[1000],ss[1000];
	int num;
	cout << "请输入要转化的字符串:" << endl;
	cin >> s;
	while (!checkString(s))
	{
		cout << "该字符串含有不合法字符！请重新输入：" << endl;
		cin >> s;
	}
	cout << "转化结果为：" << stringToInt(s) << endl;

	cout << "请输入要转化的数字:" << endl;
	cin >> num;
	intToString(num, ss);
	cout << "转化结果为：" << ss << endl;
	system("pause");
	return 0;
}