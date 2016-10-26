#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data = 0)
	{
		this->data = data;
		next = NULL;
	}
};
class HashSearch
{
public:
	Node* hashlink[11];
	int size;
	int i, j;
	bool find;
	int where;
public:
	HashSearch(int size = 0)
	{
		this->size = size;
		i = j = 0;
		for (i = 0; i < 11;i++)
		{
			hashlink[i] = new Node();
		}
	}
	void init()
	{
		int tmp;
		for (i = 0; i < size; i++)
		{
			cin >> tmp;
			insertHash(tmp);
		}
	}
	void insertHash(int e)
	{
		int index = e % 11;
		Node* n = new Node(e);
		n->next = hashlink[index]->next;
		hashlink[index]->next = n;
	}
	void HashSearchIn(int e)
	{
		where = 1;
		int index = e % 11;
		Node* p = hashlink[index]->next;
		while (p)
		{
			if (p->data == e)
			{
				cout << e % 11 << ' ' << where<<endl;
				return;
			}
			else
			{
				p = p->next;
				where++;
			}
		}
		cout << "error" << endl;
		insertHash(e);
	}
};
int main()
{
	int size,time,e;
	cin >> size;
	HashSearch h(size);
	h.init();
	cin >> time;
	while (time--)
	{
		cin >> e;
		h.HashSearchIn(e);
	}
	system("pause");
	return 0;
}