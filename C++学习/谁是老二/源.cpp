/*����һ���ṹ�壬���������գ���ʾһ��ѧ���ĳ������ڡ�Ȼ����һȺѧ���ĳ����������ҳ�˭�ĳ����������еڶ�

Ҫ�󣺳������ڵĴ洢����ʹ�ýṹ�壬����ʹ���������͵����ݽṹ��

Ҫ�����ȫ���̶Գ������ڵ����롢���ʡ����������ʹ�ýṹ��*/

/*��һ������t��ʾ��t����������

ÿ�����������������ֱ��ʾ�ꡢ�¡���

��������t��ʵ��*/

#include <iostream>
using namespace std;

struct Student
{
	int year;
	int mon;
	int day;
};


int main()
{
	int t, i, j;
	cin >> t;
	Student student[10], temp;
	for (i = 0; i<t; i++)
	{
		cin >> student[i].year >> student[i].mon >> student[i].day;
	}
	for (i = 1; i<t; i++)
	{

		for (j = 0; j<t - i; j++)
		{

			if (student[j + 1].year<student[j].year || (student[j + 1].year == student[j].year && student[j + 1].mon<student[j].mon)
				|| (student[j + 1].year == student[j].year&&student[j + 1].mon == student[j].mon && student[j + 1].day<student[j].day))
			{
				temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}


	}

	cout << student[1].year << "-" << student[1].mon << "-" << student[1].day << endl;

	return 0;
}