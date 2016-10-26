#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define binNodePosi(T) binNode<T>*   //结点位置
#define stature(p) ((p)?(p)->height:-1)   //统一空树和非空树的高度

#define IsRoot(x) (!((x).parent))//是树根
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//是左子树
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//是右子树
#define HasParent(x) (!IsRoot(x))//有父亲
#define HasLChild(x) ((x).lChild)//有左子树
#define HasRChild(x) ((x).rChild)//有右子树
#define HasChild(x) (HasLChild(x)||HasRChild(x)) //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x)&&HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))//是叶子

#define sibling(p) (IsLChild(*(p))?(p)->parent->rChild:(p)->parent->lChild) /*兄弟*/
#define uncle(x) (IsLChild(*((x)->parent))?(x)->parent->parent->rChild:(x)->parent->parent->lChild) /*叔叔*/
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) /*来自父亲的指针*/ 

template <typename T> class Cleaner {
	static void clean(T x) { //相当于递归基
	}
};
template <typename T> class Cleaner<T*> {
	static void clean(T* x) {
		if (x) { delete x; } //如果其中包含指针，递归释放
	}
};
template <typename T> void release(T x) 
{ Cleaner<T>::clean(x); }

template <typename T> class binNode //树结点的模板类 <typename T>等同于<class T>
{
public:
	binNodePosi(T) parent, lChild, rChild;
	T data;//数据域
	int height;//该节点高度

	binNode()
	{
		this->lChild = NULL;
		this->rChild = NULL;
		this->parent = NULL;
		this->height = 0;
	}
	binNode(T e, binNodePosi(T) pos = NULL, binNodePosi(T) lc = NULL, binNodePosi(T) rc = NULL, int h = 0) 
		:data(e), parent(pos), lChild(lc), rChild(rc), height(h){}

	/*const&表示常引用 这时候无法通过引用修改原变量的值 不管加不加const 引用本身是必须被初始化而且初始化后是无法被改变的*/
	binNodePosi(T) insertAsLC(T const& e)//作为左子树插入
	{
		return lChild = new binNode(e, this);
	}
	binNodePosi(T) insertAsRC(T const& e)//作为右子树插入
	{
		return rChild = new binNode(e, this);
	}

	int size()//返回子树规模 也就是后代总数
	{
		int s = 1;
		if (lChild) s += lChild->size();//递归计入左子树后代
		if (rChild) s += rChild->size();//递归计入右子树后代
		return s;
	}
	binNodePosi(T) succ()//中序意义下的直接后继
	{
		binNodePosi(T) s = this;//记录后继的临时变量
		if (rChild) 
		{ //若有右孩子，则直接后继必在右子树中，具体地就是
			s = rChild; //右子树中
			while (s->lChild) 
			{
				s = s->lc; //最靠左（最小）的节点
			}
		}
		else 
		{ //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
			while (s->parent != NULL&&s==s->parent->rChild)//如果s是右孩子
			{
				s = s->parent; //逆向地沿右向分支，不断朝左上方移动
			}
			s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
		}
		return s;
	}

	/*遍历接口*/
	template <typename VST> void travLevel(VST& visit)//子树层次遍历
	{
		queue<binNodePosi(T)> Q;
		Q.push(this);//根节点入队
		while (!Q.empty())
		{
			binNodePosi(T) x = Q.front();
			Q.pop();
			visit(x->data);
			if (x->lChild)
			{
				Q.push(x->lChild);
			}
			if (x->rChild)
			{
				Q.push(x->rChild);
			}
		}
	}

	template <typename VST> void visitAlongLeftBranch(binNodePosi(T) x, VST& visit, stack<binNodePosi(T)>& S)
	{//先序遍历依托的函数 沿着左侧链访问节点
		while (x)
		{
			visit(x->data);//访问当前节点
			if (x->rChild)
			{
				S.push(x->rChild);//右孩子进栈
			}
			x = x->lChild;//沿着左侧链进行 直到没有左子树
		}
	}
	template <typename VST> void travPre(VST& visit)//子树先序遍历
	{
		stack<binNodePosi(T)> S;
		binNodePosi(T) x = this;//根节点
		while (true)
		{//以子树为单位 逐批访问节点
			visitAlongLeftBranch(x, visit, S);//对于每一个树根 访问左侧链 将右子树们缓冲入栈
			if (S.empty()) break;//栈空表示遍历完毕
			x = S.top();//取出一个右孩子 也就是下一个需要遍历的树的树根 迭代对其做同样的遍历操作
			S.pop();
		}
	}

	template <typename VST> void goAlongLeftBranch(binNodePosi(T) x,stack<binNodePosi(T)>& S)
	{//中序遍历依托的函数 将左侧链入栈
		while (x)
		{
			S.push(x);
			x = x->lChild;//依次将左孩子入栈
		}
	}
	template <typename VST> void travIn(VST& visit)//子树中序遍历
	{
		stack<binNodePosi(T)> S;
		binNodePosi(T) x = this;//根节点
		while (true)
		{

			goAlongLeftBranch(x, S);
			if (S.empty()) break;//栈空表示遍历完成
			x = S.top();
			S.pop();
			visit(x->data);//立即访问之
			x = x->rChild;//转向右子树（可能为空，留意处理手法）
		}
	}

	
	template <typename VST> void gotoHLVFL(stack<binNodePosi(T)>& S)//在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
	{ //后序遍历依托函数 沿途所遇节点依次入栈
		while (binNodePosi(T) x = S.top()) //自顶而下，反复检查当前节点（即栈顶）
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
	template <typename VST> void travPost(VST& visit)//子树后序遍历
	{
		binNodePosi(T) x = this;//根节点
		stack<BinNodePosi(T)> S; //辅助栈

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
			visit(x->data); //弹出栈顶（即前一节点之后继），并访问之
		}
	}
};

