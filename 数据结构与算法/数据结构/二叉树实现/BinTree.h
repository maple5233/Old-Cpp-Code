#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define binNodePosi(T) binNode<T>*   //���λ��
#define stature(p) ((p)?(p)->height:-1)   //ͳһ�����ͷǿ����ĸ߶�

#define IsRoot(x) (!((x).parent))//������
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//��������
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//��������
#define HasParent(x) (!IsRoot(x))//�и���
#define HasLChild(x) ((x).lChild)//��������
#define HasRChild(x) ((x).rChild)//��������
#define HasChild(x) (HasLChild(x)||HasRChild(x)) //����ӵ��һ������
#define HasBothChild(x) (HasLChild(x)&&HasRChild(x)) //ͬʱӵ����������
#define IsLeaf(x) (!HasChild(x))//��Ҷ��

#define sibling(p) (IsLChild(*(p))?(p)->parent->rChild:(p)->parent->lChild) /*�ֵ�*/
#define uncle(x) (IsLChild(*((x)->parent))?(x)->parent->parent->rChild:(x)->parent->parent->lChild) /*����*/
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) /*���Ը��׵�ָ��*/ 

template <typename T> class Cleaner {
	static void clean(T x) { //�൱�ڵݹ��
	}
};
template <typename T> class Cleaner<T*> {
	static void clean(T* x) {
		if (x) { delete x; } //������а���ָ�룬�ݹ��ͷ�
	}
};
template <typename T> void release(T x) 
{ Cleaner<T>::clean(x); }

