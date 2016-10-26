#include <iostream>
using namespace std;
#define datatype int
class LinkNode
{
public:
	datatype data;
	LinkNode* next;
	LinkNode(datatype e=0)
	{
		data = e;
		next = NULL;
	}
};
class LinkList
{
public:
	LinkList(int size=0)
	{
		head = new LinkNode();
		this->size = size;
	}
	~LinkList()
	{
		LinkNode *p = head;
		LinkNode* q = NULL;
		while (p->next)
		{
			q = p->next;
			delete p;
			p = q;
		}
		delete p;
	}
	LinkNode* getByIndex(int index)//index从head下一个算起 head的index是0;
	{
		LinkNode* p = head;
		if (index == 0)
		{
			return head;
		}
		while (index--)
		{
			p = p->next;
			if (!p)
				return 0;
		}
		return p;//可能是0（不存在）也可能是有;
	}
	datatype getDateByIndex(int index)
	{
		return getByIndex(index)->data;
	}
	bool insert(datatype e,int index)
	{		
		LinkNode* q = getByIndex(index - 1);
		if (q)
		{
			LinkNode* n = new LinkNode(e);
			LinkNode* p = q->next;
			q->next = n;
			n->next = p;
			size++;
			return true;
		}
		else
		{
			return false;
		}
	}
	void init(int length)
	{
		int i;
		char tmp;
		for (i = 1; i <= length; i++)
		{
			cin >> tmp;
			insert((int)tmp, i);
		}
	}
	bool Del(int i)
	{
		if (getByIndex(i - 1))
		{
			LinkNode *p = getByIndex(i - 1);
			p->next = p->next->next;
			size--;
			return true;
		}
		else
		{
			return false;
		}
	}
	void swapNodeByOrder(int index1,int index2)//用交换值的方式按左小右大的顺序交换结点;
	{
		LinkNode* p = getByIndex(index1);
		LinkNode* q = getByIndex(index2);
		datatype tmp;
		if (p->data > q->data)
		{
			tmp = p->data;
			p->data = q->data;
			q->data = tmp;
		}
	}
	void Display()
	{
		LinkNode *p = head->next;
		while (p->next)
		{
			cout <<(char) p->data << ' ';
			p = p->next;
		}
		cout<<(char)p->data << endl;
	}
	void sort()
	{
		int i, j;
		for (i = 1; i <= size; i++)
		{
			for (j = 1; j <= size - i;j++)
			{
				swapNodeByOrder(j, j+1);
			}
		}
	}
	void cut(LinkList& num,LinkList& bigChar,LinkList& smallChar)
	{
		//sort();
		LinkNode* p=head->next;
		int numCount = 0;
		int bigCount = 0;
		int smallCount = 0;
		while (p)
		{
			char c = (char)p->data;
			if ('0' <= c&&c <= '9')
			{
				num.insert(p->data, numCount + 1); numCount++;
			}
			else if ('a' <= c&&c <= 'z')
			{
				smallChar.insert(p->data, smallCount + 1); smallCount++;
			}
			else if ('A' <= c&&c <= 'Z')
			{
				bigChar.insert(p->data, bigCount + 1); bigCount++;
			}
			p = p->next;
		}
	}
private:
	LinkNode* head;
	int size;
};


int main()
{
	LinkList mainL, num, bigChar, smallChar;
	int size;
	cin >> size;
	mainL.init(size);
	mainL.cut(num, bigChar, smallChar);
	mainL.Display();

	bigChar.Display();
	smallChar.Display();
	num.Display();

	bigChar.sort();
	smallChar.sort();
	num.sort();

	bigChar.Display();
	smallChar.Display();
	num.Display();

	system("pause");
	return 0;
}