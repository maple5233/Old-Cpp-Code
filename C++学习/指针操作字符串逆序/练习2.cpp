/*��д��������ָ���������дһ���������ַ����������������е��øú������û������һ���ַ������������*/
#include<iostream>
#include<cstring>
using namespace std;
void fan(char*,char*,int);
int main()
{
	char a[10000];
	char b[10000];
	int l;
	cout << "�������ַ���:" << endl;
	cin >> a;
	cout << endl;
	l = strlen(a);
	fan(a,b,l);
	cout << "��л����ʹ�ã�"<<endl<<endl;
	system("pause");
}
void fan(char* p,char* q,int j)
{
	int i;
	for (i = 0; i < j; i++)
	{
		*(q + i) = *(p + (j - i - 1));
	}
	cout << "���ַ����ķ�ת�ַ���Ϊ��" << endl;
	for (i = 0; i < j; i++)
	{
		cout << *(q + i);
	}
	cout << endl << endl;
}