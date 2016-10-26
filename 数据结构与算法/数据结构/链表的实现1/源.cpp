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
private:
	int len;
	Node* head;
public:
	LinkList()
	{
		head = new Node();
		len = 0;
	}
	~LinkList()
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
};
int main()
{
	LinkList a;
	int n, index = 1, data;
	cin >> n;
	while (n--)
	{
		cin >> data;
		a.Insert(index, data);
		index++;
	}
	a.Display();
	
	cin >> n >> data;
	if (a.Insert(n, data))
	{
		a.Display();
	}
	else cout << "error" << endl;
	cin >> n >> data;
	if (a.Insert(n, data))
	{
		a.Display();
	}
	else cout << "error" << endl;
	
	cin >> n;
	if (a.Del(n))
	{
		a.Display();
	}
	else cout << "error" << endl;
	cin >> n;
	if (a.Del(n))
	{
		a.Display();
	}
	else cout << "error" << endl;
	
	cin >> n;
	if (a.GetData(n))
	{
		cout << a.GetData(n) << endl;
	}
	else cout << "error" << endl;
	cin >> n;
	if (a.GetData(n))
	{
		cout << a.GetData(n) << endl;
	}
	else cout << "error" << endl;
	system("pause");
	return 0;
}