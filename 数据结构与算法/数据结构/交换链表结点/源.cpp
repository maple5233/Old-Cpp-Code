#include <iostream>
#include <cmath>
using namespace std;
#define ok 1
#define error 0

class ListNode
{
public:
	int data;
	ListNode * next;
	ListNode()
	{
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode * head;
	int len;
	LinkList();
	ListNode * LL_index(int i);
	int LL_get(int i);
	int LL_insert(int i, int item);
	int LL_del(int i);
	void LL_display();
	void swap1(ListNode * p, ListNode * q);
	void swap2(ListNode * p, ListNode * q);
};
void LinkList::swap1(ListNode * p, ListNode * q)//相邻结点交换
{
	ListNode * i = head;
	ListNode * tmp = NULL;
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
void LinkList::swap2(ListNode * p, ListNode * q)//不相邻结点交换
{
	ListNode * i = head;
	ListNode * j = head;
	ListNode * tmp1 = NULL, *tmp2 = NULL;
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

LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

ListNode* LinkList::LL_index(int i)
{
	ListNode *p = head;
	p = head->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return error;
	return p;
}

int LinkList::LL_get(int i)
{
	ListNode *p = head;
	p = p->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return error;
	return p->data;
}

int LinkList::LL_del(int i)
{
	ListNode *p = head;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;//修改p本身是移动结点索引 不改变链表的结构
		++j;
	}
	if (!p || j>i)
		return error;
	p->next = p->next->next;//p指向被删除元素的前一个，修改p的next值是删除结点 next值是存储链表信息的关键
	return ok;
}

int LinkList::LL_insert(int i, int item)
{
	ListNode *p = head;
	int j = 0;
	while (p&&j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
	{
		return error;
	}
	ListNode* s = new ListNode();
	s->data = item;
	s->next = p->next;
	p->next = s;
	return ok;
}
int main()
{
	int n;
	int index = 1;
	LinkList a;
	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		a.LL_insert(index, data);
		index++;
	}
	a.LL_display();//输入链表元素

	int c, d;
	ListNode *p, *q;


	cin >> c >> d;//按位置交换结点
	if (abs(c - d) >1)//不相邻
	{
		if (a.LL_index(c) != NULL  &&  a.LL_index(d) != NULL)
		{
			p = a.LL_index(c);
			q = a.LL_index(d);
			a.swap2(p, q);
			a.LL_display();
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else//相邻
	{
		if (a.LL_index(c) != NULL  &&  a.LL_index(d) != NULL)
		{
			p = a.LL_index(c);
			q = a.LL_index(d);
			a.swap1(p, q);
			a.LL_display();
		}
		else
		{
			cout << "error" << endl;
		}
	}
	system("pause");
	return 0;
}
