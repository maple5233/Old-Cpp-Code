/*定义并实现三个函数：

第一个函数是整数函数，返回类型为整数，参数是一个整数变量，操作是求该变量的平方值

第二个函数是浮点数函数，返回类型为浮点数，参数是一个浮点数变量，操作是求该变量的平方根值。求平方根可以使用函数sqrt（浮点参数），将返回该参数的平方根，在VC中需要头文件cmath。

第三个函数是字符串函数，无返回值，参数是一个字符串指针，操作是把这个字符串内所有小写字母变成大写。

要求：定义三个函数指针分别指向这三个函数，然后根据调用类型使用函数指针来调用这三个函数。不能直接调用这三个函数。

如果类型为I，则通过指针调用整数函数；如果类型为F，则通过指针调用浮点数函数；如果类型为S，则通过指针调用字符串函数*/

/*第一行输入一个t表示有t个测试实例

每行先输入一个大写字母，表示调用类型，然后再输入相应的参数

依次输入t行*/

#include<iostream>
#include<cmath>
using namespace std;
int I(int a);
float F(float b);
void S(char *p);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char x;
		cin >> x;
		if (x == 'I')
		{
			int j;
			cin >> j;
			cout << I(j) << endl;
		}
		if (x == 'F')
		{
			float j;
			cin >> j;
			cout << F(j) << endl;
		}
		if (x == 'S')
		{
			char j[50];
			cin >> j;
			S(j);
			cout << j << endl;
		}
	}
	return 0;
}

int I(int a)
{
	int c;
	c = a*a;
	return c;
}

float F(float b)
{
	float c;
	c = sqrt(b);
	return c;
}

void S(char *p)
{
	while (*p != 0)
	{
		if (*p >= 'a'&&*p <= 'z')
			*p = *p - 'a' + 'A';
		p++;
	}
}