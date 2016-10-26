#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
	这种方法思路是先将中缀表达式一次性转化为后缀表达式，再进行后缀表达式的运算
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
	case '(':
	case'@':
	default:
		return 0;
	}
}

/****************中缀表达式转换成后缀表达式********************/
void Change(string s1, string& s2)
{
	stack<char> T;
	int i = 0;
	char ch;
	T.push( '@');
	ch = s1[i];
	while (ch != '\0')
	{
		if (ch == ' ')//跳过空格
			ch = s1[++i];
		else if (ch == '(')//左括号直接进栈
		{
			T.push(ch);
			ch = s1[++i];
		}
		else if (ch == ')')//出现右括号 则依次把栈中的的运算符加入后缀表达式中，直到出现'('，从栈中删除'(' 
		{
			while (T.top() != '(')
			{
				s2+= T.top();
				T.pop();
			}
				
			T.pop();
			ch = s1[++i];
			s2 += ' ';
		}
		/*除括号外的其他运算符， 当其优先级高于除'('以外的栈顶运算符时，直接入栈。
		否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止。*/
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
		{
			char w = T.top();
			while (Precedence(w) >= Precedence(ch))
			{
				s2+= w;
				T.pop();
				w = T.top();
			}
			T.push(ch);
			ch = s1[++i];
			s2 += ' ';
		}
		else
		{
			while ((ch >= '0' && ch <= '9') || ch == '.')//数字直接加入后缀表达式
			{
				s2 += ch;
				ch = s1[++i];
			}
			s2 += ' ';
		}
	}
	ch = T.top();
	T.pop();
	while (ch != '@')
	{
		s2 += ch;
		ch = T.top();
		T.pop();
	}
}

/******************二元计算器***************************/
int Calculater(char a, char b,char c)
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
		break;
	}
}

/****************后缀表达式求值******************************/
int CalculateAll (string s)
{
	stack<char> T;
	int result=0;
	for (string::iterator it = s.begin(); it != s.end(); ++it)//使用string的迭代器
	{
		char ch = *(it);
		char a, b;
		if (ch == ' ')
		{
			continue;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
		{
			a = T.top();
			T.pop();
			b = T.top();
			T.pop();
			result = Calculater(a, b, ch);
			result += '0';
			T.push(result);
		}
		else
		{
			T.push(ch);
		}
	}
	char re = T.top();
	result = re - '0';
	return result;
}

int main()
{
	string infix, suffix;
	cout << "请输入算式" << endl;
	cin >> infix;
	cout << "转化为中缀表达式的结果为" << endl;
	Change(infix, suffix);
	cout << suffix << endl;
	cout << "计算结果为" << endl;
	cout << CalculateAll(suffix) << endl;
	system("pause");
	return 0;
}