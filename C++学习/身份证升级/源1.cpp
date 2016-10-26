/*
#include<iostream> 
#include<cstring> 
#include<iomanip>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=1990, int m=1, int d=1){year = y;month = m;day = d;}
	int getY()const{ return year; }
	int getM()const{ return month; }
	int getD()const{ return day; }
};
class PID
{
	int type;
	char num[100];
	Date t;
public:
	PID(int ye, int mo, int da, int lei, char nu[]) :t(ye, mo, da), type(lei){strcpy(num, nu);}
	void print()
	{
		cout << "type=" << type << " birth=" << t.getY() << '.';
		cout << setfill('0') << setw(2) << t.getM() << '.' << setw(2) << t.getD() << endl;
		cout << "ID=" << num << endl;
	}
	void Lvup()
	{
		if (type == 2)
			return;
		else
		{
			type = 2;
			int i;
			int sum=0;
			char tmp[100];
			char aa, bb;
			for (i = 0; i<6; i++)
				tmp[i] = num[i];
			aa = t.getY() / 1000+'0';
			tmp[6] = aa;
			bb = t.getY() / 100 - 10 * (t.getY() / 1000) + '0';
			tmp[7] = bb;
			for (i = 6; i<15; i++)
				tmp[i + 2] = num[i];
			for (i = 0; i<17; i++)
			{
				sum = sum + int(tmp[i] - '0');
			}
			if (sum % 10 == 0)
			{
				tmp[17] = 'X';
			}
			else
			{
				tmp[17] = '0' + sum % 10;
			}
			tmp[18] = 0;
			strcpy(num,tmp);
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
		char uid[100];
		int uy, um, ud;
		cin >> ulei;
		cin >> uid;
		cin >> uy >> um >> ud;
		PID sfz(uy, um, ud, ulei, uid);
		sfz.Lvup();
		sfz.print();
	}
	return 0;
}
*/