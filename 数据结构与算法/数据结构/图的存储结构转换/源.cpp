#include <iostream>
using namespace std;
class Node
{
public:
	char data;
};
class Edge
{
public:
	int weight;//权重;
	Edge(int w = 9999)
	{
		weight = w;
	}
};
class Graph
{
public:
	int n, e;//n为点数，e为边数;
	Edge* E[20][20];//邻接矩阵;
	Node* N[20];//点集;
public:
	Graph()
	{
		int i, j;
		n = e = 0;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				E[i][j] = NULL;
		}
		for (i = 0; i < 20; i++)
		{
			N[i] = NULL;
		}
	}
	int getIndex(char c)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (N[i]->data==c)
				break;
		}
		return i;
	}
	char getData(int i)
	{
		return N[i]->data;
	}
	bool insertE(int i,int j)
	{
		if (E[i][j])
			return false;
		E[i][j] = new Edge(1);//创建新边;
		return true;
	}
	void initByCin()
	{
		char a, b;
		int i;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			N[i] = new Node();
			cin >> N[i]->data;
		}
		cin >> e;
		for ( i = 0; i < e; i++)
		{
			cin >> a >> b;
			insertE(getIndex(a), getIndex(b));
		}
	}
	void initByJZ()
	{
		int i,j;
		e = 0;
		int tmp;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				E[i][j] = NULL;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> tmp;
				if (tmp)
				{
					E[i][j] = new Edge(1);
					e++;
				}
			}
		}
	}
	void display1()
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n-1; j++)
			{
			
				if (E[i][j])
				{
					cout << 1 << ' ';
				}
				else
				{
					cout << 0 << ' ';
				}
			}
			if (E[i][j])
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 <<endl;
			}
		}
	}
	void display2()
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			cout << getData(i) << ':';
			for (j = 0; j < n; j++)
			{
				if (E[i][j])
				{
					cout << "->"<< getData(j);
				}
			}
			cout << '^' << endl;
		}
	}
	void display3()
	{
		int i;
		for (i = 0; i < n-1; i++)
			cout << getData(i) << ' ';
		cout << getData(i) <<endl;
	}
};
int main()
{
	Graph g;
	g.initByCin();
	g.display3();
	g.display1();
	g.initByJZ();
	g.display2();
	//system("pause");
	return 0;
}