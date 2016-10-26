#include<iostream>
using namespace std;
#include <iostream> 
using namespace std;
#define ok 1 
#define error 0 

class polynode
{
public:
	int expn; //指数
	float coef;//系数
};
class ListNode
{
public:
	polynode data;
	ListNode * next;
	ListNode()
	{
		next = NULL;
	}
};

class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList()
	{
		head = new ListNode();
		len = 0;
	}
	ListNode* LL_index(int i)//按位置获取结点指针域 注意如果位置i为0不会返回头指针 而是返回空
	{
		ListNode *p = head->next;
		int j = 1;
		while (p&&j<i)
		{
			p = p->next;
			++j;
		}
		if (!p || j>i)
			return error;
		return p;
	}
	polynode LL_get(int i)//按位置获取结点数据域
	{
		ListNode *p = head;
		p = p->next;
		int j = 1;
		while (p&&j<i)
		{
			p = p->next;
			++j;
		}
		return p->data;
	}
	int LL_insert(int i, polynode item)//插入函数
	{
		ListNode *p = head;
		int j = 0;
		while (p&&j<i - 1)
		{
			p = p->next;
			++j;
		}
		if (!p || j>i - 1)
		{
			return error;
		}
		ListNode* s = new ListNode();
		s->data.coef = item.coef;
		s->data.expn = item.expn;
		s->next = p->next;
		p->next = s;
		len++;
		return ok;
	}
	int LL_del(int i)
	{
		ListNode *p = head;
		int j = 1;
		while (p&&j<i)
		{
			p = p->next;
			++j;
		}
		if (!p || j>i)
			return error;
		p->next = p->next->next;
		len--;
		return ok;
	}
	void LL_display()
	{
		ListNode* p;
		ListNode* q;
		p = head->next;
		q = this->LL_index(len);
		while (p != q)
		{
			if (p->data.expn<0)//负数非常数项
			{
				if (p->data.coef<0.0)
				{
					cout << '(' << p->data.coef << ')' << "x^(" << p->data.expn << ") + ";
				}
				if (p->data.coef>0.0)
				{
					cout << p->data.coef << "x^(" << p->data.expn << ") + ";
				}
			}
			if ((p->data.expn == 0) && (p->data.coef<0.0))//常数项 负数
			{
				cout << '(' << p->data.coef << ')' << " + ";
			}
			if ((p->data.expn == 0) && (p->data.coef>0.0))//常数项 正数
			{
				cout << p->data.coef << " + ";
			}
			if (p->data.expn>0)//正数非常数项
			{
				if (p->data.coef<0.0)
				{
					cout << '(' << p->data.coef << ')' << "x^" << p->data.expn << " + ";
				}
				if (p->data.coef>0.0)
				{
					cout << p->data.coef << "x^" << p->data.expn << " + ";
				}
			}
			p = p->next;
		}

		if (p->data.expn<0)
		{
			if (p->data.coef<0.0)
			{
				cout << '(' << p->data.coef << ')' << "x^(" << p->data.expn << ")";
			}
			if (p->data.coef>0.0)
			{
				cout << p->data.coef << "x^(" << p->data.expn << ")";
			}
		}
		if (p->data.expn == 0 && p->data.coef<0.0)
		{
			cout << '(' << p->data.coef << ')';
		}
		if (p->data.expn == 0 && p->data.coef>0.0)
		{
			cout << p->data.coef;
		}
		if (p->data.expn>0)
		{
			if (p->data.coef<0.0)
			{
				cout << '(' << p->data.coef << ')' << "x^" << p->data.expn;
			}
			if (p->data.coef>0.0)
			{
				cout << p->data.coef << "x^" << p->data.expn;
			}
		}
		cout << endl;
	}
	bool LL_empty()
	{
		if (len == 0)
			return true;
		else
			return false;
	}
	void delFirst(ListNode *p, ListNode *q)//删除p指针的下一个结点，并且把这个结点赋给q 即取出结点
	{
		q->next = p->next->next;
		q->data = p->next->data;
		p->next = p->next->next;
		len--;
	}
	void insFirst(ListNode *p, ListNode *q)//在结点p的下一个插入一个结点 使得结点的数据域等于q的数据域 即加入结点
	{
		ListNode* s = new ListNode();
		s->data = q->data;
		s->next = p->next;
		p->next = s;
		len++;
	}
};

void CreatePolyn(LinkList &P, int m)//建立一元多项式链表P 项数为m
{
	polynode e;
	int i = 0;
	ListNode* h = P.head;
	e.coef = 0.0;
	e.expn = -1;
	h->data = e;
	for (i = 1; i <= m; i++)
	{
		cin >> e.coef >> e.expn;
		if (!P.LL_insert(i, e))
		{
			cout << "error" << endl;
		}
	}
}

