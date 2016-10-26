#include<iostream>
#include <algorithm>
using namespace std;

int longest_plateau1(int x[], int n)
{
	
	int i = 1,length=1;
	for (i = 1; i < n; i++)
	{
		if (x[i] == x[i - length])
			length++;
	}
	return length;
}
//�Ϻõ����������� ���ϰ���󳤶ȴ����������ƶ�
int longest_plateau2(int x[], int n)
{
	int i = 0 , length=1,count=1;
	for (i = 0; i < n; i++)
	{
		if (x[i] != x[i + 1])
		{
			length = count >= length ? count : length;
			count = 1;
			continue;
		}
		count++;
	}
	return length;
}
int main()
{
	cout << "���������鳤�ȣ�" << endl;
	int n,i;
	cin >> n;
	int* x = new int[n];
	cout << "�����������������ݣ�" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	cout << "����Ԫ�����£�" << endl;
	for (i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	sort(x, x + n);
	cout << endl<<endl;

	cout << "ʹ�ú���1���������󳤶�Ϊ";
	cout << longest_plateau1(x, n) << endl<<endl;
	cout << "ʹ�ú���2���������󳤶�Ϊ";
	cout << longest_plateau2(x, n) << endl<<endl;
	system("pause");
	delete[] x;
	return 0;
}