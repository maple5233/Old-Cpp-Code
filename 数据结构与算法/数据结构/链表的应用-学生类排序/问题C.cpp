/*
��Ŀ����

���ȿ����̲ĵ�ʮ�µ�11�������£�
 #include <iostream.h>
struct Student
{
 long number;
 float score;
 Student* next;
};
 
Student* head;    //����ָ��
 
Student* Create()
{
 Student* pS;        //�����Ľ��ָ��
 Student* pEnd;      //��βָ�룬����������������
 pS=new Student;     //�½�һ����㣬׼����������
 cin >>pS->number >>pS->score;    //����㸳ֵ
 head=NULL;          //һ��ʼ����Ϊ��
 pEnd=pS;
 while(pS->number!=0){
    if(head==NULL)
      head=pS;
    else
      pEnd->next=pS;
 
    pEnd=pS;        //s��
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
������Ļ����ϣ����ʵ��޸ģ�����һ������n���ڵ�(Node)�ĵ�������ÿ���ڵ����һ��������ֵ��һ��ָ�򱾽ڵ����ͺ���ָ�룬
�Ը�����������������򣨶���һ����������void sort(Student *)������ð���㷨�����������Ľ������ע�����롢�����ʽ����

����

���������и��ڵ������ֵ

���

�������������и��ڵ������ֵ

��������

34 5 66 89 2 6 77 0

�������

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