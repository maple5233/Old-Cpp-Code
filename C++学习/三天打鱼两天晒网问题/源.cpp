#include<iostream>
using namespace std;
int days(struct dateday);
struct date
{ 
	int year;
	int month;
	int day;
};
int days(struct date day)/*���㱾������ 1 �� 1 ���������*/
{
	static int day_tab[2][13] =
	{ { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int i, lp;
	lp = day.year % 4 == 0 && day.year % 100 != 0 || day.year % 400 == 0;//lp==0 Ϊƽ�꣬��0Ϊ����
	for (i = 1; i<day.month; i++) 
		day.day += day_tab[lp][i];
	return day.day;
}
int main()
{
	date today,term;
	int yearday = 0;
	int year = 1990;
	bool leap;

	cout << "���������ڣ�" << endl;
	cin >> today.year >> today.month >> today.day;
	
	/*����� 1990 ����ָ�����ǰһ�깲�ж�����*/
	for (; year<today.year; year++)
	{
		leap = bool(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
		if (leap)
		{
			yearday += 366;
		}
		else
		{
			yearday += 365;
		}
	}
	yearday += days(today);

	int day = yearday % 5;
	
	if (day>0 && day<4)
	{
		cout << "���ڴ��㡣" << endl;
	}
	else
	{
		cout << "����ɹ����" << endl;
	}
	system("pause");
	return 0;
}

