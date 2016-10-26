#include<iostream>  
#include<list>  
using namespace std;

void joseph(int n, int m, int k);

int main()
{
	int n, m, k;
	cout << "please input n:";
	cin >> n;
	cout << "please input m:";
	cin >> m;
	cout << "please inpur k:";
	cin >> k;
	cout << "the sequences of leaving the list are:";
	joseph(n, m, k);
	system("pause");
	return 0;
}

void joseph(int n, int m, int k)
{
	list<int> numbers;
	int i, j;
	for (i = 1; i <= n; i++)
		numbers.push_back(i);
	list<int>::iterator current = numbers.begin();
	list<int>::iterator next;
	for (i = 1; i<k; i++)
	{
		++current;
		if (current == numbers.end())
			current = numbers.begin();
	}
	while (numbers.size()>1)
	{
		for (i = 1; i<m; i++)
		{
			++current;
			if (current == numbers.end())
				current = numbers.begin();
			/*
			由于list本身并不是一个循环链表，所以每当到达
			最后一个元素的下一个位置时，需要修改迭代器指向第一个元素
			*/
		}
		next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		--current;
		cout << *current << " ";
		numbers.erase(current);
		current = next;
	}
	cout << *current << endl;
}