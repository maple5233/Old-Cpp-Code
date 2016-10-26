#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isBracket(char c)//判断是不是括号;
{
	if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
		return true;
	return false;
}
bool isLeft(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return true;
	return false;
}
bool isMatch(char a, char b)
{
	if (a == '('&&b == ')')
		return true;
	if (a == '['&&b == ']')
		return true;
	if (a == '{'&&b == '}')
		return true;
	return false;
}
int judgeString(string s)
{
	char c;
	stack<char> tmp;//使用STL库的字符栈;
	char ch;
	string::iterator it ;//使用s的迭代器;

	for (it = s.begin(); it != s.end(); it++)
	{
		c = *(it);//解引用;
		if (!isBracket(c))
		{
			continue;
		}
		else if (isLeft(c))//c是左括号;
		{
			tmp.push(c);
			continue;
		}
		else//c是右括号;
		{
			if (tmp.empty())
				return -2;//右括号多于左括号或括号乱序;
			else
			{
				ch = tmp.top();
				tmp.pop();
				if (!isMatch(ch, c))
				{
					return -1;//配对不正确;
				}
				else
				{
					continue;
				}
			}
		}
	}

	if (tmp.empty())
	{
		return 0;//一切正常;
	}
	else
	{
		return -3;//左括号多于右括号;
	}
}
int main()
{
	int t;
	cin >> t;
	string s;

	while (t--)
	{
		cin >> s;
		switch (judgeString(s))
		{
		case -1:
			cout << "配对不正确" << endl; break;
		case -2:
			cout << "右括号多于左括号 或 左右括号乱序" << endl;break;
		case -3:
			cout << "左括号对于右括号" << endl; break;
		default:
			cout << "一切正常" << endl; break;
		}
	}
	return 0;
}