template <typename T> class binNode //������ģ���� <typename T>��ͬ��<class T>
{
public:
	binNodePosi(T) parent, lChild, rChild;
	T data;//������
	int height;//�ýڵ�߶�

	binNode()
	{
		this->lChild = NULL;
		this->rChild = NULL;
		this->parent = NULL;
		this->height = 0;
	}
	binNode(T e, binNodePosi(T) pos = NULL, binNodePosi(T) lc = NULL, binNodePosi(T) rc = NULL, int h = 0) 
		:data(e), parent(pos), lChild(lc), rChild(rc), height(h){}

	/*const&��ʾ������ ��ʱ���޷�ͨ�������޸�ԭ������ֵ ���ܼӲ���const ���ñ����Ǳ��뱻��ʼ�����ҳ�ʼ�������޷����ı��*/
	binNodePosi(T) insertAsLC(T const& e)//��Ϊ����������
	{
		return lChild = new binNode(e, this);
	}
	binNodePosi(T) insertAsRC(T const& e)//��Ϊ����������
	{
		return rChild = new binNode(e, this);
	}

	int size()//����������ģ Ҳ���Ǻ������
	{
		int s = 1;
		if (lChild) s += lChild->size();//�ݹ�������������
		if (rChild) s += rChild->size();//�ݹ�������������
		return s;
	}
	binNodePosi(T) succ()//���������µ�ֱ�Ӻ��
	{
		binNodePosi(T) s = this;//��¼��̵���ʱ����
		if (rChild) 
		{ //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
			s = rChild; //��������
			while (s->lChild) 
			{
				s = s->lc; //�����С���Ľڵ�
			}
		}
		else 
		{ //����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
			while (s->parent != NULL&&s==s->parent->rChild)//���s���Һ���
			{
				s = s->parent; //������������֧�����ϳ����Ϸ��ƶ�
			}
			s = s->parent; //����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ�̣�������ڣ�
		}
		return s;
	}

	/*�����ӿ�*/
	template <typename VST> void travLevel(VST& visit)//������α���
	{
		queue<binNodePosi(T)> Q;
		Q.push(this);//���ڵ����
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
	{//����������еĺ��� ������������ʽڵ�
		while (x)
		{
			visit(x->data);//���ʵ�ǰ�ڵ�
			if (x->rChild)
			{
				S.push(x->rChild);//�Һ��ӽ�ջ
			}
			x = x->lChild;//������������� ֱ��û��������
		}
	}
	template <typename VST> void travPre(VST& visit)//�����������
	{
		stack<binNodePosi(T)> S;
		binNodePosi(T) x = this;//���ڵ�
		while (true)
		{//������Ϊ��λ �������ʽڵ�
			visitAlongLeftBranch(x, visit, S);//����ÿһ������ ��������� ���������ǻ�����ջ
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();//ȡ��һ���Һ��� Ҳ������һ����Ҫ�������������� ����������ͬ���ı�������
			S.pop();
		}
	}

	template <typename VST> void goAlongLeftBranch(binNodePosi(T) x,stack<binNodePosi(T)>& S)
	{//����������еĺ��� ���������ջ
		while (x)
		{
			S.push(x);
			x = x->lChild;//���ν�������ջ
		}
	}
	template <typename VST> void travIn(VST& visit)//�����������
	{
		stack<binNodePosi(T)> S;
		binNodePosi(T) x = this;//���ڵ�
		while (true)
		{

			goAlongLeftBranch(x, S);
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();
			S.pop();
			visit(x->data);//��������֮
			x = x->rChild;//ת��������������Ϊ�գ����⴦���ַ���
		}
	}

	
	template <typename VST> void gotoHLVFL(stack<binNodePosi(T)>& S)//����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
	{ //����������к��� ��;�����ڵ�������ջ
		while (binNodePosi(T) x = S.top()) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
		{
			if (x->lChild || x->rChild)
			{ //����������
				if (x->rChild) 
				{
					S.push(x->rChild); //�����Һ��ӣ�������ջ
				}
				S.push(x->lChild); //Ȼ���ת������
			}
			else
			{//ʵ������
				S.push(x->rChild); //������
			}
			if (!S.top())
				break;
		}
		S.pop(); //����֮ǰ������ջ���Ŀսڵ�
	}
	template <typename VST> void travPost(VST& visit)//�����������
	{
		binNodePosi(T) x = this;//���ڵ�
		stack<BinNodePosi(T)> S; //����ջ

		if (x) 
			S.push(x); //���ڵ���ջ

		while (!S.empty())
		{
			if (S.top() != x->parent) //��ջ���ǵ�ǰ�ڵ�֮�������Ϊ�����֣�����ʱ��
			{
				gotoHLVFL(S); //����������Ϊ��֮�����У��ҵ�HLVFL���൱�ڵݹ��������У� 
			}	//���ջ���ǵ�ǰ�ڵ�ĸ��׽ڵ� ��˵�����Һ����Ѿ�������� ���Է��ʸ�����
			x = S.top();
			S.pop();
			visit(x->data); //����ջ������ǰһ�ڵ�֮��̣���������֮
		}
	}
};

template <typename T> class binTree //������ģ����
{
protected:
	int _size;//��ģ
	binNodePosi(T) _root;//��
	virtual int updateHeight(binNodePosi(T) x)//���½ڵ�x�ĸ߶�
	{
		return x->height = 1+max(stature(x->lChild),stature(x->rChild));
	}
	void updateHeightAbove(binNodePosi(T) x)//����x�������ȵĸ߶�
	{
		while (x)//���Ż���һ���߶Ȳ��ı� ������ֹ
		{
			updateHeight(x);
			x = x->parent;
		}
	}
public:
	binTree() :_size(0), _root(NULL){}
	~binTree(){ if (0 < _size){ removeTree(_root); } }
	int size() const //��ģ
	{
		return _size;
	}
	bool isEmpty() const //�п�
	{
		return !_root;
	}
	binNodePosi(T) root() const //����
	{
		return _root;
	}

	/******�ڵ����ӿ�*****/
	binNodePosi(T) insertAsLC(binNodePosi(T) x, T const& e)//����������
	{
		_size++;
		x->insertAsLC(e);//x�����ȸ߶ȿ��ܱ� �������߶ȱ�Ȼ����
		updateHeightAbove(x);
		return x->lChild;
	}
	binNodePosi(T) insertAsRC(binNodePosi(T) x, T const& e)//����������
	{
		_size++;
		x->insertAsRC(e);//x�����ȸ߶ȿ��ܱ� �������߶ȱ�Ȼ����
		updateHeightAbove(x);
		return x->RChild;
	}
	binNodePosi(T) insertAsRoot(T const& e)
	{
		_size=1;
		_root = new binNode<T>(e);
		return _root;
	}

	/*****������ ɾ�� ����ӿ�*****/
	binNodePosi(T) attachAsLC(binNodePosi(T) x, binTree<T>* &S)//S�����ÿ� S�����ڵ�x������������
	{
		if (x->lChild=S->_root)
		{
			x->lChild->parent = x;//����
			_size += S->_size;
			updateHeightAbove(x);
			S->_root = NULL;
			S->_size = 0;//�ͷ�ԭ��
			release(S);
			S = NULL;
			return x;
		}
	}
	binNodePosi(T) attachAsRC(binNodePosi(T) x, binTree<T>* &S)//S�����ÿ� S�����ڵ�x������������
	{
		if (x->rChild = S->_root)
		{
			x->rChild->parent = x;//����
			_size += S->_size;
			updateHeightAbove(x);
			S->_root = NULL;
			S->_size = 0;//�ͷ�ԭ��
			release(S);
			S = NULL;
			return x;
		}
	}

	static int removeAt(binNodePosi(T) x)
	{
		if (!x)
			return 0;//����
		else
		{
			int n = 1 + removeAt(x->lChild) + removeAt(x->rChild);
			release(x->data);
			release(x);
			return n;
		}
	}
	int removeTree(binNodePosi(T) x)//ɾ���ڵ㼰���� ���ع�ģ
	{
		FromParentTo(*x) = NULL;//�ϳ����� ��������
		updateHeightAbove(x->parent);//���¸߶� ���ϸ�
		int n = removeAt(x);//�ݹ�ժ������
		_size -= n;
		return n;
	}
	
	binTree<T>* secede(binNodePosi(T) x)//ժ������x����װ���µ�������
	{
		FromParentTo(*x) = NULL;//�ϳ����� ��������
		updateHeightAbove(x->parent);//���¸߶� ���ϸ�
		binTree<T>* S = new binTree<T>;
		S->_root = x;
		S->_size = x->size();
		x->parent = NULL; //��ҳ��� �Ӳ��ϸ�
		_size -= S->_size;
		return S;
	}

	/******�����ӿ�*****/
	template <typename VST> void travLeval(VST& visit)
	{ if (_root) _root->travLevel(visit); }
	template <typename VST> void travPre(VST& visit)
	{ if (_root) _root->travPre(visit); }
	template <typename VST> void travIn(VST& visit)
	{ if (_root) _root->travIn(visit); }
	template <typename VST> void travPost(VST& visit)
	{ if (_root) _root->travPost(visit); }

	/******�����ʼ��****/
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