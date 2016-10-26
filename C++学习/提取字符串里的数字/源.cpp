#include<iostream>
#include<string>
using namespace std;
bool isNum(char c)
{
	if (c<='9'&&c>='0')
		return true;
	return false;
}
int main()
{
	string str;
	string num = "";//空字符串
	unsigned int i;
	cout << "请输入一个带数字的字符串：" << endl;
	getline(cin, str, '\n');
	for (i = 0; i < str.length(); i++)
	{
		if (!isNum(str[i]))
		{
			continue;
		}
		while (isNum(str[i]))
		{
			num += str[i];//string的+运算就是字符串连接
			i++;
		}
		num += ' ';
	}
	cout << "结果是：";
	cout << num << endl;
	system("pause");
	return 0;
}