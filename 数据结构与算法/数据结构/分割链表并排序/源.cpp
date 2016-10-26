#include<iostream>
using namespace std;
#define ok 1
#define error 0
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		next = NULL;
	}
};
class LinkList
{
public:
	int len;
	Node* head;
	LinkList()
	{
		head = new Node();
		len = 0;
	}
	/*~LinkList()
	{
		Node *p, *q;
		p = head;
		while (!p == NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
		len = 0;
		head = NULL;
	}*/
	Node* GetIndex(int i)
	{
		if (i == 0)
		{
			return head;
		}
		else
		{
			Node *p = head->next;
			int j = 1;
			while (p&&j<i)
			{
				p = p->next;
				j++;
			}
			if (!p)
			{
				return error;
			}
			return p;
		}
	}
	int GetData(int i)
	{
		if (GetIndex(i))
			return GetIndex(i)->data;
		else
			return error;
	}
	void Display()
	{
		Node* p = head->next;
		Node* q = this->GetIndex(len);
		while (p!=q)
		{
			cout <<(char)(p->data) << ' ';
			p = p->next;
		}
		cout << (char)(p->data)<<endl;
	}
	int Insert(int i, int data)
	{
		if (GetIndex(i - 1))
		{
			Node *p = new Node();
			p->data = data;
			Node *q = GetIndex(i - 1);
			p->next = q->next;
			q->next = p;
			len++;
			return ok;
		}
		else
		{
			return error;
		}
	}
	int Del(int i)
	{
		if (GetIndex(i - 1))
		{
			Node *p = GetIndex(i - 1);
			p->next = p->next->next;
			len--;
			return ok;
		}
		else
		{
			return error;
		}
	}
	void swap1(Node * p, Node * q)//相邻结点交换 冒泡排序的交换只发生在相邻两个元素之间 其实用不到swap2
	{
		Node * i = head;
		Node * tmp = NULL;
		while (i)
		{
			if (i->next == p)
			{
				break;
			}
			else
			{
				i = i->next;
				continue;
			}
		}
		i->next = q;
		tmp = q->next;
		q->next = p;
		p->next = tmp;
	}
	void swap2(Node * p, Node * q)//不相邻结点交换 对于冒泡排序并没有什么卵用的函数
	{
		Node * i = head;
		Node * j = head;
		Node * tmp1 = NULL, *tmp2 = NULL;
		while (i)
		{
			if (i->next == p)
			{
				break;
			}
			else
			{
				i = i->next;
				continue;
			}
		}
		while (j)
		{
			if (j->next == q)
			{
				break;
			}
			else
			{
				j = j->next;
				continue;
			}
		}
		tmp1 = p->next;
		tmp2 = q->next;
		i->next = q;
		q->next = tmp1;
		j->next = p;
		p->next = tmp2;
	}
	void sort1()//升序冒泡排序 利用swap1函数
	{
		int i, j;
		for (j = 1; j <= len; j++)
		{
			for (i = 1; i <= len - j; i++)
			{
				int a = (int)(GetIndex(i)->data);
				int b = (int)(GetIndex(i + 1)->data);
				if (a>b)				
				{
					swap1(GetIndex(i), GetIndex(i + 1));
				}
			}
		}
	}
	void sort2()//升序冒泡排序 直接交换数据域
	{

		int i, j,tmp;
		for (j = 1; j <= len; j++)
		{
			for (i = 1; i <= len - j; i++)
			{
				int a = (GetIndex(i)->data);
				int b = (GetIndex(i + 1)->data);
				if (a>b)
				{
					tmp = (GetIndex(i)->data);
					(GetIndex(i)->data) = (GetIndex(i + 1)->data);
					(GetIndex(i + 1)->data) = tmp;
				}
			}
		}
	}
};
int main()
{
	LinkList bigChar, smallChar, num;
	LinkList total;//总的
	int totalLength, i;
	char tmpChar;
	int bigCount = 1, smallCount = 1, numCount = 1;
	cin >> totalLength;
	for (i = 1; i <= totalLength; i++)
	{
		cin >> tmpChar;
		total.Insert(i, (int)tmpChar);
	}
	total.Display();
	for (i = 1; i <= totalLength; i++)
	{
		Node* p;
		p = total.GetIndex(i);
		if ((p->data <= 90) && (p->data >= 65))//大写字母
		{
			bigChar.Insert(bigCount, p->data);
			bigCount++;
		}
		else if ((p->data <= 122) && (p->data >= 97))//小写字母
		{
			smallChar.Insert(smallCount, p->data);
			smallCount++;
		}
		else if ((p->data <= 57) && (p->data >= 48))//数字
		{
			num.Insert(numCount, p->data);
			numCount++;
		}
	}
	bigChar.Display();
	smallChar.Display();
	num.Display();
	
	/*
	bigChar.sort1();
	smallChar.sort1();
	num.sort1();
	*/

	bigChar.sort2();
	smallChar.sort2();
	num.sort2();

	bigChar.Display();
	smallChar.Display();
	num.Display();
	system("pause");
	return 0;
}