template <typename T> class binTree //二叉树模板类
{
protected:
	int _size;//规模
	binNodePosi(T) _root;//根
	virtual int updateHeight(binNodePosi(T) x)//更新节点x的高度
	{
		return x->height = 1+max(stature(x->lChild),stature(x->rChild));
	}
	void updateHeightAbove(binNodePosi(T) x)//更新x及其祖先的高度
	{
		while (x)//可优化：一旦高度不改变 即可终止
		{
			updateHeight(x);
			x = x->parent;
		}
	}
public:
	binTree() :_size(0), _root(NULL){}
	~binTree(){ if (0 < _size){ removeTree(_root); } }
	int size() const //规模
	{
		return _size;
	}
	bool isEmpty() const //判空
	{
		return !_root;
	}
	binNodePosi(T) root() const //树根
	{
		return _root;
	}

	/******节点接入接口*****/
	binNodePosi(T) insertAsLC(binNodePosi(T) x, T const& e)//接入左子树
	{
		_size++;
		x->insertAsLC(e);//x的祖先高度可能变 其他结点高度必然不变
		updateHeightAbove(x);
		return x->lChild;
	}
	binNodePosi(T) insertAsRC(binNodePosi(T) x, T const& e)//接入右子树
	{
		_size++;
		x->insertAsRC(e);//x的祖先高度可能变 其他结点高度必然不变
		updateHeightAbove(x);
		return x->RChild;
	}
	binNodePosi(T) insertAsRoot(T const& e)
	{
		_size=1;
		_root = new binNode<T>(e);
		return _root;
	}

	/*****树接入 删除 分离接口*****/
	binNodePosi(T) attachAsLC(binNodePosi(T) x, binTree<T>* &S)//S本身置空 S当作节点x的左子树接入
	{
		if (x->lChild=S->_root)
		{
			x->lChild->parent = x;//接入
			_size += S->_size;
			updateHeightAbove(x);
			S->_root = NULL;
			S->_size = 0;//释放原树
			release(S);
			S = NULL;
			return x;
		}
	}
	binNodePosi(T) attachAsRC(binNodePosi(T) x, binTree<T>* &S)//S本身置空 S当作节点x的右子树接入
	{
		if (x->rChild = S->_root)
		{
			x->rChild->parent = x;//接入
			_size += S->_size;
			updateHeightAbove(x);
			S->_root = NULL;
			S->_size = 0;//释放原树
			release(S);
			S = NULL;
			return x;
		}
	}

	static int removeAt(binNodePosi(T) x)
	{
		if (!x)
			return 0;//空树
		else
		{
			int n = 1 + removeAt(x->lChild) + removeAt(x->rChild);
			release(x->data);
			release(x);
			return n;
		}
	}
	int removeTree(binNodePosi(T) x)//删除节点及其后代 返回规模
	{
		FromParentTo(*x) = NULL;//赶出家门 父不认子
		updateHeightAbove(x->parent);//更新高度 子认父
		int n = removeAt(x);//递归摘除子树
		_size -= n;
		return n;
	}
	
	binTree<T>* secede(binNodePosi(T) x)//摘除子树x并封装成新的树返回
	{
		FromParentTo(*x) = NULL;//赶出家门 父不认子
		updateHeightAbove(x->parent);//更新高度 子认父
		binTree<T>* S = new binTree<T>;
		S->_root = x;
		S->_size = x->size();
		x->parent = NULL; //离家出走 子不认父
		_size -= S->_size;
		return S;
	}

	/******遍历接口*****/
	template <typename VST> void travLeval(VST& visit)
	{ if (_root) _root->travLevel(visit); }
	template <typename VST> void travPre(VST& visit)
	{ if (_root) _root->travPre(visit); }
	template <typename VST> void travIn(VST& visit)
	{ if (_root) _root->travIn(visit); }
	template <typename VST> void travPost(VST& visit)
	{ if (_root) _root->travPost(visit); }

	/******先序初始化****/
	void createTreePre(T& in, binNodePosi(T) x)
	{
		cin >> in;
		if (in == '0')
		{
			x = NULL;
		}
		else
		{
			x = new binNode(tmp);
			updateHeightAbove(x);
			x->data = in;
			createTreePre(in, x->lChild);
			createTreePre(in, x->rChild);
		}
	}
};