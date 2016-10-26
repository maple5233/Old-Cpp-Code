#include <iostream>
using namespace std;
class Node
{
public:
	char data;
	Node* lChild;
	Node* rChild;
};
class VTree
{
private:
	char* N;
	int size;
	int treeHigh;
public:
	VTree()
	{
		N = NULL;
		size = 0;
		treeHigh = 0;
	}
	void init(int size)
	{
		int i;
		this->size = size;
		N = new char[size + 1];
		N[0] = 99;
		for (i = 1; i <= size; i++)
		{
			cin >> N[i];
		}
	}
	void travPost(int index)
	{
		if (index > size)
			return;//µÝ¹é»ù;
		travPost(2 * index);
		travPost(2 * index + 1);
		if (N[index] != '0')
			cout << N[index] << ' ';
	}
	int getHigh(int index)
	{
		int high = 0;
		if (index > size)
		{
			return 0;//µÝ¹é»ù;
		}
		int a, b;
		a = getHigh(2 * index);
		b = getHigh(2 * index + 1);
		high = a > b ? a : b;
		high++;
		return high;
	}
	void showHigh()
	{
		treeHigh = getHigh(1);
		cout << treeHigh << endl;
	}
};
int main()
{
	//int T,size;
	//cin >> T;
	//while (T--)
	//{
	int size;
	cin >> size;
	VTree v;
	v.init(size);
	v.showHigh();
	v.travPost(1);
	//}
}