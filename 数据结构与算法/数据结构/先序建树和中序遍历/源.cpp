#include<iostream>
using namespace std;
class Node
{
public:
	char data;
	Node* lc;
	Node* rc;
};
class binTree
{
public:
	Node* root;
	int size;
	int hasCreate;
	void createTree(Node*& x)
	{
		char c;
		cin >> c;
		if (c == '0')
		{
			x = NULL;
			return;
		}
		else
		{
			x = new Node();
			x->data = c;
			createTree(x->lc);
			createTree(x->rc);
		}
	}
public:
	binTree()
	{
		root = NULL;
		hasCreate = 0;
	}
	void init(int size)
	{
		//char c;
		this->size = size;
		createTree(root);
	}
	void trM(Node* x)
	{
		if (!x) return;//µÝ¹é»ù;
		trM(x->lc);
		if (x->data != '0')
			cout << x->data << ' ';
		trM(x->rc);
	}
};
int main()
{ 
	binTree T;
	int size;
	cin >> size;
	T.init(size);
	T.trM(T.root);
	cout << endl;
	//system("pause");
}