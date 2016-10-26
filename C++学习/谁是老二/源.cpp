/*定义一个结构体，包含年月日，表示一个学生的出生日期。然后在一群学生的出生日期中找出谁的出生日期排行第二

要求：出生日期的存储必须使用结构体，不能使用其他类型的数据结构。

要求程序全过程对出生日期的输入、访问、输出都必须使用结构。*/

/*第一行输入t表示有t个出生日期

每行输入三个整数，分别表示年、月、日

依次输入t个实例*/

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