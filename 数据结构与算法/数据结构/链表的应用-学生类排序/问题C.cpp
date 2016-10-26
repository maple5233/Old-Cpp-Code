/*
题目描述

首先看看教材第十章第11例题如下：
 #include <iostream.h>
struct Student
{
 long number;
 float score;
 Student* next;
};
 
Student* head;    //链首指针
 
Student* Create()
{
 Student* pS;        //创建的结点指针
 Student* pEnd;      //链尾指针，用于在其后面插入结点
 pS=new Student;     //新建一个结点，准备插入链表
 cin >>pS->number >>pS->score;    //给结点赋值
 head=NULL;          //一开始链表为空
 pEnd=pS;
 while(pS->number!=0){
    if(head==NULL)
      head=pS;
    else
      pEnd->next=pS;
 
    pEnd=pS;        //s点
    pS=new Student;
    cin >>pS->number >>pS->score;
 }
 pEnd->next=NULL;
 delete pS;
 return(head);
}
 
void ShowList(Student* head)
{
 cout <<"now the items of list are \n";
 
 while(head){
    cout <<head->number <<"," <<head->score <<endl;
    head=head->next;
 }
}
 
void main()
{
 ShowList(Create());
}
在例题的基础上，做适当修改，建立一个具有n个节点(Node)的单向链表，每个节点包含一个整形数值和一个指向本节点类型后向指针，
对该链表按照升序进行排序（定义一个排序函数，void sort(Student *)，采用冒泡算法），输出排序的结果。（注意输入、输出格式！）

输入

输入链表中各节点的整数值

输出

输出排序后链表中各节点的整数值

样例输入

34 5 66 89 2 6 77 0

样例输出

2 5 6 34 66 77 89
*/


#include <iostream>
using namespace std;
int sum = 0;
struct Student
{
	int number;
	Student* next;
};

Student* head;

Student* Create()
{
	Student* pS;
	Student* pEnd;
	pS = new Student;
	cin >> pS->number;
	head = NULL;
	pEnd = pS;
	while (pS->number != 0){
		if (head == NULL)
			head = pS;
		else
			pEnd->next = pS;

		pEnd = pS;
		pS = new Student;
		cin >> pS->number;
		sum++;
	}
	pEnd->next = NULL;
	return(head);
}
void sort(Student *p)
{
	int i, j, temp;
	Student *q;
	for (i = 1; i<sum; i++)
	{
		for (j = 0; j<sum - i; j++)
		{
			q = p->next;
			if (p->number>q->number)
			{
				temp = p->number;
				p->number = q->number;
				q->number = temp;
			}
			p = p->next;
		}
		p = head;
	}
}

void ShowList(Student* head)
{
	while (head->next != 0){
		cout << head->number << " ";
		head = head->next;
	}
	cout << head->number << endl;
}

int main()
{
	sort(Create());
	ShowList(head);
	return 0;
}