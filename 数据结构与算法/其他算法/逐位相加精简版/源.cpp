/*ʵ�ֵĹ���������һ����Ȼ��������ӣ�����ѭ�������� ֱ��Ϊ��λ����
��������63����������9 ��6+3=9�� ����87����������6��8+7=15 1+5=6�� ����666����������9*/

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