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
#define HasLChild(x) ((x).lChild)//��������
#define HasRChild(x) ((x).rChild)//��������

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
	binNodePosi _hot;//�����С��ڵ�ĸ���
	int time;//���Ҵ���
	binNodePosi result;//�����С��ڵ�
	binNodePosi _root;//����
	int _size;//���Ĺ�ģ

	binNodePosi& searchIn(binNodePosi& v, const datatype& e, binNodePosi& hot)
	{
		time++;
		if (!v||(e==v->data))
		{
			return v;//����ҵ��˻��߲���ʧ��ֱ�ӷ��� ����ҵ��˷������нڵ������ �Ҳ������ؼ����ڱ���λ������ ֵΪNULL
		}
		hot = v;
		return searchIn(((e < v->data) ? v->lChild : v->rChild), e, hot);//�ݹ�
		//����ʱ������ֵָ�����нڵ㣨�ҵ��ˣ����߼�����ڱ���λ�ã��Ҳ�����������룩��hotָ���丸��
	}
	binNodePosi succ(binNodePosi v)
	{//����v�����������µ�ֱ�Ӻ��
		binNodePosi s = v;
		if (s->rChild)//������Һ��ӣ�ֱ�Ӻ�̱�Ȼ���Һ����� ���Һ����о�����С���Ǹ�
		{
			s = s->rChild;
			while (HasLChild(*s))
				s = s->lChild;//���ģ���С���Ľڵ�
		}
		else//���� ֱ�Ӻ�̽��ǡ�����ǰ�ڵ������������������ͣ�Զ�����ȡ�
		{
			while (IsRChild(*s))
			{
				s = s->parent;//���������Ϸ��ƶ� ��������Զ��
			}
			s = s->parent;//�����Ϸ��ƶ� ����������������
		}
		return s;
	}
	binNodePosi removeAt(binNodePosi& x, binNodePosi& hot)
	{
		binNodePosi w = x;//ʵ�ʱ�ɾ���Ľڵ�
		binNodePosi theSucc = NULL;//��־������
		if (!HasLChild(*x))//ֻ��������
		{
			theSucc = x = x->rChild;//������ȡ��֮
		}
		else if (!HasRChild(*x))//ֻ��������
		{
			theSucc = x = x->lChild;//������ȡ��֮
		}
		else//˫�����ڵ�
		{
			w = succ(w);//�ҵ�ֱ�Ӻ��

			datatype tmp = w->data;
			w->data = x->data;
			x->data = tmp;//��֮����������

			binNodePosi u = w->parent;
			((u == x) ? u->rChild : u->lChild) = theSucc = w->rChild;//������� ����x
			/*w��Ȼ��Ҷ�ӽڵ����ֻ���Һ��ӵĽڵ� ���Խ�����һ����w->rChild ;
			  ���w��˫�ף���x ��ôx��ֱ�Ӻ����w��Ҳ����˵w��x���Һ��� ��w���Һ���������x���Һ��� ��w������x��ʵ��ɾ��w w���Һ��ӳ�Ϊүү���Һ���;
			  ���w��˫�ף�����x����ô��w���Һ���������x������ ��w������x ʵ��ɾ��w��w���Һ��ӳ�Ϊүү������;*/
		}
		hot = w->parent;//��¼ʵ�ʱ�ɾ���ڵ�ĸ��ף������ߵ�үү��
		if (theSucc)
		{
			theSucc->parent = hot;//��������үү��Ϊ����
		}
		delete w;//�ͷŽڵ�
		return theSucc;//���ؽ�����
	}
	void goAlongLeftBranch(binNodePosi x, stack<binNodePosi>& S)
	{//����������еĺ��� ���������ջ
		while (x)
		{
			S.push(x);
			x = x->lChild;//���ν�������ջ
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
		//�������һ�η��ʵ�λ�õ�����
	}
	binNodePosi insert(const datatype& e)
	{
		binNodePosi& x = search(e);//��������� _hot��ָ��ȽϹ������һ�����  ͬʱ�������Ӧ���ӣ��գ���λ��
		if (x) return x;//ȷ��Ŀ�겻���� �������_hot
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
			cout << x->data<<' ';//��������֮
			x = x->rChild;//ת��������������Ϊ�գ����⴦���ַ���
		}
		cout << endl;
	}
	/*������ҽ��*/
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