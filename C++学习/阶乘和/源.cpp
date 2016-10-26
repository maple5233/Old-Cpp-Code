#include<iostream>
using namespace std;
int jch(int);
int jc(int);
int main()
{
	int a;
	cin >> a;
	cout<<jch(a)<<endl;
	system("pause");
}
int jc(int a)
{
	if (a == 1)
		return a;
	else
		return jc(a - 1)*a;
}
int jch(int a)
{
	if (a == 1)
		return a;
	else
		return jch(a - 1) + jc(a);
}