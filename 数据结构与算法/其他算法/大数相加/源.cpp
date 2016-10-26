/*******************************
* p5_9.cpp                     *
* ���������ӷ�                 *
********************************/
#include <iostream>
using namespace std;
char *ladd(char *s1, char *s2)
{
	int n1, n2, i, n;
	char *res, c = 0;
	n1 = strlen(s1);            //n1=���ִ�s1�ĳ���
	n2 = strlen(s2);            //n2=���ִ�s2�ĳ���
	n = n1>n2 ? n1 : n2;      //���ִ�s1,s2��󳤶�
	res = new char[n + 2];       //������������ڴ�
	for (i = n + 1; i >= 0; i--)   //��s1�ӵ�λ��ʼ�ᵽres��û�����ֵ�λ�Լ����λ��'0'
		res[i] = i>n - n1 ? s1[i - n - 1 + n1] : '0';
	for (i = n; i >= 0; i--)
	{
		char tchar;
		tchar = i>n - n2 ? res[i] - '0' + s2[i - n + n2 - 1] - '0' + c : res[i] - '0' + c; //�����ַ������
		c = tchar>9 ? 1 : 0;                           //���λ
		res[i] = c>0 ? tchar - 10 + '0' : tchar + '0';            //�����ֱ�������ַ�
	}
	return res;
}
void main() {
	char num1[100], num2[100], *num;
	cin >> num1 >> num2;
	num = ladd(num1, num2);
	cout << num1 << "+" << num2 << "=" << num << endl;
	delete[] num;
}