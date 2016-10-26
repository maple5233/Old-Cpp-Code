#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include<iomanip>
using namespace std;
class Date
{
private:
	string day, year, month;
public:
	Date(string y = "1990", string m = "1", string d = "1") { day = d; year = y; month = m; }
	string getD()const { return day; }
	string getY()const { return year; }
	string getM()const { return month; }
};
class PID
{
private:
	int lei;
	string num;
	Date t;
public:
	PID(int l, string nu, string ye, string mo, string da) : t(ye, mo, da), lei(l), num(nu){}
	void print()
	{
		cout << "type=" << lei << " birth=" << t.getY() << '.';
		cout << setfill('0') << setw(2) << t.getM() << '.' << setw(2) << t.getD() << endl;
		cout << "ID=" << num << endl;
	}
	void Lvup()
	{
		if (lei == 2)
		{
			return;
		}
		else
		{
			lei = 2;
			string tmp,tmp1;
			int shu = 0, i = 0;
			tmp.assign(num, 0, 6);
			tmp = tmp + t.getY();
			tmp1.assign(num, 8, 7);
			tmp = tmp + tmp1;
			for (i = 0; i < tmp.length(); i++)
			{
				shu = shu + int(tmp[i] - '0');
			}
			shu = shu % 10;
			switch (shu)
			{
			case 0:tmp = tmp + "X";  break;
			case 1:tmp = tmp + "1";  break;
			case 2:tmp = tmp + "2";  break;
			case 3:tmp = tmp + "3";  break;
			case 4:tmp = tmp + "4";  break;
			case 5:tmp = tmp + "5";  break;
			case 6:tmp = tmp + "6";  break;
			case 7:tmp = tmp + "7";  break;
			case 8:tmp = tmp + "8";  break;
			case 9:tmp = tmp + "9";  break;
			default:
				break;
			}
			num = tmp;
		}
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int ulei;
		string uid;
		string uy, um, ud;
		cin >> ulei;
		cin >> uid;
		cin >> uy >> um >> ud;
		PID sfz(ulei, uid, uy, um, ud);
		sfz.Lvup();
		sfz.print();
	}
	return 0;
}