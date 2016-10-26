#include <iostream>
#include<string>
#include "Student.h"
using namespace std;

template<class T>
void swap(T&a,T&b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	string a = "1", b = "2";
	char c = 1.1, d = 2.2;
	swap(a, b);
	swap(c, d);
	istream aa;
	ostream bb;

	cin >> a;
	cout << a;
}