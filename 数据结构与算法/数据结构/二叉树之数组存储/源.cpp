#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define binNodePosi binNode*   //���λ��
#define IsRoot(x) (!((x).parent))//������
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//��������
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//��������
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) //���Ը��׵�ָ�� 
/*	���㷨��ԭ�������ڵĽڵ������˿�λ������������ֵΪ0 ���ʱ ��������� Ϊ0��ʱ������
����1 2 3 4 0 5 6 7 8 0 0 9 10
���1 2 4 7 8 3 5 9 10 6
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
	{//��������������к���
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
	/*�������鲢����γ�ʼ����*/
	void createTreeInOne(int* num, int numsize)
	{
		int i;
		queue<int> Q;
		queue<binNodePosi> S;//�Ŷӽ��ܴ���
		_size += numsize;

		for (i = 0; i < numsize; i++)
		{
			Q.push(num[i]);
		}//Ԥ����������Ϊ����

		_root = new binNode(0, _root);
		binNodePosi x = _root;
		createTreeInTwo(Q, x, S);//�Ը��ڵ㴦�� 
		while (!Q.empty())
		{
			x = S.front();
			S.pop();
			createTreeInTwo(Q, x, S);
		}
		while (!S.empty())//���Q�ľ�֮���ʣ��ڵ�
		{
			x = S.front();
			S.pop();
			FromParentTo(*x) = NULL;//�ϳ����� ��������
			delete x;
		}
	}
	/*�������������ڵ�*/
	void visitBinTree()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;
		while (true)
		{
			visitAlongLeftBranch(x, S);//����ÿһ������ ��������� ���������ǻ�����ջ
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();//ȡ��һ���Һ��� Ҳ������һ����Ҫ�������������� ����������ͬ���ı�������
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