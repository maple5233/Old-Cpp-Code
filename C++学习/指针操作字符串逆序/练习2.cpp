/*编写程序，利用指针操作，编写一个函数将字符串反序，在主函数中调用该函数将用户输入的一个字符串反序输出。*/
#include<iostream>
#include<cstring>
using namespace std;
void fan(char*,char*,int);
int main()
{
	char a[10000];
	char b[10000];
	int l;
	cout << "请输入字符串:" << endl;
	cin >> a;
	cout << endl;
	l = strlen(a);
	fan(a,b,l);
	cout << "感谢您的使用！"<<endl<<endl;
	system("pause");
}
void fan(char* p,char* q,int j)
{
	int i;
	for (i = 0; i < j; i++)
	{
		*(q + i) = *(p + (j - i - 1));
	}
	cout << "该字符串的反转字符串为：" << endl;
	for (i = 0; i < j; i++)
	{
		cout << *(q + i);
	}
	cout << endl << endl;
}