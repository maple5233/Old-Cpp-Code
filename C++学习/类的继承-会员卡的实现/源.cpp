#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class VIPCard
{
protected:
	int no;
	int fen;
public:
	VIPCard(int n){ no = n; fen = 0; }
	void XDD(float money1){ fen = fen + int(money1); }
};

class XYCard
{
protected:
	int num;
	char name[10];
	int edu;
	float zhang;
	int jifen;
public:
	XYCard(int nu, char* s, int ed)
	{
		num = nu;
		int i;
		int l = strlen(s);
		for (i = 0; i<l; i++)
		{
			*(name + i) = *(s + i);
		}
		*(name + l) = 0;
		edu = ed;
		zhang = 0;
		jifen = 0;
	}
	void TK(float money2)
	{
		zhang = zhang - money2;
		jifen = jifen - int(money2);
	}
	bool XF(float money3)
	{
		if ((zhang + money3)<edu || (zhang + money3) == edu)
		{
			zhang = zhang + money3;
			jifen = jifen + int(money3);
			return true;
		}
		else
			return false;
	}
};

class Card :public XYCard, public VIPCard
{
public:
	Card(int n, int nu, char* s, int ed) :VIPCard(n), XYCard(nu, s, ed){}
	void DH(int huan)
	{
		fen = fen + huan / 2;
		jifen = jifen - huan;
	}
	void display()
	{
		cout << no << ' ' << fen << endl;
		cout << num << ' ' << name << ' ' << zhang << ' ' << jifen << endl;
	}
};

int main()
{
	int uno, unum, uedu;
	char s[10];
	cin >> uno >> unum >> s >> uedu;
	Card a(uno, unum, s, uedu);
	char c;
	float m;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> c >> m;
		if (c == 'o')
		{
			if(a.XF(m))
			a.XDD(m);
		}
		if (c == 'c')
		{
			a.XF(m);
		}
		if (c == 'q')
		{
			a.TK(m);
		}
		if (c == 't')
		{
			a.DH(m);
		}
	}
	a.display();
	system("pause");
	return 0;
}