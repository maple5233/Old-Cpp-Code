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
#define HasLChild(x) ((x).lChild)//有左子树
#define HasRChild(x) ((x).rChild)//有右子树

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
class BST
{
private:
	binNodePosi _hot;//“命中”节点的父亲
	int time;//查找次数
	binNodePosi result;//“命中”节点
	binNodePosi _root;//树根
	int _size;//树的规模

	binNodePosi& searchIn(binNodePosi& v, const datatype& e, binNodePosi& hot)
	{
		time++;
		if (!v||(e==v->data))
		{
			return v;//如果找到了或者查找失败直接返回 如果找到了返回命中节点的引用 找不到返回假想哨兵的位置引用 值为NULL
		}
		hot = v;
		return searchIn(((e < v->data) ? v->lChild : v->rChild), e, hot);//递归
		//返回时，返回值指向命中节点（找到了）或者假想的哨兵的位置（找不到，方便插入），hot指向其父亲
	}
	binNodePosi succ(binNodePosi v)
	{//返回v在中序意义下的直接后继
		binNodePosi s = v;
		if (s->rChild)//如果有右孩子，直接后继必然在右孩子中 是右孩子中尽可能小的那个
		{
			s = s->rChild;
			while (HasLChild(*s))
				s = s->lChild;//最靠左的（最小）的节点
		}
		else//否则 直接后继将是“将当前节点包含于其左子树的最低（远）祖先”
		{
			while (IsRChild(*s))
			{
				s = s->parent;//不断向左上方移动 （尽可能远）
			}
			s = s->parent;//向右上方移动 （包含于左子树）
		}
		return s;
	}
	binNodePosi removeAt(binNodePosi& x, binNodePosi& hot)
	{
		binNodePosi w = x;//实际被删除的节点
		binNodePosi theSucc = NULL;//标志接替者
		if (!HasLChild(*x))//只有右子树
		{
			theSucc = x = x->rChild;//右子树取代之
		}
		else if (!HasRChild(*x))//只有左子树
		{
			theSucc = x = x->lChild;//左子树取代之
		}
		else//双子树节点
		{
			w = succ(w);//找到直接后继

			datatype tmp = w->data;
			w->data = x->data;
			x->data = tmp;//与之交换数据域

			binNodePosi u = w->parent;
			((u == x) ? u->rChild : u->lChild) = theSucc = w->rChild;//逐出家门 隔离x
			/*w必然是叶子节点或者只有右孩子的节点 所以接替者一定是w->rChild ;
			  如果w的双亲ｕ是x 那么x的直接后继是w，也就是说w是x的右孩子 用w的右孩子来接替x的右孩子 用w来接替x，实际删除w w的右孩子成为爷爷的右孩子;
			  如果w的双亲ｕ不是x，那么用w的右孩子来接替x的左孩子 用w来接替x 实际删除w，w的右孩子成为爷爷的左孩子;*/
		}
		hot = w->parent;//记录实际被删除节点的父亲（接替者的爷爷）
		if (theSucc)
		{
			theSucc->parent = hot;//接替者与爷爷结为父子
		}
		delete w;//释放节点
		return theSucc;//返回接替者
	}
	void goAlongLeftBranch(binNodePosi x, stack<binNodePosi>& S)
	{//中序遍历依托的函数 将左侧链入栈
		while (x)
		{
			S.push(x);
			x = x->lChild;//依次将左孩子入栈
		}
	}
public:
	BST()
	{
		_hot = NULL;
		time = 0;
		result = NULL;
		_size = 0;
		_root = NULL;
	}
	binNodePosi& search(const datatype& e)
	{
		time = 0;
		return searchIn(_root,e,_hot=NULL);
		//返回最后一次访问的位置的引用
	}
	binNodePosi insert(const datatype& e)
	{
		binNodePosi& x = search(e);//如果不存在 _hot将指向比较过的最后一个结点  同时返回其对应孩子（空）的位置
		if (x) return x;//确认目标不存在 并计算出_hot
		x = new binNode(e,_hot);
		_size++;
		return x;
	}
	bool remove(const datatype& e)
	{
		binNodePosi& x = search(e);
		if (!x) return false;
		removeAt(x, _hot);
		_size--;
		return true;
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
			cout << x->data<<' ';//立即访问之
			x = x->rChild;//转向右子树（可能为空，留意处理手法）
		}
		cout << endl;
	}
	/*输出查找结果*/
	void displayResult(const datatype& e)
	{
		bool success;
		if (search(e))
		{
			success = true;
		}
		else
		{
			success = false;
		}
		if (success)
		{
			cout << time << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		BST bst;
		int size,tmp,de;
		cin >> size;
		while (size--)
		{
			cin >> tmp;
			bst.insert(tmp);
		}
		bst.travIn();
		cin >> de;
		while (de--)
		{
			cin >> tmp;
			bst.remove(tmp);
			bst.travIn();
		}
	}
}