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
	}//��ȡ���ֳ���

	s[numLength] = 0;//��ʼ���ַ���
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
	cout << "������Ҫת�����ַ���:" << endl;
	cin >> s;
	while (!checkString(s))
	{
		cout << "���ַ������в��Ϸ��ַ������������룺" << endl;
		cin >> s;
	}
	cout << "ת�����Ϊ��" << stringToInt(s) << endl;

	cout << "������Ҫת��������:" << endl;
	cin >> num;
	intToString(num, ss);
	cout << "ת�����Ϊ��" << ss << endl;
	system("pause");
	return 0;
}