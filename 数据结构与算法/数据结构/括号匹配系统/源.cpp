#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isBracket(char c)//�ж��ǲ�������;
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
	stack<char> tmp;//ʹ��STL����ַ�ջ;
	char ch;
	string::iterator it ;//ʹ��s�ĵ�����;

	for (it = s.begin(); it != s.end(); it++)
	{
		c = *(it);//������;
		if (!isBracket(c))
		{
			continue;
		}
		else if (isLeft(c))//c��������;
		{
			tmp.push(c);
			continue;
		}
		else//c��������;
		{
			if (tmp.empty())
				return -2;//�����Ŷ��������Ż���������;
			else
			{
				ch = tmp.top();
				tmp.pop();
				if (!isMatch(ch, c))
				{
					return -1;//��Բ���ȷ;
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
		return 0;//һ������;
	}
	else
	{
		return -3;//�����Ŷ���������;
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
			cout << "��Բ���ȷ" << endl; break;
		case -2:
			cout << "�����Ŷ��������� �� ������������" << endl;break;
		case -3:
			cout << "�����Ŷ���������" << endl; break;
		default:
			cout << "һ������" << endl; break;
		}
	}
	return 0;
}