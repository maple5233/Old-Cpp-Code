#include<stdio.h>  
#include<stdlib.h>  
#include<malloc.h>  

typedef struct _node
{
	struct _node* prev;
	struct _node* next;
	int number;
}node, *linklist;

linklist create(int n);
void joseph(linklist head, int k, int m);

int main()
{
	linklist head;
	int m, n, k;
	printf("please input n:");
	scanf("%d", &n);
	printf("please input m:");
	scanf("%d", &m);
	printf("please input k:");
	scanf("%d", &k);
	head = create(n);
	printf("the sequences of leaving the list are:");
	joseph(head, k, m);
	return 0;
}
linklist create(int n)
{
	linklist head = (linklist)malloc(sizeof(node));
	node *tail;
	int i;
	head->next = head;
	head->prev = head;
	head->number = 1;
	tail = head;
	for (i = 2; i <= n; i++)
	{
		node *p = (node*)malloc(sizeof(node));
		p->number = i;
		p->next = tail->next;
		p->prev = tail;
		tail->next = p;
		tail = p;
		head->prev = tail;
	}
	return head;
}

void joseph(linklist head, int k, int m)
{
	int i;
	node *p;
	node *q;
	p = head;
	for (i = 1; i<k; i++)//��ȡ��ʼ�����Ľ��  
		p = p->next;
	while (head->next != head)
	{
		for (i = 1; i<m; i++)
			p = p->next;//��ȡÿ�ּ����ĵ�m����㣬����ɾ�����  
		q = p->next;
		q->prev = p->prev;
		p->prev->next = q;
		printf("%d ", p->number);
		if (p == head)//���ɾ�����ǵ�һ����㣬����Ҫ��������headָ��  
			head = q;
		free(p);
		p = q;//ɾ��һ�����֮�󣬴Ӹý�����һ��������¿�ʼ����  
	}
	printf("%d\n", head->number);
}