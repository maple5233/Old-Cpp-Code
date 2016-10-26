#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Complex
{
private:
	double a, b;
public:
	Complex();
	Complex(double a0, double b0);
	Complex jia(Complex fs2);
	Complex jian(Complex fs2);
	void print();
};
Complex::Complex()
{
	a = 1;
	b = 1;
}
Complex::Complex(double a0, double b0)
{
	a = a0;
	b = b0;
}
Complex Complex::jia(Complex fs2)
{
	Complex fs3;
	fs3.a = a + fs2.a;
	fs3.b = b + fs2.b;
	return fs3;
}
Complex Complex::jian(Complex fs2)
{
	Complex fs3;
	fs3.a = a - fs2.a;
	fs3.b = b - fs2.b;
	return fs3;
}
void Complex::print()
{
	if (b == 0)
		cout << a;

	if (a == 0 && b == 1)
		cout << "i";
	if (a == 0 && b == -1)
		cout << "-i";

	if (a != 0 && b == 1)
		cout << a << '+' << 'i';
	if (a != 0 && b == -1)
		cout << a << '-' << 'i';

	if (a == 0 && b != 1 && b != -1 && b != 0)
		cout << b << "i";

	if (a != 0 && b>0 && b != 1)
		cout << a << "+" << b << 'i';
	if (a != 0 && b<0 && b != -1)
		cout << a << b << 'i';
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		double ua1, ub1, ua2, ub2;
		cin >> ua1 >> ub1 >> ua2 >> ub2;
		Complex fs1(ua1, ub1);
		Complex fs2(ua2, ub2);
		Complex	he, cha;
		he = fs1.jia(fs2);
		cha = fs1.jian(fs2);
		cout << "sum:";
		he.print();
		cout << endl;
		cout << "remainder:";
		cha.print();
		cout << endl;
	}
	return 0;
}