void addPolyn(LinkList &a, LinkList &b)//多项式相加
{
	ListNode* ha = a.head;//ha总是指向a最后一个被处理的结点 也就是a链中处理完成部分的最后一个
	ListNode* hb = b.head;//hb总是指向b最后一个被处理的结点 也就是b链中处理完成部分的最后一个
	ListNode* qa = ha->next;//qa指向a当前正在处理的结点 还可以充当临时变量 反正有ha 只要qa=ha->hext;就可以摆回来
	ListNode* qb = hb->next;//qb指向b当前正在处理的结点 还可以充当临时变量 反正有hb 只要qb=hb->hext;就可以摆回来
	while (qa&&qb)
	{
		polynode aa, bb;
		aa = qa->data;
		bb = qb->data;
		if (aa.expn<bb.expn)//a的指数比b的指数小，保留当前qa结点，处理下一个
		{
			ha = qa;//qa和qa前面部分已经处理完毕
			qa = qa->next;
			continue;
		}
		if (aa.expn>bb.expn)//a的指数比b的大，不移动qa，把qb代表的往qa前面一个塞（即ha和qa之间），qb再往后移动，以便于下一次比较
		{
			b.delFirst(hb, qb);//从b链拿出来qb
			a.insFirst(ha, qb);//把qb塞进a链前一个
			qb = hb->next;//qb指向已处理的链表部分的尾部的下一个 方便下一轮处理
			ha = ha->next;//a链已处理的部分多了一节
			continue;
		}
		if (aa.expn == bb.expn)//指数相同，合并即可
		{
			float sum = aa.coef + bb.coef;
			if (sum != 0.0)
			{
				qa->data.coef = sum;
				ha = qa;
			}
			else//合并后大小为0
			{
				a.delFirst(ha, qa);
				delete qa;//拿出去就不要啦
			}
			b.delFirst(hb, qb);//拿出来qb 
			delete qb;//也不要了
			qb = hb->next;
			qa = ha->next;
		}
	}
	/*如果b链比较长 链接b链中的未处理部分*/
	if (!b.LL_empty())
	{
		int c = b.len;
		ListNode* ea;
		ea = a.LL_index(a.len);
		if (ea == NULL)
		{
			ea = a.head;
		}//如果ea取不到值 证明目前a是空链表 a.len=0；
		ea->next = b.head->next;
		a.len = a.len + c;
		delete b.head;
	}
}
void mono_mul_mono(LinkList a, LinkList b, LinkList &c)//单项式乘以单项式 返回给c
{
	ListNode* p = a.head->next;
	ListNode* q = b.head->next;
	ListNode* s = new ListNode();
	s->data.coef = (p->data.coef)*(q->data.coef);//系数相乘
	s->data.expn = (p->data.expn) + (q->data.expn);//指数相加
	c.LL_insert(1, s->data);
	delete s;
}
void poly_mul_mono(LinkList a, LinkList b, LinkList &c)//多项式a乘以单项式b 返回给c
{
	int i;
	LinkList *tmp = new LinkList[a.len];//存储a拆解的结果
	LinkList *mul = new LinkList[a.len];//存储每一项相乘的结果
	for (i = 0; i<a.len; i++)
	{
		tmp[i].LL_insert(1, a.LL_get(i + 1));
		mono_mul_mono(tmp[i], b, mul[i]);
	}
	for (i = 0; i<a.len; i++)
	{
		addPolyn(c, mul[i]);
	}
	delete[] tmp;
	delete[] mul;
}
void poly_mul_poly(LinkList a, LinkList b,LinkList &c)//多项式a乘以多项式b 返回给c
{
	int i;
	LinkList *tmp = new LinkList[b.len];//拆解b的结果
	LinkList *mul = new LinkList[b.len];//存储b每一项与a相乘结果
	for (i = 0; i<b.len; i++)
	{
		tmp[i].LL_insert(1, b.LL_get(i + 1));
		poly_mul_mono(a, tmp[i], mul[i]);
	}
	for (i = 0; i<b.len; i++)
	{
		addPolyn(c, mul[i]);
	}
	delete[] tmp;
	delete[] mul;
}

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		LinkList a, b,c;
		cin >> n;
		CreatePolyn(a, n);
		cin >> m;
		CreatePolyn(b, m);
		a.LL_display();
		b.LL_display();
		poly_mul_poly(a, b, c);
		c.LL_display();
	}
	return 0;
}