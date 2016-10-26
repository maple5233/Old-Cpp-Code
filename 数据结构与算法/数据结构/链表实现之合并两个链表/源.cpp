#include <iostream>
using namespace std;
#define ok 1
#define error 0

class Node
{
public:
	int data;
	Node * next;
	Node()
	{
		next = NULL;
	}
};

class LinkList
{
private:
	int len;
	Node* head;
public:
	LinkList()
	{
		head = new Node();
		len = 0;
	}
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
			while (p&&j < i)
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
		Node *p = head->next;
		while (p)
		{
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
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
	friend void hebing(LinkList a, LinkList b, LinkList &c);
};


void hebing(LinkList a, LinkList b, LinkList &c)
{
	Node* pa = a.head->next;
	Node* pb = b.head->next;
	c.head = a.head;
	Node* pc = c.head;
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
		a.Insert(index, data);
		index++;
	}
	index = 1;
	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		b.Insert(index, data);
		index++;
	}
	hebing(a, b, c);
	c.Display();
	system("pause");
	return 0;
}
