#include<iostream>
using namespace std;
class myStack
{
private:
	int *a;
	int top;
	int length;
	int content;
public:
	myStack(int content)
	{
		top = -1;
		length = 0; 
		this->content = content;
		a = new int[content];
	}
	~myStack()
	{
		delete[] a;
	}
	bool push(int data)
	{
		if (top == content - 1)
		{
			return false;
		}
		else
		{
			top++;
			*(a + top) = data;
			length++;
			return true;
		}
	}
	bool pop()
	{
		if (top == 1)
		{
			return false;
		}
		else
		{
			top--;
			length--;
			return true;
		}
	}
	bool pop(int &data)
	{
		if (top == 1)
		{
			return false;
		}
		else
		{
			data = *(a + top);
			top--;
			length--;
		}
	}
	bool getTop(int &data)
	{
		if (top == -1)
		{
			cout << "Error:栈空！无法读取！" << endl;
			return false;
		}
		else
		{
			data = *(a + top);
			return true;
		}
	}
	bool isEmpty()
	{
		return (top == -1) ? true : false;
	}
	int getLength(){ return length; }
	void display()
	{
		int i;
		for (i = 0; i < length; i++)
		{
			cout << *(a + i) << ' ';
		}
		cout << endl;
	}
};
int main()
{
	int content, i, tmp;
	cin >> content;
	myStack stack(content);
	for (i = 0; i < content; i++)
	{
		cin >> tmp;
		if (!stack.push(tmp))
		{
			cout << "Error:栈已经满了(上溢出)！无法插入！" << endl;
		}
	}
	stack.display();
	if (!stack.pop())
	{
		cout << "Error:栈是空的(下溢出)！无法弹出！" << endl;
	}
	stack.display();
	system("pause");
}