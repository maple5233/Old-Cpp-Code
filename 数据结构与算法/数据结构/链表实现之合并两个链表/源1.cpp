/*#include <iostream>
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
	//~LinkList();
	ListNode * LL_index(int i);
	int LL_get(int i);
	int LL_insert(int i, int item);
	int LL_del(int i);
	void LL_display();
	friend void hb(LinkList a, LinkList b, LinkList &c);
};

void hb(LinkList a, LinkList b, LinkList &c)
{
	ListNode* pa = a.head->next;
	ListNode* pb = b.head->next;
	c.head = a.head;
	ListNode* pc = c.head;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
}

LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}

/*LinkList::~LinkList()
{

ListNode *p,*q;
p=head;
while(p!=NULL)
{
q=p;
p=p->next;
delete q;
}
len=0;
head=NULL;
}*/
/*
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
	LinkList a, b, c;
	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		a.LL_insert(index, data);
		index++;
	}
	index = 1;
	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		b.LL_insert(index, data);
		index++;
	}
	hb(a, b, c);
	c.LL_display();
	system("pause");
	return 0;
}
*/