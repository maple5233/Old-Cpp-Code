#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(){ year = 1990; month = 01; day = 01; }
	Date(int ye, int mo, int da){ year = ye; month = mo; day = da; }
	void print(){ cout << year << '.' << month << '.' << day; }
};
class Pho
{
private:
	char type;
	string no;
	int zt;
	Date *p;
public:
	Pho(){}
};