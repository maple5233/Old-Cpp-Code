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
	T.push('@');
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
				s2 += T.top();
				T.pop();
			}

			T.pop();
			ch = s1[++i];
			s2 += ' ';
		}
		/*除括号外的其他运算符， 当其优先级高于除'('以外的栈顶运算符时，直接入栈。
		否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止。*/
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			char w = T.top();
			while (Precedence(w) >= Precedence(ch))
			{
				s2 += w;
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
double Calculater(double a, double b, char c)
{
	switch (c)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	default:
		break;
	}
}

/****************检查是不是运算符或者空格*********************/
bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/'||c==' ')
	{
		return true;
	}
	return false;
}

/****************后缀表达式求值******************************/
double CalculateAll(string s)
{
	stack<double> T;
	double result = 0;
	char tmp[100] = { 0 };//临时存储浮点数
	int i = 0;
	double tmpnum;
	double a, b;

	for (string::iterator it = s.begin(); it != s.end();)//使用string的迭代器
	{
		char ch = *(it);
		if (ch == ' ')
		{
			it++;
			continue;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			a = T.top();
			T.pop();
			b = T.top();
			T.pop();
			result = Calculater(a, b, ch);
			T.push(result);
			it++;
		}
		else
		{
			while (!isOper(ch))
			{
				tmp[i] = ch;
				tmp[i + 1] = 0;
				i++;
				it++;
				ch = *(it);
			}
			tmpnum = (double)(atof(tmp));//字符串转化为浮点
			tmp[0] = 0;
			i = 0;//清空临时浮点字符串数组并将索引归零
			T.push(tmpnum);
		}
	}
	result = T.top();
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