#include <iostream>
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
	~LinkList();
	ListNode * LL_index(int i);
	int LL_get(int i);
	int LL_insert(int i, int item);
	int LL_del(int i);
	void LL_display();
};

LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}

LinkList::~LinkList()
{

	ListNode *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	len = 0;
	head = NULL;
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
	int n, index = 1;
	LinkList list;

	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		list.LL_insert(index, data);
		index++;
	}
	list.LL_display();
	int i, new_data;
	cin >> i >> new_data;
	if (list.LL_insert(i, new_data))
	{
		list.LL_display();
	}
	else{
		cout << "error" << endl;
	}
	cin >> i >> new_data;
	if (list.LL_insert(i, new_data))
	{
		list.LL_display();

	}
	else{
		cout << "error" << endl;
	}
	cin >> i;
	if (list.LL_del(i))
	{
		list.LL_display();
	}
	else{
		cout << "error" << endl;
	}
	cin >> i;
	if (list.LL_del(i))
	{
		list.LL_display();
	}
	else{
		cout << "error" << endl;
	}
	cin >> i;
	if (list.LL_get(i))
	{
		cout << list.LL_get(i) << endl;
	}
	else{
		cout << "error" << endl;
	}
	cin >> i;
	if (list.LL_get(i))
	{
		cout << list.LL_get(i) << endl;
	}
	else{
		cout << "error" << endl;
	}
	system("pause");
	return 0;

}
