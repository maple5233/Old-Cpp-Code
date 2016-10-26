#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
	���ַ���˼·���Ƚ���׺���ʽһ����ת��Ϊ��׺���ʽ���ٽ��к�׺���ʽ������
*/

/******************���ȼ��ж�*******************************/
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

/****************��׺���ʽת���ɺ�׺���ʽ********************/
void Change(string s1, string& s2)
{
	stack<char> T;
	int i = 0;
	char ch;
	T.push( '@');
	ch = s1[i];
	while (ch != '\0')
	{
		if (ch == ' ')//�����ո�
			ch = s1[++i];
		else if (ch == '(')//������ֱ�ӽ�ջ
		{
			T.push(ch);
			ch = s1[++i];
		}
		else if (ch == ')')//���������� �����ΰ�ջ�еĵ�����������׺���ʽ�У�ֱ������'('����ջ��ɾ��'(' 
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
		/*�������������������� �������ȼ����ڳ�'('�����ջ�������ʱ��ֱ����ջ��
		�����ջ����ʼ�����ε����ȵ�ǰ�������������ȼ��ߺ����ȼ���ȵ��������ֱ��һ���������ȼ��͵Ļ���������һ��������Ϊֹ��*/
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
			while ((ch >= '0' && ch <= '9') || ch == '.')//����ֱ�Ӽ����׺���ʽ
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

/******************��Ԫ������***************************/
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

/****************��׺���ʽ��ֵ******************************/
int CalculateAll (string s)
{
	stack<char> T;
	int result=0;
	for (string::iterator it = s.begin(); it != s.end(); ++it)//ʹ��string�ĵ�����
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
	cout << "��������ʽ" << endl;
	cin >> infix;
	cout << "ת��Ϊ��׺���ʽ�Ľ��Ϊ" << endl;
	Change(infix, suffix);
	cout << suffix << endl;
	cout << "������Ϊ" << endl;
	cout << CalculateAll(suffix) << endl;
	system("pause");
	return 0;
}