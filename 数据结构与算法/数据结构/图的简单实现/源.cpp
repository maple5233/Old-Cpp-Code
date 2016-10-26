#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
#define datatype int
typedef enum { UNDISCOVERD, DISCOVERD, VISITED, DELETED } VStatus;//顶点的四种状态
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD }Etype;//边的类型：未定义，支撑树边，跨边，前向边，后向边

vector<datatype> out;
queue<datatype> out2;


class Vertex//顶点类
{
public:
	datatype data;//数据域
	int no;//编号
	VStatus status;//状态
	int dtime, ftime;//遍历中的时间标签
	int parent;//遍历中的父节点
	int inDegree, outDegree;//入度和出度
	Vertex(datatype d = 0)
	{
		data = d;
		parent = -1;
		no = 0;
		dtime = -1;
		ftime = -1;
		status = UNDISCOVERD;
		inDegree = 0;
		outDegree = 0;
	}
};
class Edge
{
public:
	int weight;//权重
	Etype type;//分类
	Edge(int w = 9999)
	{
		weight = w;
		type = UNDETERMINED;
	}
};
class Graph
{
private:
	void reset()
	{//辅助信息复位
		int i, j;
		for (i = 0; i < n; i++)
		{
			V.at(i).status = UNDISCOVERD;
			V.at(i).dtime = V.at(i).ftime = -1;
			V.at(i).parent = -1;
			for (j = 0; j < n; j++)
			{
				if (E[i][j] != NULL)
				{
					E[i][j]->type = UNDETERMINED;
				}
			}
		}
	}
	void BFS(int v, int &clock)//连通域广度优先搜索
	{
		queue<int> Q;
		int u;

		V[v].status = DISCOVERD;
		Q.push(v);
		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			V[v].dtime = ++clock;
			for (u = firstNbr(v); u < n; u = nextNbr(v, u))//枚举所有邻居
			{
				if (UNDISCOVERD == V[u].status)
				{
					V[u].status = DISCOVERD;
					Q.push(u);
					E[v][u]->type = TREE;
					V[u].parent = v;
				}
				else
				{
					E[v][u]->type = CROSS;
				}
			}
			cout << V[v].data << ' ';//访问之
			V[v].ftime = clock;
			V[v].status = VISITED;
		}
	}
	void DFS(int v, int &clock)//连通域深度优先搜索
	{
		int u;
		V[v].dtime = ++clock;
		V[v].status = DISCOVERD;//先序发现之
		out2.push(V[v].data);//先序随即访问之
		for (u = firstNbr(v); u < n; u = nextNbr(v, u))
		{
			switch (V[u].status)
			{
			case UNDISCOVERD://扩展支撑树
				E[v][u]->type = TREE;
				V[u].parent = v;
				//cout << "v->" <<v;
				//cout << "u->" <<u ;
				DFS(u, clock);
				break;//递归
			case DISCOVERD://u已经被发现但没被访问 应该属于被后代指向的祖先
				E[v][u]->type = BACKWARD; break;
			default://u已经被访问完毕
				E[v][u]->type = (V[v].dtime < V[u].dtime) ? FORWARD : CROSS; break;
			}
		}
		V[v].status = VISITED;//后序标记访问过程结束
		V[v].ftime = ++clock;
	}
	bool TSortSmall(int v, int& clock, stack<datatype>& S)
	{
		int u;
		V[v].dtime = ++clock;
		V[v].status = DISCOVERD;
		for (u = firstNbr(v); u < n; u = nextNbr(v, u))
		{
			switch (V[u].status)
			{
			case UNDISCOVERD://扩展支撑树
				E[v][u]->type = TREE;
				V[u].parent = v;
				if (!TSortSmall(u, clock, S))//如果后代失败了 就整个失败了
				{
					return false;
				}
				break;//递归
			case DISCOVERD://u已经被发现但没被访问 应该属于被后代指向的祖先 存在这样的边说明不是DAG
				E[v][u]->type = BACKWARD;
				return false;//不必深入 返回报告失败
			default://u已经被访问完毕
				E[v][u]->type = (V[v].dtime < V[u].dtime) ? FORWARD : CROSS; break;
			}
		}
		V[v].status = VISITED;//标记访问过程结束
		S.push(V[v].data);//标记即可入栈
		V[v].ftime = ++clock;
		return true;//v及其后代排序成功
	}
	bool TSortBig(int v, queue<datatype>& Q)
	{

	}
