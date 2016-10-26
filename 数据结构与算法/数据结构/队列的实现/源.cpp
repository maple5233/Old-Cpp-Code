#include<iostream>
#define maxsize 10
using namespace std;
class Myqueue
{
public:
	Myqueue()
	{
		head = 0;
		tail = 0;
	}
	bool isEmpty()
	{
		int size = head - tail;
		if (size == 0)
			return true;
		return false;
	}
	int getHead()
	{
		if (!isEmpty())
		{
			return data[head];
		}
		else
		{
			return 0;
		}
	}
	bool Out_queue(int &del)
	{
		if (!isEmpty() && head != 0)
		{
			del = getHead();
			head = (head + 1) % maxsize;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool In_queue(int ins)
	{
		if ((tail + 1) % maxsize == head)
			return false;
		else
		{
			data[tail] = ins;
			tail = (tail + 1) % maxsize;
			return true;
		}
	}
	void display()
	{
		for (int i = head;; i++)
		{
			if (i == tail)
			{
				cout << endl;
				break;
			}
			else if (i == maxsize)
			{
				cout << data[maxsize] << ' ';
				i = -1;
				continue;
			}
			else
			{
				cout << data[i] << ' ';
				continue;
			}
		}
	}
private:
	int head;
	int tail;
	int data[maxsize];
};
int main()
{
	Myqueue quene;
	quene.In_queue(1);
	quene.In_queue(3);
	quene.In_queue(2);
	quene.In_queue(4);
	quene.In_queue(5);
	quene.display();
	system("pause");
	return 0;
}

