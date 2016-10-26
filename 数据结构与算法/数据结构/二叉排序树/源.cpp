#include <iostream>
#include <cmath>
using namespace std;
class Node
{
public:
	int data;
	Node* lc;
	Node* rc;
	Node(int e = 0)
	{
		data = e;
	}
};
class BST
{
private:
	Node* root;
	int size;
	int time;
	int where;//命中后在该层的位置;
	int index;//在数组中的位置;
public:
	BST(int size=0)
	{
		root = NULL;
		this->size = size;
	}
	void init()
	{
		int i,e;
		for (i = 0; i < size;i++)
		{
			cin >> e;
			insert(e);
		}
	}
	Node*& searchIn(Node*& v,const int& e)
	{
		if (!v || (e == v->data)) return v;//命中或找不到 递归基;
		//return searchIn(((e < v->data) ? v->lc : v->rc), e);//递归深入;
		time++;
		if (e>v->data)//右孩子;
		{
			index = 2 * index + 1;
			where=index-pow(2, time - 1) + 1;
			return searchIn(v->rc, e);
		}
		else
		{
			index = 2 * index;
			where=index-pow(2, time - 1) + 1;
			return searchIn(v->lc, e);
		}
	}
	Node*& search(const int& e)
	{
		time = 1;
		index = 0;
		return searchIn(root, e);
	}
	void insert(const int& e)
	{
		Node*& x = search(e);
		if (x) return;
		x = new Node(e);
	}
	void display(const int& e)
	{
		if (search(e))
		{
			cout << 1 << ' ' << index+1 << ' ' << time << endl;
		}
		else
		{
			cout << 0 << ' ' << index+1 << ' ' << time << endl;
		}
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size;
		cin >> size;
		BST b(size);
		b.init();
		cin >> size;
		b.display(size);
	}
	return 0;
}