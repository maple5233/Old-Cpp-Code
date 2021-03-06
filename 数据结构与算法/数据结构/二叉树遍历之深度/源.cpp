#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define datatype char 
#define binNodePosi binNode*   //结点位置

class binNode
{
public:
	binNodePosi parent;
	binNodePosi lChild;
	binNodePosi rChild;
	datatype data;
	binNode(datatype dat = 0, binNodePosi p = NULL, binNodePosi l = NULL, binNodePosi r = NULL)
		:data(dat), parent(p), lChild(l), rChild(r){}
};
class binTree
{
private:
	void createTreePre(binNodePosi& x)//x从_root开始
	{
		datatype in;
		cin >> in;
		if (in == '0')
		{
			x = NULL;
		}
		else
		{
			x = new binNode(in);
			x->data = in;
			createTreePre(x->lChild);
			createTreePre(x->rChild);
		}
	}
	int countMaxPath(binNodePosi x)
	{
		int LD, RD;
		if (x == NULL)
			return 0;
		else
		{
			LD = countMaxPath(x->lChild);
			RD = countMaxPath(x->rChild);
			return (LD>RD ? LD : RD) + 1;
		}
	}
protected:
	int _size;
	binNodePosi _root;
public:
	/*构造函数*/
	binTree() :_size(0), _root(NULL){}
	/*先序遍历递归初始化树*/
	void createTreePre()
	{
		createTreePre(_root);
	}
	/*求最大深度*/
	int countMaxPath()//从root开始
	{
		return countMaxPath(_root);
	}

};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		binTree tree;
		tree.createTreePre();
		cout << tree.countMaxPath() << endl;
	}
	return 0;
}