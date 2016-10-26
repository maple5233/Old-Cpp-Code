#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;
class CFraction
{
private:
	int fz, fm;
public:
	void init(int fz_val, int fm_val);//赋值函数
	CFraction add(const CFraction &r);//加
	CFraction sub(const CFraction &r);//减
	CFraction mul(const CFraction &r);//乘
	CFraction div(const CFraction &r);//除
	int getGCD();//求最大公约数
	void print();//打印结果
};
void CFraction::init(int fz_val, int fm_val)
{
	fz = fz_val;
	fm = fm_val;
}
int CFraction::getGCD()
{
	int temp, a, b;
	a = fz;
	b = fm;
	do
	{
		temp = a%b;
		a = b;
		b = temp;
	} while (temp != 0);
	return a;//辗转相除法
}
CFraction CFraction::add(const CFraction &r)
{
	CFraction p;
	int q;
	int fz1 = fz, fm1 = fm;//存储被加数的分子分母
	int fz2 = r.fz, fm2 = r.fm;//存储加数的分子分母
	int fm3 = fm1*fm2;
	int fz3 = fz1*fm2 + fz2*fm1;
	p.init(fz3, fm3);//结果赋给p，用以求最大公约数
	q = p.getGCD();
	int fz4 = fz3 / q;
	int fm4 = fm3 / q;//约分
	if (fm4<0)
	{
		fm4 = -fm4;
		fz4 = -fz4;
	}//如果分母是负数就把分母分子都乘以负1 保证分母是正的
	p.init(fz4, fm4);
	return p;
}
CFraction CFraction::sub(const CFraction &r)
{
	CFraction p;
	int q;
	int fz1 = fz, fm1 = fm;
	int fz2 = r.fz, fm2 = r.fm;
	int fm3 = fm1*fm2;
	int fz3 = fz1*fm2 - fz2*fm1;
	p.init(fz3, fm3);
	q = p.getGCD();
	int fz4 = fz3 / q;
	int fm4 = fm3 / q;
	if (fm4<0)
	{
		fm4 = -fm4;
		fz4 = -fz4;
	}
	p.init(fz4, fm4);
	return p;
}
CFraction CFraction::mul(const CFraction &r)
{
	CFraction p;
	int q;
	int fz1 = fz, fm1 = fm;
	int fz2 = r.fz, fm2 = r.fm;
	int fm3 = fm1*fm2;
	int fz3 = fz1*fz2;
	p.init(fz3, fm3);
	q = p.getGCD();
	int fz4 = fz3 / q;
	int fm4 = fm3 / q;
	if (fm4<0)
	{
		fm4 = -fm4;
		fz4 = -fz4;
	}
	p.init(fz4, fm4);
	return p;
}
CFraction CFraction::div(const CFraction &r)
{
	CFraction p;
	int q;
	int fz1 = fz, fm1 = fm;
	int fz2 = r.fz, fm2 = r.fm;
	int fm3 = fm1*fz2;
	int fz3 = fz1*fm2;
	p.init(fz3, fm3);
	q = p.getGCD();
	int fz4 = fz3 / q;
	int fm4 = fm3 / q;
	if (fm4<0)
	{
		fm4 = -fm4;
		fz4 = -fz4;
	}
	p.init(fz4, fm4);
	return p;
}
void CFraction::print()
{
	cout << fz << "/" << fm << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		CFraction m, n, jia, jian, cheng, chu;
		int r1, r2, r3, r4;
		cin >> r1;
		getchar();//用来跳过输入时的第一个分数线
		cin >> r2 >> r3;
		getchar();//用来跳过输入时的第二个分数线
		cin >> r4;
		m.init(r1, r2);
		n.init(r3, r4);
		jia = m.add(n);
		jian = m.sub(n);
		cheng = m.mul(n);
		chu = m.div(n);
		jia.print();
		jian.print();
		cheng.print();
		chu.print();
		cout << endl;
	}
	return 0;
}
