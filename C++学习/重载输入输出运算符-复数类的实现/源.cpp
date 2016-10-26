#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(){real = 0; imag = 0; }
	Complex(double r, double i){ real = r; imag = i; }
	friend Complex operator + (Complex& c1,Complex &c2);
	friend Complex operator - (Complex& c1, Complex &c2);
	friend ostream& operator << (ostream& output, Complex& c); 
	friend istream& operator >> (istream& input , Complex& c );
private:
	double real;
	double imag;
};
Complex operator + (Complex& c1, Complex &c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator - (Complex& c1, Complex &c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
istream& operator >> (istream& input, Complex& c)
{
	input >> c.real >> c.imag;
	return input;
}
ostream& operator << (ostream& output, Complex& c)
{
	if (c.imag == 0)
		output << c.real << endl;

	if (c.real == 0 && c.imag == 1)
		output << 'i' << endl;
	if (c.real == 0 && c.imag == -1)
		output << "-i" << endl;

	if (c.real == 0 && c.imag != 0 && c.imag != 1 && c.imag != -1)
		output << c.imag << 'i' << endl;

	if (c.real != 0 && c.imag == 1)
		output << c.real << "+i" << endl;
	if (c.real != 0 && c.imag == -1)
		output << c.real << "-i" << endl;

	if (c.real != 0 && c.imag<0 && c.imag != -1)
		output << c.real << c.imag << 'i' << endl;
	if (c.real != 0 && c.imag>0 && c.imag != 1)
		output << c.real << '+' << c.imag << 'i' << endl;

	return output;
}
int main()
{
	Complex a, b;
	cin >> a >> b;
	cout << a + b;
	cout << a - b;
	system("pause");
	return 0;
}