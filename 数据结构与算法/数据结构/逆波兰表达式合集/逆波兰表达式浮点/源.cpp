#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
/*
这种方法思路是使用两个栈，一个存储操作数和运算结果，另外一个存储运算符，一边转化为后缀表达式一边计算后缀表达式
*/


/******************优先级判断*******************************/
int Precedence(char sign)
{
	switch (sign)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case'#':
		return 0;
	case '(':
		return 0;
	case ')':
		return 0;
	default:
		return 0;
	}
}

/******************二元计算器***************************/
double Calculater(double a, double b, char c)//a,b是操作数，c为操作符
{
	switch (c)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	default:
		return 0;
	}
}

/******************判断是不是运算符***************************/
bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')
	{
		return true;
	}
	return false;
}

/********************中缀表达式计算工具************************/
double CalculateAll(string s)
{
	stack<char> oper;//存储运算符
	stack<double> num;//存储操作数和运算结果
	oper.push('#');

	char tmp[100] = {0};//临时存储浮点数
	int i = 0;
	double tmpnum; 

	double result = 0;
	double a = 0, b = 0;
	char c, x;

	string::iterator it = s.begin();//使用string的迭代器
	while(1)
	{
		c = *(it);
		if (c != '#' || oper.top() != '#')//判断是否计算完成
		{
			if (c == ' ')//跳过空格
			{
				it++;
				continue;
			}
			else if (!isOper(c))//数字进栈
			{
				while (!isOper(c))
				{
					tmp[i] = c;
					tmp[i + 1] = 0;
					i++;
					it++;
					c = *(it);
				}
				tmpnum = (double)(atof(tmp));//字符串转化为浮点
				tmp[0] = 0;
				i = 0;//清空临时浮点字符串数组并将索引归零
				num.push(tmpnum);
				continue;
			}
			else
			{
				if (oper.top() == '('&&c == ')')//脱括号，扫描下一个
				{//出栈操作
					oper.pop();
					it++;
					continue;
				}
				else if (c == '(')//左括号固定进栈
				{
					oper.push(c);//进栈操作
					it++;
					continue;
				}
				else if (Precedence(oper.top()) < Precedence(c))//栈顶元素优先级低，直接进栈，扫描下一个
				{
					oper.push(c);//进栈操作
					it++;
					continue;
				}
				else//栈顶元素优先级高 或者两个同样的符号相遇 运算，不扫描下一个 下次继续比较栈顶元素和c
				{//运算操作
					x = oper.top();
					oper.pop();

					a = num.top();
					num.pop();

					b = num.top();
					num.pop();

					num.push(Calculater(b, a, x));
					continue;
				}
			}// end else
		}// end if
		else
		{
			return (num.top());
		}
	}//end for
}

int main()
{
	int t;
	cin >> t;
	string s;
	double result;
	while (t--)
	{
		cin >> s;
		result = CalculateAll(s);
		cout << fixed << setprecision(4) << result << endl;
	}
	return 0;
}