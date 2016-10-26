#include<iostream>
using namespace std;
class CDate
{
private:
	int month;
	int day;
	int year;
	int week;
public:
	CDate();
	CDate(int y, int m, int d);
	void print();
	void getWeekofDay();
};
CDate::CDate()
{
	year = 1990;
	month = 1;
	day = 1;
	week = 0;
}
CDate::CDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	week = 0;
}
void CDate::print()
{
	cout << month << "/" << day << "/" << year << ", ";
	switch (week)
	{
	case 0:cout << "unknown" << endl; break;
	case 1:cout << "Monday" << endl; break;
	case 2:cout << "Tuesday" << endl; break;
	case 3:cout << "Wednesday" << endl; break;
	case 4:cout << "Thursday" << endl; break;
	case 5:cout << "Friday" << endl; break;
	case 6:cout << "Saturday" << endl; break;
	case 7:cout << "Sunday" << endl; break;
	default:
		cout << "unknown" << endl; break;
	}
}
void CDate::getWeekofDay()
{
	if (month == 1)
	{
		week = (day + 2 * 13 + 3 * (13 + 1) / 5 + (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7 + 1;
	}
	if (month == 2)
	{
		week = (day + 2 * 14 + 3 * (14 + 1) / 5 + (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7 + 1;
	}
	if (month > 3 && month <= 12)
	{
		week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7 + 1;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int uy, um, ud;
		cin >> uy >> um >> ud;
		CDate a(uy, um, ud);
		a.getWeekofDay();
		a.print();
	}
	return 0;
}