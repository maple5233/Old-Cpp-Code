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
	string num = "";//���ַ���
	unsigned int i;
	cout << "������һ�������ֵ��ַ�����" << endl;
	getline(cin, str, '\n');
	for (i = 0; i < str.length(); i++)
	{
		if (!isNum(str[i]))
		{
			continue;
		}
		while (isNum(str[i]))
		{
			num += str[i];//string��+��������ַ�������
			i++;
		}
		num += ' ';
	}
	cout << "����ǣ�";
	cout << num << endl;
	system("pause");
	return 0;
}