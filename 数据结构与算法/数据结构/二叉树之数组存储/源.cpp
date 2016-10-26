#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define binNodePosi binNode*   //结点位置
#define IsRoot(x) (!((x).parent))//是树根
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//是左子树
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//是右子树
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) //来自父亲的指针 
/*	此算法给原本不存在的节点留出了空位，并将数据域赋值为0 输出时 检查数据域 为0的时候跳过
输入1 2 3 4 0 5 6 7 8 0 0 9 10
输出1 2 4 7 8 3 5 9 10 6
*/
class binNode
{
public:
	binNodePosi parent;
	binNodePosi lChild;
	binNodePosi rChild;
	int data;
	binNode(int dat = 0, binNodePosi p = NULL, binNodePosi l = NULL, binNodePosi r = NULL)
		:data(dat), parent(p), lChild(l), rChild(r){}
};
class binTree
{
private:
	void createTreeInTwo(queue<int>& Q, binNodePosi& x, queue<binNodePosi>& S)
	{
		int tmp;
		tmp = Q.front();
		Q.pop();
		x->data = tmp;
		x->lChild = new binNode(0, x);
		x->rChild = new binNode(0, x);
		S.push(x->lChild);
		S.push(x->rChild);
	}
	void visitAlongLeftBranch(binNodePosi x, stack<binNodePosi>& S)
	{//迭代先序遍历依托函数
		while (x)
		{
			if (x->data != 0)
			{
				cout << x->data << ' ';
			}
			if (x->rChild)
			{
				S.push(x->rChild);
			}
			x = x->lChild;
		}
	}
protected:
	int _size;
	binNodePosi _root;
public:
	binTree() :_size(0), _root(NULL){}
	/*接受数组并按层次初始化树*/
	void createTreeInOne(int* num, int numsize)
	{
		int i;
		queue<int> Q;
		queue<binNodePosi> S;//排队接受创造
		_size += numsize;

		for (i = 0; i < numsize; i++)
		{
			Q.push(num[i]);
		}//预处理，化数组为队列

		_root = new binNode(0, _root);
		binNodePosi x = _root;
		createTreeInTwo(Q, x, S);//对根节点处理 
		while (!Q.empty())
		{
			x = S.front();
			S.pop();
			createTreeInTwo(Q, x, S);
		}
		while (!S.empty())//清除Q耗尽之后的剩余节点
		{
			x = S.front();
			S.pop();
			FromParentTo(*x) = NULL;//赶出家门 父不认子
			delete x;
		}
	}
	/*先序遍历输出树节点*/
	void visitBinTree()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;
		while (true)
		{
			visitAlongLeftBranch(x, S);//对于每一个树根 访问左侧链 将右子树们缓冲入栈
			if (S.empty()) break;//栈空表示遍历完毕
			x = S.top();//取出一个右孩子 也就是下一个需要遍历的树的树根 迭代对其做同样的遍历操作
			S.pop();
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
		int i;
		int size;
		cin >> size;
		int* bin = new int[size];
		for (i = 0; i < size; i++)
		{
			cin >> bin[i];
		}
		binTree tree;
		tree.createTreeInOne(bin, size);
		tree.visitBinTree();
	}
	return 0;
}