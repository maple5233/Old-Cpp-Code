#include<iostream>
using namespace std;
void Swap(int&a, int&b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
int main()
{
	int a, b;
	cout << "������a,b��" << endl;
	cin >> a >> b;
	Swap(a, b);
	cout << "������a=" << a << ",b=" << b << endl;
	system("pause");
	return 0;
}