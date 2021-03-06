#include<iostream>
#include<stack>
#include<string>
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
	case '^':
	case '%':
		return 3;
	case'@':
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
int Calculater(char a, char b, char c)//a,b是操作数，c为操作符
{
	int aa, bb;
	aa = a - '0';
	bb = b - '0';
	switch (c)
	{
	case '+':return aa + bb;
	case '-':return aa - bb;
	case '*':return aa * bb;
	case '/':return aa / bb;
	case '^':return aa ^ bb;
	case '%':return aa % bb;
	default:
		return 0;
	}
}

/******************判断是不是运算符***************************/
bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '(' || c == ')' || c == '@')
	{
		return true;
	}
	return false;
}

/********************中缀表达式计算工具************************/
int CalculateAll(string s)
{
	stack<char> oper;//存储运算符
	stack<char> num;//存储操作数和运算结果
	oper.push('@');
	int result = 0;
	char a, b, c, x;
	for (string::iterator it = s.begin();;)//使用string的迭代器
	{
		c = *(it);
		if (c != '@' || oper.top() != '@')//判断是否计算完成
		{
			if (c == ' ')//跳过空格
			{
				it++;
				continue;
			}
			else if (!isOper(c))//数字进栈
			{
				num.push(c);
				it++;
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
				else//栈顶元素优先级高 或者两个同样的符号相遇 运算，不扫描下一个
				{//运算操作
					x = oper.top();
					oper.pop();

					a = num.top();
					num.pop();

					b = num.top();
					num.pop();

					num.push(Calculater(b, a, x) + '0');
					continue;
				}
			}// end else
		}// end if
		else
		{
			return (num.top() - '0');
		}
	}//end for
}

int main()
{
	string s;
	int result;

	cout << "请输入算式：" << endl;
	cin >> s;

	s += '@';
	result = CalculateAll(s);

	cout << "计算结果为" << result << "。" << endl;
	system("pause");

	return 0;
}