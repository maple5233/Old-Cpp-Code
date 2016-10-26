//构建huffman树的过程中有大量增删操作 又不需要考虑元素的顺序和位置 因此链表来存放森林最佳 但是OJ系统不支持LIST库 只好改用数组
#include<string>
#include<iostream>
#include<map>//使用map表来记录编码表
using namespace std;

#define datatype huffChar //数据类型
#define binNodePosi binNode*   //结点位置
#define HasLChild(x) ((x).lChild)//有左子树
#define HasRChild(x) ((x).rChild)//有右子树
#define HasChild(x) (HasLChild(x)||HasRChild(x)) //至少拥有一个孩子
#define IsLeaf(x) (!HasChild(x))//是叶子
#define IsRoot(x) (!((x).parent))//是树根


class huffChar
{
public:
	char ch;
	int weight;
	huffChar(char c = '#', int w = 0) :ch(c), weight(w){}
};
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
	/*树接入接口*/
	binNodePosi attachAsLC(binNodePosi x, binTree* &S)//S本身置空 S当作节点x的左子树接入
	{
		if (x->lChild = S->_root)
		{
			x->lChild->parent = x;//接入
			_size += S->_size;
			S->_root = NULL;
			delete S;//释放原树
			return x;
		}
		return NULL;
	}
	binNodePosi attachAsRC(binNodePosi x, binTree* &S)//S本身置空 S当作节点x的左子树接入
	{
		if (x->rChild = S->_root)
		{
			x->rChild->parent = x;//接入
			_size += S->_size;
			S->_root = NULL;
			delete S;//释放原树
			return x;
		}
		return NULL;
	}
	/******根节点接入接口*****/
	binNodePosi  insertAsRoot(datatype const& e)
	{
		_size = 1;
		_root = new binNode(e);
		return _root;
	}
};

binTree* forest[100];//空森林
int size = 0;//森林规模
/*编码森林初始化*/
void initForest()
{
	int i;
	cin >> size;
	huffChar* ch = new huffChar[size];
	for (i = 0; i < size; i++)
	{
		cin >> ch[i].weight;
	}
	for (i = 0; i < size; i++)
	{
		cin >> ch[i].ch;	
	}
	for (i = 0; i < size; i++)
	{
		binTree* tree = new binTree();
		tree->insertAsRoot(ch[i]);
		forest[i] = tree;
	}//构造森林
}
/*找出最小权重Huffman字符所在的树*/
binTree* minChar(binTree** forest)
{
	int i;
	binTree* p = forest[0];//从首个开始寻找
	binTree* minChar = p;
	int minWeight = p->_root->data.weight;
	for (i = 0; i<size; i++)//使用寻找最小
	{
		if (minWeight > forest[i]->_root->data.weight)
		{
			minWeight = forest[i]->_root->data.weight;
			minChar = forest[i];
		}
	}
	/*从森林中删除minChar*/
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
/*huffman编码算法*/
binTree* generateTree(binTree** forest)
{
	while (1 < size)
	{
		binTree* T1 = minChar(forest);//倒数第一
		binTree* T2 = minChar(forest);//倒数第二
		binTree* S = new binTree();
		huffChar tmp;
		tmp.ch = 0;
		tmp.weight = T1->_root->data.weight + T2->_root->data.weight;
		S->insertAsRoot(tmp);
		S->attachAsLC(S->_root, T1);//如果要求左孩子权值不大于右孩子 就应该把T1放在左边
		S->attachAsRC(S->_root, T2);
		forest[size] = S;//将S放回森林
		size++;
	}
	return forest[0];
}
/*遍历获取编码*/
void generateCT(string code, binNodePosi v, map<char, string>& huffTable)
{
	if (IsLeaf(*v))
	{
		char c;
		c = v->data.ch;
		huffTable[c] = code;//存入表
		return;
	}
	if (HasLChild(*v))//left=0
	{
		generateCT(code + '0', v->lChild, huffTable);
		//code不直接先+'0' 而是在作为参数传递给下一层的时候再加'0'是为了不影响下一个if
	}
	if (HasRChild(*v))//right=1
	{
		generateCT(code + '1', v->rChild, huffTable);
	}
}
/*构成编码字典*/
map<char, string>* generateTable(binTree* tree)
{
	map<char, string>* table = new map<char, string>;
	string code = "";
	generateCT(code, tree->_root, *table);
	return table;
}
/*打印编码表*/
void tableDisplay(map<char, string> huffTable)
{
	map<char, string>::iterator it;
	for (it = huffTable.begin(); it != huffTable.end(); it++)
	{
		cout << it->first << " :" << it->second << endl;
	}
}
/*按字典编码*/
void encode(string s, map<char, string> huffTable, string& code)
{
	string::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		code += huffTable[*it];
	}
}
/*按字典解码*/
bool decodeOne(string code, map<char, string> huffTable, string& s)
{
	string::iterator it;
	map<char, string>::iterator result;
	string tmp = "";
	it = code.begin();
	while (true)
	{
		tmp += (*it);
		for (result = huffTable.begin(); result != huffTable.end(); result++)
		{
			if (result->second == tmp)//找到value值为tmp的元素
			{
				s += result->first;//找到对应的原码
				code.erase(0, tmp.length());//删除已经解码的部分
				tmp = "";//清空tmp;
				if (!code.empty())//还没解码完成
				{
					it = code.begin();//接着解码
					break;//退出for循环
				}
				else
				{
					return true;//解码完成
				}
			}
		}
		if (it == code.end() - 1)//如果it走到了string的尽头（没字符串可以取）还找不到，则解码失败
		{
			if (result == huffTable.end())
			{
				return false;
			}
		}
		if (result == huffTable.end())//没能找到但是还有字符串可以取
		{
			it++;//还有希望
		}
	}
}
/*按编码树解码*/
bool decodeTwo(string code, binTree* tree, string& s)
{
	unsigned int i = 0, dir = 0;
	binNodePosi x = tree->_root;
	for (i = 0;; i++)
	{
		dir = int(code[i] - 48);//方向是1(右)或者0(左)
		x = dir ? x->rChild : x->lChild;

		if (i == code.length() - 1)//解码走到尽头的时候
		{
			if (!IsLeaf(*x))//如果不是叶子
			{
				return false;
			}
			else
			{
				s += x->data.ch;
				return true;
			}

		}

		if (IsLeaf(*x))//到达终点找到对应的编码
		{
			s += x->data.ch;
			x = tree->_root;
		}
	}
}
int main()
{
	int T, k;
	cin >> T;
	while (T--)
	{
		initForest();//构建森林
		binTree* huffmanTree = generateTree(forest);//构建huffman树
		map<char, string>* huffmanTable = generateTable(huffmanTree);//构建编码字典
		cin >> k;//解码次数
		while (k--)
		{
			string s="";
			string code = "";
			cin >> code;
			bool decodeSuccess;
			decodeSuccess = decodeTwo(code, huffmanTree, s);
			if (decodeSuccess)
			{
				cout << s << endl;
			}
			else
			{
				cout << "error" << endl;
			}
		}
	}
	return 0;
}