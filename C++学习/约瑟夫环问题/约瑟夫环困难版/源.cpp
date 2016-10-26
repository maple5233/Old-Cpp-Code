/*
编号为1，2… n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
一开始任选一个正整数作为报数的上限值m，从第一个人开始按顺时针方向自1开始顺序报数，
报到m时停止报数，报m的人出列，将他的密码作为新的m值，从他的顺时针方向上的下一个开始重新从1报数，如此下去，
直至所有人全部出列为止，设计一个程序求出出列顺序。
*/
#include<iostream>
#include<limits.h>
#include<string>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
struct Node
{
	int index;
	int passWord;
	struct Node* next;
};
Node* Create(int n)
{
	int i, pass;
	Node* head;//头
	Node* tail;//尾
	head = tail = new Node;
	cout << "输入每个人的密码：" << endl;
	for (i = 1; i<n; i++)
	{
		tail->index = i;
		cin >> pass;
		tail->passWord = pass;
		tail->next = new Node;
		tail = tail->next;
	}
	tail->index = i;
	cin >> pass;
	tail->passWord = pass;
	tail->next = head;
	return head;
}
void Josephu(Node* head, int passWord)
{
	int i, j=1;
	Node* tail =head->next;
	while (tail->next!=head)
	{
		tail = tail->next;
	}//找到尾巴
	while (tail != head)//两个人或以上
	{
		for (i = 1; i < passWord; i++)
		{
			head = head->next;
			tail = tail->next;
		}//数数 移动头和尾
		tail->next = head->next;//head出列
		cout << "第" << j << "个出列的人的序号是" << head->index << endl;
		j++;
		passWord = head->passWord;
		delete head;//释放head
		head = tail->next;
	}
	cout << "第" << j<< "个出列的人的序号是" << head->index << endl;
	delete head;
}
int main()
{
	int n, passWord;
	Node* head = NULL;
	cout << "输入初始密码和人数：" << endl;
	cin >> passWord >> n;
	head = Create(n);
	Josephu(head, passWord);
	system("pause");
	return 0;
}