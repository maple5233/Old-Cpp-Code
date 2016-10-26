#include<iostream>
using namespace std;
#include <iostream> 
using namespace std;
#define ok 1 
#define error 0 

class polynode
{
public:
	int expn; //ָ��
	float coef;//ϵ��
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
	ListNode* LL_index(int i)//��λ�û�ȡ���ָ����
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
	polynode LL_get(int i)//��λ�û�ȡ���������
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
	int LL_insert(int i, polynode item)//���뺯��
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
			if (p->data.expn<0)//�����ǳ�����
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
			if ((p->data.expn == 0) && (p->data.coef<0.0))//������ ����
			{
				cout << '(' << p->data.coef << ')' << " + ";
			}
			if ((p->data.expn == 0) && (p->data.coef>0.0))//������ ����
			{
				cout << p->data.coef << " + ";
			}
			if (p->data.expn>0)//�����ǳ�����
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
	void delFirst(ListNode *p, ListNode *q)//ɾ��pָ�����һ����㣬���Ұ������㸳��q ��ȡ�����
	{
		q->next = p->next->next;
		q->data = p->next->data;
		p->next = p->next->next;
		len--;
	}
	void insFirst(ListNode *p, ListNode *q)//�ڽ��p����һ������һ����� ʹ�ý������������q�������� ��������
	{
		ListNode* s = new ListNode();
		s->data = q->data;
		s->next = p->next;
		p->next = s;
		len++;
	}
};

void CreatePolyn(LinkList &P, int m)//����һԪ����ʽ����P ����Ϊm
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

void addPolyn(LinkList &a, LinkList &b)//����ʽ���
{
	ListNode* ha = a.head;//ha����ָ��a���һ��������Ľ�� Ҳ����a���д�����ɲ��ֵ����һ��
	ListNode* hb = b.head;//hb����ָ��b���һ��������Ľ�� Ҳ����b���д�����ɲ��ֵ����һ��
	ListNode* qa = ha->next;//qaָ��a��ǰ���ڴ���Ľ�� �����Գ䵱��ʱ���� ������ha ֻҪqa=ha->hext;�Ϳ��԰ڻ���
	ListNode* qb = hb->next;//qbָ��b��ǰ���ڴ���Ľ�� �����Գ䵱��ʱ���� ������hb ֻҪqb=hb->hext;�Ϳ��԰ڻ���
	while (qa&&qb)
	{
		polynode aa, bb;
		aa = qa->data;
		bb = qb->data;
		if (aa.expn<bb.expn)//a��ָ����b��ָ��С��������ǰqa��㣬������һ��
		{
			ha = qa;//qa��qaǰ�沿���Ѿ��������
			qa = qa->next;
			continue;
		}
		if (aa.expn>bb.expn)//a��ָ����b�Ĵ󣬲��ƶ�qa����qb�������qaǰ��һ��������ha��qa֮�䣩��qb�������ƶ����Ա�����һ�αȽ�
		{
			b.delFirst(hb, qb);//��b���ó���qb
			a.insFirst(ha, qb);//��qb����a��ǰһ��
			qb = hb->next;//qbָ���Ѵ���������ֵ�β������һ�� ������һ�ִ���
			ha = ha->next;//a���Ѵ���Ĳ��ֶ���һ��
			continue;
		}
		if (aa.expn == bb.expn)//ָ����ͬ���ϲ�����
		{
			float sum = aa.coef + bb.coef;
			if (sum != 0.0)
			{
				qa->data.coef = sum;
				ha = qa;
			}
			else//�ϲ����СΪ0
			{
				a.delFirst(ha, qa);
				delete qa;//�ó�ȥ�Ͳ�Ҫ��
			}
			b.delFirst(hb, qb);//�ó���qb 
			delete qb;//Ҳ��Ҫ��
			qb = hb->next;
			qa = ha->next;
		}
	}
	/*���b���Ƚϳ� ����b���е�δ������*/
	if (!b.LL_empty())
	{
		int c = b.len;
		ListNode* ea;
		ea = a.LL_index(a.len);
		ea->next = b.head->next;
		a.len = a.len + c;
		delete b.head;
	}
}
void cPolyn(LinkList &a, LinkList &b)//����һ��˼· ���b һ��һ���
{
	int i;
	LinkList *tmp = new LinkList[b.len];
	for (i = 0; i<b.len; i++)
	{
		tmp[i].LL_insert(1, b.LL_get(i + 1));
	}
	for (i = 0; i<b.len; i++)
	{
		addPolyn(a, tmp[i]);//ʡȥ��д����ʽ+����ʽ�� ֻ�Ǹ�˼·���� ���ö���ʽ�Ӷ���ʽ��
	}
	delete[] tmp;
}

int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		LinkList a, b;
		cin >> n;
		CreatePolyn(a, n);
		cin >> m;
		CreatePolyn(b, m);
		a.LL_display();
		b.LL_display();
		addPolyn(a, b);
		a.LL_display();
	}
	return 0;
}