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
	for (i = 1; i<k; i++)//获取开始计数的结点  
		p = p->next;
	while (head->next != head)
	{
		for (i = 1; i<m; i++)
			p = p->next;//获取每轮计数的第m个结点，即待删除结点  
		q = p->next;
		q->prev = p->prev;
		p->prev->next = q;
		printf("%d ", p->number);
		if (p == head)//如果删除的是第一个结点，则需要重新设置head指针  
			head = q;
		free(p);
		p = q;//删除一个结点之后，从该结点的下一个结点重新开始计数  
	}
	printf("%d\n", head->number);
}