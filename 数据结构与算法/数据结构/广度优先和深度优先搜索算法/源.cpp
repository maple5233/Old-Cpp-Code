#include <iostream>
#include <stack>
#include <queue>
enum STATUS{ UNFOUND, VISITED };
using namespace std;
class Node
{
public:
	char data;
	STATUS st;
	Node()
	{
		st = UNFOUND;
	}
};
class Edge
{
public:
	int weight;//Ȩ��;
	Edge(int w = 9999)
	{
		weight = w;
	}
};
class Graph
{
public:
	int n, e;//nΪ������eΪ����;
	Edge* E[20][20];//�ڽӾ���;
	Node* N[20];//�㼯;
	void BFS(int s)
	{
		queue<int> Q;
		int v, u;
		Q.push(s);
		N[s]->st = VISITED;
		while (!Q.empty())
		{
			v = Q.front();
			Q.pop();
			

			for (u = firstNbr(v); u < n; u = getNBR(v, u))
			{
				if (N[u]->st==UNFOUND)
				{
					N[u]->st = VISITED;
					Q.push(u);
				}
			}

			if (!Q.empty())
			{
				cout << N[v]->data << ' ';
			}
			if (Q.empty())
			{
				cout << N[v]->data;
			}
		}
	}
	void DFS(int s)
	{
		int v = s;
		int u;
		N[s]->st = VISITED;
		cout <<N[s]->data<< ' ';
		for (u = firstNbr(v); u < n;u=getNBR(v,u))
		{
			if (N[u]->st==UNFOUND)
			{
				DFS(u);
			}
		}
	}
public:
	Graph()
	{
		int i, j;
		n = e = 0;
		for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			E[i][j] = NULL;
		for (i = 0; i < 20; i++)
			N[i] = NULL;
	}
	int getIndex(char c)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (N[i]->data == c)
				break;
		}
		return i;
	}
	char getData(int i)
	{
		return N[i]->data;
	}
	bool insertE(int i, int j)
	{
		if (E[i][j])
			return false;
		E[i][j] = new Edge(1);//�����±�;
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
		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			insertE(getIndex(a), getIndex(b));
		}
	}
	void initByJZ()
	{
		int i, j;
		e = 0;
		int tmp;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			N[i] = new Node();
			N[i]->data = '0' + i;
		}
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
	bool exist(int i, int j)
	{
		return (0 <= j) && (0 <= i) && (i < n) && (j < n) && (E[i][j]);
	}
	int getNBR(int i, int j) // ���Ѿ�ö�ٵ�����i���ھ�j ö����һ��i���ھ�;
	{
		while ((n>j) && !exist(i, ++j));
		return j;
	}
	int firstNbr(int i)//ö�ٵ�i�ĵ�һ���ھӣ���i�е�����);
	{
		return(getNBR(i, -1));
	}
	bool hasNbr(int i)
	{
		if (firstNbr(i) == n)
			return false;
		return true;
	}
	void bfs(int s)
	{//ȫͼ�����������;
		reset();
		int v = s;
		BFS(v);
		do
		{
			if (UNFOUND == N[v]->st)
			{
				cout << ' ';
				BFS(v);
			}
			v = v++;
			v = v%n;
		} while (s != v);
		cout << endl;
	}
	void dfs(int s)
	{//ȫͼ�����������;
		reset();
		int v = s;
		do 
		{
			if (UNFOUND == N[v]->st)
			{
				DFS(v);
			}
			v++;
			v = v%n;
		} while (v!=s);
		cout << endl;
	}
	void reset()
	{
		int i;
		for (i = 0; i < n;i++)
		{
			N[i]->st = UNFOUND;
		}
	}
};
int main()
{
	Graph g;
	g.initByCin();
	g.bfs(0);
	//system("pause");
	return 0;
}