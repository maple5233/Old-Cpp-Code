/*******************************
* p5_9.cpp                     *
* 超长整数加法                 *
********************************/
#include <iostream>
using namespace std;
char *ladd(char *s1, char *s2)
{
	int n1, n2, i, n;
	char *res, c = 0;
	n1 = strlen(s1);            //n1=数字串s1的长度
	n2 = strlen(s2);            //n2=数字串s2的长度
	n = n1>n2 ? n1 : n2;      //数字串s1,s2最大长度
	res = new char[n + 2];       //申请存结果串的内存
	for (i = n + 1; i >= 0; i--)   //将s1从低位开始搬到res，没有数字的位以及最高位填'0'
		res[i] = i>n - n1 ? s1[i - n - 1 + n1] : '0';
	for (i = n; i >= 0; i--)
	{
		char tchar;
		tchar = i>n - n2 ? res[i] - '0' + s2[i - n + n2 - 1] - '0' + c : res[i] - '0' + c; //将数字符变成数
		c = tchar>9 ? 1 : 0;                           //设进位
		res[i] = c>0 ? tchar - 10 + '0' : tchar + '0';            //将数字变成数字字符
	}
	return res;
}
void main() {
	char num1[100], num2[100], *num;
	cin >> num1 >> num2;
	num = ladd(num1, num2);
	cout << num1 << "+" << num2 << "=" << num << endl;
	delete[] num;
}