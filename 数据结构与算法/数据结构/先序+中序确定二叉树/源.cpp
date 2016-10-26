#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
	char data; 
	Node* lc;
	Node* rc;
	Node()
	{
		lc = rc = NULL;
	}
};
class binTree
{
public:
	Node* root;
	int size;
public:
	binTree()
	{
		root = NULL;
		size = 0;
	}
	bool createByPreAndIns(Node*& _root, string pre, string ins)
	{
		if (pre.length() == 0 || ins.length() == 0||pre.length()!=ins.length())
		{
			return false;
		}
		char r = pre[0];//根;
		int index = ins.find(r);//找到根在中序序列中的位置，在string中很方便;

		string lc_ins = ins.substr(0, index);//左孩子的中序序列;  
		string rc_ins = ins.substr(index + 1);//右孩子的中序序列;
		//pre = pre.substr(1);//去掉头就可以吃;

		int lc_length = lc_ins.length();//左孩子的长度;  
		int rc_length = rc_ins.length();//右孩子的长度;

		string lc_pre = pre.substr(1, lc_length);//左孩子的前序序列;
		//string lc_pre = pre.substr(0, lc_length);//左孩子的前序序列;
		string rc_pre = pre.substr(1+lc_length);//右孩子的前序序列;
		//string rc_pre = pre.substr(lc_length);//右孩子的前序序列;


		_root = new Node();
		_root->data = r;

		createByPreAndIns(_root->lc, lc_pre, lc_ins);
		createByPreAndIns(_root->rc, rc_pre, rc_ins);
	}
	void tra_pos(Node* x)
	{
		if (!x) return;
		tra_pos(x->lc);
		tra_pos(x->rc);
		if (x->data!='0')
		{
			cout << x->data << ' ';
		}
		
	}
};
int main()
{
	string pre="",ins="";//把中序和先序遍历序列处理为string类型以方便查找和分割;
	int size,i;
	char c;
	cin >> size;
	for (i = 0; i < size;i++)
	{
		cin >> c;
		pre += c;
	}
	for (i = 0; i < size; i++)
	{
		cin >> c;
		ins += c;
	}
	binTree b;
	b.createByPreAndIns(b.root, pre, ins);
	b.tra_pos(b.root);
	cout << endl;
	system("PAUSE");
	return 0;
}