public:
	/*基本属性*/
	vector<Vertex> V;//顶点集
	Edge* E[20][20];//边集 二维数组
	int n;//点的个数
	int e;//边的条数

	/*构造函数*/
	Graph()
	{
		int i, j;
		n = e = 0;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				E[i][j] = NULL;
		}
	}
	/*获取点的编号*/
	int getIndex(datatype c)//返回指定数据的编号
	{
		vector<Vertex>::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			if (it->data == c)
			{
				return it->no;
			}
		}
		return -1;//没有这个元素
	}
	int getIndexTwo(datatype c)//返回指定数据的下标
	{
		vector<Vertex>::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			if (it->data == c)
			{
				return it - V.begin();
			}
		}
		return -1;//没有这个元素
	}
	/*获取邻居*/
	bool exsit(int i, int j)//判断某条边是否存在
	{
		return (0 <= j) && (0 <= i) && (i < n) && (j < n) && (E[i][j]);
	}
	int nextNbr(int i, int j)//若已经枚举到到点i的邻居j 枚举下一个i的邻居
	{
		while ((n>j) && !exsit(i, ++j));
		return j;
	}
	int firstNbr(int i)//枚举点i的第一个邻居（在i行的行首）
	{
		return(nextNbr(i, -1));
	}
	bool hasNbr(int i)
	{
		if (firstNbr(i) == n)
			return false;
		return true;
	}
	/*初始化图;*/
	void initV()
	{//按照输入的n 初始化n个顶点 下标从0-(n-1) 数据从A开始到第n个字母
		//再输入e条边
		int i, n, e;
		datatype a, b;
		Vertex v('A' - 1);

		cin >> n;
		for (i = 0; i < n; i++)
		{
			v.no = i;
			v.data++;
			insertVertex(v);
		}

		cin >> e;
		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			insertEdge(getIndex(a), getIndex(b));
		}
	}
	void initVE()
	{//分别输入顶点和边;
		Vertex v;
		datatype a, b;
		int n, e, i;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			v.no = i;
			cin >> v.data;
			insertVertex(v);
		}

		cin >> e;
		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			insertEdge(getIndex(a), getIndex(b));
		}
	}
	void initVertex(int size)//用户直接输入邻接矩阵
	{
		int i, j, tmp;
		n = size;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				cin >> tmp;
				if (tmp == 1)
				{
					insertEdge(i, j);
					e++;
				}
			}
		}
		Vertex v;
		for (i = 0; i < size; i++)
		{
			v.no = i;
			v.data = i;
			insertVertex(v);
		}
		n = n / 2;
		e = e / 2;
	}
	void initWE(int size)
	{//构造带权图的邻接矩阵 没有的点权重被赋值为9999
		int i, j, tmp;
		n = size;

		Vertex v;
		for (i = 0; i < size; i++)
		{
			v.no = i;
			v.data = i;
			insertVertex(v);
		}

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				cin >> tmp;
				if (tmp>0)
				{
					insertEdge(i, j, tmp);
					e++;
				}
				else
				{
					insertEdge(i, j,9999);
				}
			}
		}
		
		n = n / 2;
		e = e / 2;
	}
	/*插入和删除;*/
	bool insertEdge(int i, int j, int w = 9999)//插入一条由i指向j的边 权重为w
	{
		if (E[i][j])
			return false;
		E[i][j] = new Edge(w);//创建新边 权重为w
		e++;
		V[i].outDegree++;
		V[j].inDegree++;
		return true;
	}
	void remove(int i)//删除点
	{
		vector<Vertex>::iterator it;
		it = V.begin() + i;

		int j;
		for (j = 0; j < n; j++)
		{
			if (exsit(i, j))
			{
				delete E[i][j];
				E[i][j] = NULL;
				V[j].inDegree--;
				e--;
			}//删除出边
		}

		//V.erase(it);//删除顶点
		it->status = DELETED;//删除顶点

		for (j = 0; j < n; j++)
		{
			if (E[j][i])
			{
				delete E[j][i];
				E[j][i] = NULL;
				V[j].outDegree--;
				e--;
			}
		}//删除入边
	}
	void remove(int i, int j)//删除边
	{
		delete E[i][j];
		E[i][j] = NULL;
		V[i].outDegree--;
		V[j].inDegree--;
		e--;
	}
	void insertVertex(Vertex v)//插入顶点v
	{
		n++;
		V.push_back(v);//点集中插入v
	}

	/*遍历与排序*/
	void bfs(int s)//全图广度优先搜索
	{//层次遍历
		int clock = 0;
		int v = s;
		do
		{
			if (UNDISCOVERD == V[v].status)
			{
				BFS(v, clock);
			}
		} while (s != (v = (++v) % n));
	}
	void dfs(int s)//全图深度优先搜索
	{//先序遍历discover 后序遍历visited
		int clock = 0;
		int v = s;
		do
		{
			if (UNDISCOVERD == V[v].status)
			{
				DFS(v, clock);
				while (out2.size() > 0)
				{
					cout << out2.front() << ' ';
					out2.pop();
				}
			}
		} while (s != (v = (++v) % n));
	}
	bool tSortSmall(int s, stack<datatype>& S)//关注极小点的拓扑排序 借助dfs框架 不需要考虑入度出度 
	{//各顶点被标记为VISITED的顺序（后序遍历） 恰好给出其中一种拓扑排序的逆序
		//这种方法不会破坏图结构 但是给出的拓扑排序 不一定会优先把小的排前面 不过一定是合法的拓扑排序
		int clock = 0;
		int v = s;
		do
		{
			if (UNDISCOVERD == V[v].status)
			{
				if (!TSortSmall(v, clock, S))//如果不是DAG
				{
					while (!S.empty())
					{
						S.pop();
					}//清空栈
					return false;//排序失败 S空
				}
			}
		} while (s != (v = (++v) % n));//v转一圈回到s
		return true;//若输入为DAG 则S内各顶点自顶向底排序
	}
	void tSortBig(int s, queue<datatype>& Q)//关注极大顶点 也就是入度为0的顶点 优先考虑小点 每次都摘除入度为0的顶点
	{//破坏了图结构 也无法判断是不是有向无环图
		Q.push(V.at(s).data);
		remove(s);//从s开始
		vector<Vertex>::iterator it;
		int num = n;
		while (num--)
		{
			for (it = V.begin(); it != V.end(); it++)
			{
				if (DELETED != it->status && it->inDegree == 0)
				{
					Q.push(it->data);
					remove(getIndex(it->data));
					break;
				}
			}
		}
	}
	/*其他*/
	void showAdjacencyList()//输出邻接表
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			cout << i << ' ' << V[i].data;
			if (hasNbr(i))
			{
				for (j = firstNbr(i); j < n; j = nextNbr(i, j))
				{
					cout << '-' << j;
				}
			}
			cout << "-^" << endl;
		}
	}
	void shortPath(int start)//构造顶点start开始的最小路径集 并输出之
	{
		int i, j, k, w, min, u,v;
		int P[20][20];//最短路径集
		int *D = new int[n];//记起点录到各个顶点的最小路径权值和（即实际长度、距离）
		bool* isFinal = new bool[n];//记录每个顶点是否已经达到选择终态
		int len[20];//记录每个最短路径的长度（即路径上的顶点的个数）

		/*初始化*/
		for (i = 0; i < n; i++)
		{
			D[i] = E[start][i]->weight;
			isFinal[i] = false;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				P[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			P[i][0] = start;//从0
			P[i][1] = i;//到i
			//记录起点和重点
			len[i] = 2;//最起始长度为2（起点和重点总共两个）
		}
		D[start] = 0;//起点到自己的长度为0
		isFinal[start] = true;//起点处理完毕

		/*主循环*/
		/*总共n-1趟*/
		/*第一趟*/

		//找出离上一次终点最近的顶点w(此时的“上一次的终点"即为起点start)
		min = 9999;
		for (u = 0; u < n; u++)
		{
			if (D[u] < min && isFinal[u] == false)
			{
				min = D[u];
				w = u;//对应顶点
			}
		}//找出离起点最小的 也就是D[]中最小的w
		isFinal[w] = true;//找到了加入已求集合 起点到w的距离已经求出 距离为min 
		//起点到w的路径已经加入了P[][]


		/*接下来有n-2趟*/

		//更新start到w再到其他顶点的距离(即更新下一趟循环需要的数据（表格的下一列）)
		//并找出离上一次终点w最近的顶点v（循环执行）
		for (k = 0; k < n - 2; k++)//接下来有n-2趟
		{
			for (i = 0; i<n; i++)
			{
				if (isFinal[i])
					continue;//跳过已经处理完毕的
				//D[i]取D[i]和min+E[w][i]->weight之中小的那个
				if (D[i] > min + E[w][i]->weight)//D[i]将缩小 起点到i的路径受到影响（因为发现走起点到w的这条路能缩短距离）
				{
					D[i] = min + E[w][i]->weight;//更新D[i] 
					/*拷贝起点到w的路径 再加一步走到i*/
					for (j = 0; j < len[w]; j++)
					{
						P[i][j] = P[w][j];
					}
					len[i] = len[w] + 1;
					P[i][len[w]] = i;
				}
			}//更新D[]的下一趟

			min = 9999;
			for (u = 0; u < n; u++)
			{
				if (D[u] < min && isFinal[u] == false)
				{
					min = D[u];
					v = u;//对应顶点
				}
			}//接着找出D[]最小的那个 也就是离w最近那个v作为新的w
			isFinal[v] = true;
			//更新w
			w = v;
		}
		/*输出结果*/
		for (i = 0; i < n; i++)
		{
			if (i != start)//起点到起点不用输出
			{
				cout << "0-" << i << '-' << D[i];
				cout << "----[";
				for (j = 0; j < len[i]; j++)
				{
					cout << P[i][j] << ' ';
				}
				cout << "]" << endl;
			}
		}
		delete[] D;
		delete[] isFinal;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		Graph gr;
		int n,start;
		cin >> n;
		gr.initWE(n);
		cin >> start;
		gr.shortPath(start);
	}
	return 0;
}