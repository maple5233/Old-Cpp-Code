//����huffman���Ĺ������д�����ɾ���� �ֲ���Ҫ����Ԫ�ص�˳���λ�� ������������ɭ����� ����OJϵͳ��֧��LIST�� ֻ�ø�������
#include<string>
#include<iostream>
using namespace std;

#define datatype myInt //��������
#define binNodePosi binNode*   //���λ��
#define HasLChild(x) ((x).lChild)//��������
#define HasRChild(x) ((x).rChild)//��������
#define HasChild(x) (HasLChild(x)||HasRChild(x)) //����ӵ��һ������
#define IsLeaf(x) (!HasChild(x))//��Ҷ��
#define IsRoot(x) (!((x).parent))//������

class myInt
{
public:
	int weight;//Ȩ��
	int index;//�����˳��
	myInt(int w = 0, int in = 0)
	{
		weight = w;
		index = in;
	}
};//�ڵ�������
class myTable
{
public:
	myInt data;
	string code;
	myTable()
	{
		myInt a(0, 0);
		string co = "";
		data = a;
		code = co;
	}
	myTable(myInt data, string code)
	{
		this->data = data;
		this->code = code;
	}
};//�ʵ���
class binNode
{
public:
	binNodePosi parent;
	binNodePosi lChild;
	binNodePosi rChild;
	datatype data;
	binNode(datatype dat, binNodePosi p = NULL, binNodePosi l = NULL, binNodePosi r = NULL)
		:data(dat), parent(p), lChild(l), rChild(r){}
};
class binTree
{
public:
	int _size;
	binNodePosi _root;
public:
	binTree() :_size(0), _root(NULL){}
	/*������ӿ�*/
	binNodePosi attachAsLC(binNodePosi x, binTree* &S)//S�����ÿ� S�����ڵ�x������������
	{
		if (x->lChild = S->_root)
		{
			x->lChild->parent = x;//����
			_size += S->_size;
			S->_root = NULL;
			delete S;//�ͷ�ԭ��
			return x;
		}
		return NULL;
	}
	binNodePosi attachAsRC(binNodePosi x, binTree* &S)//S�����ÿ� S�����ڵ�x������������
	{
		if (x->rChild = S->_root)
		{
			x->rChild->parent = x;//����
			_size += S->_size;
			S->_root = NULL;
			delete S;//�ͷ�ԭ��
			return x;
		}
		return NULL;
	}
	/******���ڵ����ӿ�*****/
	binNodePosi  insertAsRoot(datatype const& e)
	{
		_size = 1;
		_root = new binNode(e);
		return _root;
	}
};

binTree* forest[100];//��ɭ��
int size = 0;//ɭ�ֹ�ģ
myTable table[100];//�ʵ�����
int j = 0;

/*����ɭ�ֳ�ʼ��*/
void initForest()
{
	int i;
	cin >> size;
	myInt* ch = new myInt[size];

	for (i = 0; i < size; i++)
	{
		ch[i].index = i;
		cin >> ch[i].weight;
	}
	for (i = 0; i < size; i++)
	{
		binTree* tree = new binTree();
		tree->insertAsRoot(ch[i]);
		forest[i] = tree;
	}//����ɭ��
}
/*�ҳ���СȨ��Huffman�ַ����ڵ�����ɾ��֮*/
binTree* minChar(binTree** forest)
{
	int i;
	binTree* p = forest[0];//���׸���ʼѰ��
	binTree* minChar = p;
	int minWeight = p->_root->data.weight;
	for (i = 0; i<size; i++)//ʹ��Ѱ����С
	{
		if (minWeight > forest[i]->_root->data.weight)
		{
			minWeight = forest[i]->_root->data.weight;
			minChar = forest[i];
		}
	}
	/*��ɭ����ɾ��minChar*/
	for (i = 0; i < size; i++)
	{
		if (forest[i] == minChar)
			break;
	}
	for (; i < size - 1; i++)
	{
		forest[i] = forest[i + 1];
	}
	size--;
	return minChar;
}
/*huffman�����㷨*/
binTree* generateTree(binTree** forest)
{
	while (1<size)
	{
		binTree* T1 = minChar(forest);
		binTree* T2 = minChar(forest);
		binTree* S = new binTree();
		myInt tmp;
		tmp.weight = T1->_root->data.weight + T2->_root->data.weight;
		tmp.index = 999;
		S->insertAsRoot(tmp);
		S->attachAsLC(S->_root, T1);
		S->attachAsRC(S->_root, T2);
		forest[size] = S;//��S�Ż�ɭ��
		size++;
	}
	return forest[0];
}
/*������ȡ����*/
void generateCT(string code, binNodePosi v)
{
	if (IsLeaf(*v))
	{
		myInt c(v->data.weight, v->data.index);
		myTable tmp(c, code);
		table[j] = tmp;
		j++;
		return;
	}
	if (HasLChild(*v))//left=0
	{
		generateCT(code + '0', v->lChild);
		//code��ֱ����+'0' ��������Ϊ�������ݸ���һ���ʱ���ټ�'0'��Ϊ�˲�Ӱ����һ��if
	}
	if (HasRChild(*v))//right=1
	{
		generateCT(code + '1', v->rChild);
	}
}
/*���ɱ����ֵ�*/
void generateTable(binTree* tree)
{
	string code = "";
	generateCT(code, tree->_root);
}
/*��ӡ�����*/
void tableDisplay()
{
	int i, k;
	for (i = 0; i <j; i++)
	{
		for (k = 0; k < j; k++)
		{
			if (table[k].data.index == i)
				cout << table[k].data.weight << "-" << table[k].code << endl;
		}
	}//����������ӡ
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		initForest();//����ɭ��
		binTree* huffmanTree = generateTree(forest);//����huffman��
		generateTable(huffmanTree);//���������ֵ�
		tableDisplay();
	}
	return 0;
}