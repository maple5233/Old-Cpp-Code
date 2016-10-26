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
		char r = pre[0];//��;
		int index = ins.find(r);//�ҵ��������������е�λ�ã���string�кܷ���;

		string lc_ins = ins.substr(0, index);//���ӵ���������;  
		string rc_ins = ins.substr(index + 1);//�Һ��ӵ���������;
		//pre = pre.substr(1);//ȥ��ͷ�Ϳ��Գ�;

		int lc_length = lc_ins.length();//���ӵĳ���;  
		int rc_length = rc_ins.length();//�Һ��ӵĳ���;

		string lc_pre = pre.substr(1, lc_length);//���ӵ�ǰ������;
		//string lc_pre = pre.substr(0, lc_length);//���ӵ�ǰ������;
		string rc_pre = pre.substr(1+lc_length);//�Һ��ӵ�ǰ������;
		//string rc_pre = pre.substr(lc_length);//�Һ��ӵ�ǰ������;


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
	string pre="",ins="";//�����������������д���Ϊstring�����Է�����Һͷָ�;
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