#include<iostream>
#include<stack>
#define dataType int
using namespace std;
class MyQueue
{
public:
	void push(dataType data);
	void pop();
	int count();
	void show();
	bool isEmpty();
	dataType front();
private:
	stack<dataType> stackForPush;
	stack<dataType> stackForPop;
	void dump();// ��stackForPushԪ�ص���stackForPop;
};
void MyQueue::dump()
{
	while (!this->stackForPush.empty())
	{
		this->stackForPop.push(this->stackForPush.top());
		this->stackForPush.pop();
	}
}
void MyQueue::push(dataType data)
{
	this->stackForPush.push(data);
	cout << "����" << data << '\t';
	this->show();
}
void MyQueue::pop()
{
	if (!this->stackForPop.empty())
	{
		cout << "����" << this->stackForPop.top() << '\t';
		this->stackForPop.pop();
		this->show();
	}
	else if (!this->stackForPush.empty())
	{
		this->dump();
		cout << "����" << this->stackForPop.top() << '\t';
		this->stackForPop.pop();
		this->show();
	}
	else
	{
		cout << "�������" << endl;
	}
}
int MyQueue::count()
{
	return this->stackForPop.size() + this->stackForPush.size();
}
bool MyQueue::isEmpty()
{
	return !this->count();
}
dataType MyQueue::front()
{
	this->dump();
	return this->stackForPop.top();
}
void MyQueue::show()
{
	if (this->isEmpty())
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	cout << "��ǰ����Ϊ��";

	this->dump();
	while (!this->stackForPop.empty())
	{
		this->stackForPush.push(stackForPop.top());
		cout << this->stackForPop.top() << " ";
		this->stackForPop.pop();
	}

	cout << '\t' << "���г���Ϊ" << this->count() << endl;
}
int main()
{
	MyQueue q;
	q.push(1);
	cout << endl;
	q.push(2);
	cout << endl;
	q.push(3);
	cout << endl;
	q.pop();
	cout << endl;
	q.pop();
	cout << endl;
	q.pop();
	cout << endl;
	q.pop();
	cout << endl;
	system("pause");
	return 0;
}