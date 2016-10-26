#include<stack>
#include<queue>
#include<iostream>
using namespace std;
#define datatype int //��������
#define binNodePosi binNode*   //���λ��
#define IsRoot(x) (!((x).parent))//������
#define IsLChild(x) (!IsRoot(x)&&(&(x)==(x).parent->lChild))//��������
#define IsRChild(x) (!IsRoot(x)&&(&(x)==(x).parent->rChild))//��������
#define FromParentTo(x) (IsRoot(x)?_root:(IsLChild(x)?(x).parent->lChild:(x).parent->rChild)) //���Ը��׵�ָ��

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
	void createTreePre(binNodePosi& x,binNodePosi xp)//x��_root��ʼ xpΪ���ڵ�
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
	{//�������������к���
		while (x)
		{
			cout << x->data;//���ʵ�ǰ�ڵ�
			if (x->rChild)
			{
				S.push(x->rChild);//�Һ��ӽ�ջ
			}
			x = x->lChild;//������������� ֱ��û��������
		}
	}
	void visitAlongLeftBranchTwo(binNodePosi x, stack<binNodePosi>& S)
	{//�������������к��� ����汾����0
		while (x)
		{
			if (x->data)
			{
				cout << x->data<<' ';//���ʵ�ǰ�ڵ�
			}
			if (x->rChild)
			{
				S.push(x->rChild);//�Һ��ӽ�ջ
			}
			x = x->lChild;//������������� ֱ��û��������
		}
	}
	void goAlongLeftBranch(binNodePosi x, stack<binNodePosi>& S)
	{//����������еĺ��� ���������ջ
		while (x)
		{
			S.push(x);
			x = x->lChild;//���ν�������ջ
		}
	}
	void gotoHLVFL(stack<binNodePosi>& S)//����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
	{ //����������к��� ��;�����ڵ�������ջ
		while (binNodePosi x = S.top()) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
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
	int countLeaves(binNodePosi x)//������Ҷ�������ڲ�����
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
	{//�������������α���������ʼ���������к���
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
	/*��������ݹ��ʼ����*/
	void createTreePre()
	{
		createTreePre(_root,NULL);
	}
	/*�������������α���������ʼ����*/
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
	/*��ε����������*/
	void travLevel()
	{
		queue<binNodePosi> Q;
		Q.push(_root);//���ڵ����
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
	/*��������������*/
	void travPre()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//���ڵ�
		while (true)
		{//������Ϊ��λ �������ʽڵ�
			visitAlongLeftBranch(x, S);//����ÿһ������ ��������� ���������ǻ�����ջ
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();//ȡ��һ���Һ��� Ҳ������һ����Ҫ�������������� ����������ͬ���ı�������
			S.pop();
		}
		cout << endl;
	}
	/*��������������������0��*/
	void travPreTwo()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//���ڵ�
		while (true)
		{//������Ϊ��λ �������ʽڵ�
			visitAlongLeftBranchTwo(x, S);//����ÿһ������ ��������� ���������ǻ�����ջ
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();//ȡ��һ���Һ��� Ҳ������һ����Ҫ�������������� ����������ͬ���ı�������
			S.pop();
		}
		cout << endl;
	}
	/*��������������*/
	void travIn()
	{
		stack<binNodePosi> S;
		binNodePosi x = _root;//���ڵ㿪ʼ
		while (true)
		{
			goAlongLeftBranch(x, S);
			if (S.empty()) break;//ջ�ձ�ʾ�������
			x = S.top();
			S.pop();
			cout << x->data;//��������֮
			x = x->rChild;//ת��������������Ϊ�գ����⴦���ַ���
		}
		cout << endl;
	}
	/*��������������*/
	void travPost()
	{
		binNodePosi x = _root;//���ڵ�
		stack<binNodePosi> S; //����ջ

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
			cout<<x->data; //����ջ������ǰһ�ڵ�֮��̣���������֮
		}
		cout << endl;
	}
	/*��Ҷ������*/
	int countLeaves()
	{
		return countLeaves(_root);
	}
	/*��������*/
	int countMaxPath()//��root��ʼ
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