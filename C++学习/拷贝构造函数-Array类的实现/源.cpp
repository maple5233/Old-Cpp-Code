#include<iostream>
using namespace std;
class Array
{
private:
	int* a;
	int size;
public:
	Array();
	Array(int usize);
	Array(const Array &b);
	~Array();
	void input();
	void output();
	void sort();
	void insert(int value);
	void mdelete(int index);
};
Array::Array()
{
	size = 10;
	a = new int[size];
	cout << "Constructor." << endl;
}
Array::Array(int usize)
{
	size = usize;
	a = new int[size];
	cout << "Constructor." << endl;
}
Array::Array(const Array &b)
{
	size = b.size;
	a = new int[size];
	cout << "Constructor." << endl;
}
Array::~Array()
{
	delete[] a;
	cout << "Distructor." << endl;
}
void Array::input()
{
	int i;
	for (i = 0 ; i < size; i++)
		cin >> *(a + i);
}
void Array::output()
{
	int i;
	for (i = 0; i < size-1; i++)
		cout << *(a + i)<<' ';
	cout << *(a + size - 1) << endl;
}
void Array::sort()
{
	int i, j, temp;
	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - 1 - j; i++)
		{
			if ( *(a+i) > *(a+i + 1) )
			{
				temp = *(a + i);
				*(a + i) = *(a + i + 1);
				*(a + i + 1) = temp;
			}
		}
	}
}
void Array::insert(int value)
{
	int i;
	int *t=NULL;
	size = size + 1;
	t = new int[size];
	for (i = 0; i <= size - 2; i++)
	{
		*(t + i) = *(a + i);
	}
	*(t + size - 1) = value;
	delete []a;
	a = t;
	sort();
}
void Array::mdelete(int index)
{
	int i;
	int *t = NULL;
	size = size - 1;
	t = new int[size];
	for (i = 0; i <= index - 1; i++)
	{
		*(t + i) = *(a + i);
	}
	for (i = index; i < size; i++)
	{
		*(t + i) = *(a + i+1);
	}
	delete []a;
	a = t;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int s;
		cin >> s;
		Array one(s);
		int m, n;
		one.input();
		one.sort();
		cin >> m >> n;
		cout << "after sort:";
		one.output();
		one.insert(m);
		cout << "after insert:";
		one.output();
		one.mdelete(n);
		cout << "after delete:";
		one.output();
	}
	return 0;
}