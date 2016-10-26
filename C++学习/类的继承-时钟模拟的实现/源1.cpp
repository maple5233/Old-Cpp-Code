#include<iostream>
#include<cmath>
using namespace std;
class JSQ
{
protected:
	int value;
public:
	JSQ(int v){ value = v; }
	~JSQ(){}
	void increment()
	{
		value++;
	}
};
class XHJSQ :public JSQ
{
private:
	int min, max;
public:
	XHJSQ(int n, int x, int v) :JSQ(v){ min = n; max = x; }
	~XHJSQ(){}
	bool increment()
	{
		if (value == max)
		{
			value = min;
			return true;
		}
		else
		{
			value++;
			return false;
		}
	}
	int getV(){ return value; }
	void setV(int v){ value = v; }
};
class CL
{
private:
	XHJSQ hour, second, minute;
public:
	CL(int h1, int h2, int h3, int m1, int m2, int m3, int s1, int s2, int s3) :hour(h1, h2, h3), minute(m1, m2, m3), second(s1, s2, s3){}
	~CL(){}
	void time(int i)
	{
		while (i--)
		{
			if (second.increment())
			{
				if (minute.increment())
				{
					hour.increment();
				}
			}
		}
	}
	void display()
	{
		cout << hour.getV() << ':' << minute.getV() << ':' << second.getV() << endl;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int uh, um, us, guo;
		cin >> uh >> um >> us >> guo;
		CL s(0, 23, uh, 0, 59, um, 0, 59, us);
		s.time(guo);
		s.display();
	}
	return 0;
}