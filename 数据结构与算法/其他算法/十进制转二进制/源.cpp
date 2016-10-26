#include<iostream>
#include<cstdio>
using namespace std;
//限整数部分
void DtoB(int d)
{
	if (d / 2)
		DtoB(d / 2);
	cout << d % 2<<endl;
}
int main()
{
	int T;
	cin >> T;
	DtoB(T);
	system("pause");
	return 0;
}