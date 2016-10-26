#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;
/*
���ַ���˼·��ʹ������ջ��һ���洢��������������������һ���洢�������һ��ת��Ϊ��׺���ʽһ�߼����׺���ʽ
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

/******************��Ԫ������***************************/
double Calculater(double a, double b, char c)//a,b�ǲ�������cΪ������
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

/******************�ж��ǲ��������***************************/
bool isOper(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')
	{
		return true;
	}
	return false;
}

/********************��׺���ʽ���㹤��************************/
double CalculateAll(string s)
{
	stack<char> oper;//�洢�����
	stack<double> num;//�洢��������������
	oper.push('#');

	char tmp[100] = {0};//��ʱ�洢������
	int i = 0;
	double tmpnum; 

	double result = 0;
	double a = 0, b = 0;
	char c, x;

	string::iterator it = s.begin();//ʹ��string�ĵ�����
	while(1)
	{
		c = *(it);
		if (c != '#' || oper.top() != '#')//�ж��Ƿ�������
		{
			if (c == ' ')//�����ո�
			{
				it++;
				continue;
			}
			else if (!isOper(c))//���ֽ�ջ
			{
				while (!isOper(c))
				{
					tmp[i] = c;
					tmp[i + 1] = 0;
					i++;
					it++;
					c = *(it);
				}
				tmpnum = (double)(atof(tmp));//�ַ���ת��Ϊ����
				tmp[0] = 0;
				i = 0;//�����ʱ�����ַ������鲢����������
				num.push(tmpnum);
				continue;
			}
			else
			{
				if (oper.top() == '('&&c == ')')//�����ţ�ɨ����һ��
				{//��ջ����
					oper.pop();
					it++;
					continue;
				}
				else if (c == '(')//�����Ź̶���ջ
				{
					oper.push(c);//��ջ����
					it++;
					continue;
				}
				else if (Precedence(oper.top()) < Precedence(c))//ջ��Ԫ�����ȼ��ͣ�ֱ�ӽ�ջ��ɨ����һ��
				{
					oper.push(c);//��ջ����
					it++;
					continue;
				}
				else//ջ��Ԫ�����ȼ��� ��������ͬ���ķ������� ���㣬��ɨ����һ�� �´μ����Ƚ�ջ��Ԫ�غ�c
				{//�������
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