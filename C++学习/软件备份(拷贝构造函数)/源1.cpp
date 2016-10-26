#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class CDate
{
private:
	int year, month, day;
public:
	CDate(){year = 0; month = 0; day = 0; }
	CDate(int y, int m, int d) { year = y; month = m; day = d; }
	bool isLeapYear() { return (year % 4 != 0 ) || year % 400 == 0; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getDayofYear()
	{
		int i, sum = day;
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int b[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (isLeapYear())
		for (i = 0; i<month; i++)   sum += b[i];
		else
		for (i = 0; i<month; i++)   sum += a[i];
		return sum;
	}
};
class Ruan
{
private:
	string name;
	char type;
	CDate jiezhi;
	char cun;
public:
	Ruan(){ name = "no name"; type = ' '; cun = ' '; }
	Ruan(string na, char ty, char cu, int ye, int mo, int da) :jiezhi(ye, mo, da), name(na), type(ty), cun(cu){}
	Ruan(const Ruan &a){ name = a.name; type = 'B'; cun = 'H'; jiezhi = a.jiezhi; }
	void print()
	{
		cout << "name:" << name<<endl;
		cout << "type:";
		switch (type)
		{
		case'O':cout << "original" << endl;break;
		case'B':cout << "backup" << endl; break;
		case'T':cout << "trial" << endl; break;
		default:cout << endl; break;
		}
		cout << "media:";
		switch (cun)
		{
		case'D':cout << "optical disk" << endl; break;
		case'H':cout << "hard disk" << endl; break;
		case'U':cout << "USB disk" << endl; break;
		default:cout << endl; break;
		}
		cout << "this software ";
		int d1,d2,d3;
		char d4;
		d1 = jiezhi.getDayofYear();
		CDate jt(2015, 4, 7);
		d2 = jt.getDayofYear();
		d3 = d1 - d2;
		if (jiezhi.getDay() == 0 && jiezhi.getMonth() == 0 && jiezhi.getYear() == 0)
		{
			d4 = 'X';
		}
		else
		{
			if (d3 > 0)
				d4 = 'A';
			if (d3 <= 0) 
				d4 = 'B';
		}
		switch (d4)
		{
		case 'A':cout << "is going to be expired in " << d3 << " days" << endl; break;
		case 'B':cout << "has expired" << endl; break;
		case 'X':cout << "has unlimited use" << endl; break;
		default:
			break;
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string uname;
		char utype;
		char ucun;
		int uyear, umonth, uday;
		cin >> uname >> utype >> ucun >> uyear >> umonth >> uday;
		Ruan ruan(uname,utype,ucun,uyear,umonth,uday);
		Ruan bruan(ruan);
		ruan.print();
		cout << endl;
		bruan.print();
		cout << endl;
	}
}