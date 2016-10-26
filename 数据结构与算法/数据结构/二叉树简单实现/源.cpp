#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define datatype int //数据类型
#define binNodePosi binNode*   //结点位置
#define IsRoot(x) (!((x).parent))//是树根
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//是左子树
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//是右子树
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) //来自父亲的指针

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
	void createTreePre(binNodePosi& x,binNodePosi xp)//x从_root开始 xp为父节点
	{
		datatype in;
		cin >> in;
		if (in == '0')
		{
			x = NULL;
		}
		else
		{
			x = new binNode(in, xp);
			x->data = in;
			createTreePre(x->lChild,x);
			createTreePre(x->rChild,x);
		}
	}
	void visitAlongLeftBranch(binNodePosi x,stack<binNodePosi>& S)
	{//先序遍历输出依托函数
		while (x)
		{
			cout << x->data;//访问当前节点
			if (x->rChild)
			{
				S.push(x->rChild);//右孩子进栈
			}
			x = x->lChild;//沿着左侧链进行 直到没有左子树
		}
	}
	void visitAlongLeftBranchTwo(binNodePosi x, stack<binNodePosi>& S)
	{//先序遍历输出依托函数 这个版本跳过0
		while (x)
		{
			if (x->data)
			{
				cout << x->data<<' ';//访问当前节点
			}
			if (x->rChild)
			{
				S.push(x->rChild);//右孩子进栈
			}
			x = x->lChild;//沿着左侧链进行 直到没有左子树
		}
	}
	void goAlongLeftBranch(binNodePosi x, stack<binNodePosi>& S)
	{//中序遍历依托的函数 将左侧链入栈
		while (x)
		{
			S.push(x);
			x = x->lChild;//依次将左孩子入栈
		}
	}
	void gotoHLVFL(stack<binNodePosi>& S)//在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
	{ //后序遍历依托函数 沿途所遇节点依次入栈
		while (binNodePosi x = S.top()) //自顶而下，反复检查当前节点（即栈顶）
		{
			if (x->lChild || x->rChild)
			{ //尽可能向左
				if (x->rChild)
				{
					S.push(x->rChild); //若有右孩子，优先入栈
				}
				S.push(x->lChild); //然后才转至左孩子
			}
			else
			{//实不得已
				S.push(x->rChild); //才向右
			}
			if (!S.top())
				break;
		}
		S.pop(); //返回之前，弹出栈顶的空节点
	}
	int countLeaves(binNodePosi x)//迭代求叶子数量内部函数
	{
		if (x == NULL)
			return 0;
		else if (x->lChild == NULL&&x->rChild == NULL)
			return 1;
		else
			return countLeaves(x->lChild) + countLeaves(x->rChild);
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
	void createTreeInTwo(queue<int>& Q, binNodePosi& x, queue<binNodePosi>& S)
	{//接受数组参数层次遍历迭代初始化树的依托函数
		int tmp;
		tmp = Q.front();
		Q.pop();
		x->data = tmp;
		x->lChild = new binNode(0, x);
		x->rChild = new binNode(0, x);
		S.push(x->lChild);
		S.push(x->rChild);
	}
protected:
	int _size;
	binNodePosi _root;
public:
	binTree() :_size(0), _root(NULL){}
	/*先序遍历递归初始化树*/
	void createTreePre()
	{
		createTreePre(_root,NULL);
	}
	/*接受数组参数层次遍历迭代初始化树*/
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
	/*层次迭代遍历输出*/
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
	/*先序迭代遍历输出*/
	void travPre()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//根节点
		while (true)
		{//以子树为单位 逐批访问节点
			visitAlongLeftBranch(x, S);//对于每一个树根 访问左侧链 将右子树们缓冲入栈
			if (S.empty()) break;//栈空表示遍历完毕
			x = S.top();//取出一个右孩子 也就是下一个需要遍历的树的树根 迭代对其做同样的遍历操作
			S.pop();
		}
		cout << endl;
	}
	/*先序迭代遍历输出（跳过0）*/
	void travPreTwo()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//根节点
		while (true)
		{//以子树为单位 逐批访问节点
			visitAlongLeftBranchTwo(x, S);//对于每一个树根 访问左侧链 将右子树们缓冲入栈
			if (S.empty()) break;//栈空表示遍历完毕
			x = S.top();//取出一个右孩子 也就是下一个需要遍历的树的树根 迭代对其做同样的遍历操作
			S.pop();
		}
		cout << endl;
	}
	/*中序迭代遍历输出*/
	void travIn()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//根节点开始
		while (true)
		{
			goAlongLeftBranch(x, S);
			if (S.empty()) break;//栈空表示遍历完成
			x = S.top();
			S.pop();
			cout << x->data;//立即访问之
			x = x->rChild;//转向右子树（可能为空，留意处理手法）
		}
		cout << endl;
	}
	/*后序迭代遍历输出*/
	void travPost()
	{
		binNodePosi x = _root;//根节点
		stack<binNodePosi> S; //辅助栈

		if (x)
			S.push(x); //根节点入栈

		while (!S.empty())
		{
			if (S.top() != x->parent) //若栈顶非当前节点之父（则必为其右兄），此时需
			{
				gotoHLVFL(S); //在以其右兄为根之子树中，找到HLVFL（相当于递归深入其中） 
			}	//如果栈顶是当前节点的父亲节点 则说明左右孩子已经访问完毕 可以访问父亲了
			x = S.top();
			S.pop();
			cout<<x->data; //弹出栈顶（即前一节点之后继），并访问之
		}
		cout << endl;
	}
	/*求叶子数量*/
	int countLeaves()
	{
		return countLeaves(_root);
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
		tree.travPreTwo();
	}
	return 0;
}