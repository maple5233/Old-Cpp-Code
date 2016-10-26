#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Date
{
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();//用于访问类的私有数据的接口
	int getMonth();//同上
	int getDay();//同上
	void setDate(int y, int m, int d);//用来给类赋值
	void print();//输出类的“年/月/日”
	void addOneDay();//增加一天
};

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}//无参数构造函数

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}//重载 有参数构造函数

int Date::getYear(){ return year; }
int Date::getMonth(){ return month; }
int Date::getDay(){ return day; }//读取类的数据

void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::print()
{
	cout << setfill('0');
	cout << year << '/' << setw(2) << month << '/' << setw(2) << day << endl;
}
void Date::addOneDay()
{
	if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10)) && (day == 31))
	{
		month++;
		day = 1;
	}//大月最后一天
	else
	{
		if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 30))
		{
			month++;
			day = 1;
		}//小月最后一天
		else
		{
			if ((month == 2) && (year % 4 == 0) && (year % 400 != 0) && (day == 29))
			{
				month++;
				day = 1;
			}//闰年的二月最后一天
			else
			{
				if ((month == 2) && (year % 4 != 0) && (day == 28))
				{
					month++;
					day = 1;
				}//平年的二月最后一天
				else
				{
					if ((month == 12) && (day == 31))
					{
						year++;
						month = 1;
						day = 1;
					}//一年的最后一天
					else day++;//普通的一天
				}
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Date today(a, b, c);
		cout << "Today is ";
		today.print();
		today.addOneDay();
		cout << "Tomorrow is ";
		today.print();
	}
	return 0;
}
