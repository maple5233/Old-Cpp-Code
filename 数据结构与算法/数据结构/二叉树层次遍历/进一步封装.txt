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
protected:
	int _size;
	binNodePosi _root;
public:
	binTree() :_size(0), _root(NULL){}
	/*先序遍历初始化树*/
	void createTreePre()
	{
		createTreePre(_root);
	}
	/*层次遍历输出*/
	void travLevel()
	{
		queue<binNodePosi> Q;
		Q.push(_root);//根节点入队
		while (!Q.empty())
		{
			binNodePosi x = Q.front();
			Q.pop();
			cout << x->data;
			if (x->lChild)
			{
				Q.push(x->lChild);
			}
			if (x->rChild)
			{
				Q.push(x->rChild);
			}
		}
		cout << endl;
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
		tree.travLevel();
	}
	return 0;
}