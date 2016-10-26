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
	int getYear();//���ڷ������˽�����ݵĽӿ�
	int getMonth();//ͬ��
	int getDay();//ͬ��
	void setDate(int y, int m, int d);//�������ำֵ
	void print();//�����ġ���/��/�ա�
	void addOneDay();//����һ��
};

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}//�޲������캯��

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}//���� �в������캯��

int Date::getYear(){ return year; }
int Date::getMonth(){ return month; }
int Date::getDay(){ return day; }//��ȡ�������

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
	}//�������һ��
	else
	{
		if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 30))
		{
			month++;
			day = 1;
		}//С�����һ��
		else
		{
			if ((month == 2) && (year % 4 == 0) && (year % 400 != 0) && (day == 29))
			{
				month++;
				day = 1;
			}//����Ķ������һ��
			else
			{
				if ((month == 2) && (year % 4 != 0) && (day == 28))
				{
					month++;
					day = 1;
				}//ƽ��Ķ������һ��
				else
				{
					if ((month == 12) && (day == 31))
					{
						year++;
						month = 1;
						day = 1;
					}//һ������һ��
					else day++;//��ͨ��һ��
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
