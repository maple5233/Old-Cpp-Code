#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
#define datatype int
typedef enum { UNDISCOVERD, DISCOVERD, VISITED, DELETED } VStatus;//���������״̬
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD }Etype;//�ߵ����ͣ�δ���壬֧�����ߣ���ߣ�ǰ��ߣ������

vector<datatype> out;
queue<datatype> out2;


class Vertex//������
{
public:
	datatype data;//������
	int no;//���
	VStatus status;//״̬
	int dtime, ftime;//�����е�ʱ���ǩ
	int parent;//�����еĸ��ڵ�
	int inDegree, outDegree;//��Ⱥͳ���
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
	int weight;//Ȩ��
	Etype type;//����
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
	{//������Ϣ��λ
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
	void BFS(int v, int &clock)//��ͨ������������
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
			for (u = firstNbr(v); u < n; u = nextNbr(v, u))//ö�������ھ�
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
			cout << V[v].data << ' ';//����֮
			V[v].ftime = clock;
			V[v].status = VISITED;
		}
	}
	void DFS(int v, int &clock)//��ͨ�������������
	{
		int u;
		V[v].dtime = ++clock;
		V[v].status = DISCOVERD;//������֮
		out2.push(V[v].data);//�����漴����֮
		for (u = firstNbr(v); u < n; u = nextNbr(v, u))
		{
			switch (V[u].status)
			{
			case UNDISCOVERD://��չ֧����
				E[v][u]->type = TREE;
				V[u].parent = v;
				//cout << "v->" <<v;
				//cout << "u->" <<u ;
				DFS(u, clock);
				break;//�ݹ�
			case DISCOVERD://u�Ѿ������ֵ�û������ Ӧ�����ڱ����ָ�������
				E[v][u]->type = BACKWARD; break;
			default://u�Ѿ����������
				E[v][u]->type = (V[v].dtime < V[u].dtime) ? FORWARD : CROSS; break;
			}
		}
		V[v].status = VISITED;//�����Ƿ��ʹ��̽���
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
			case UNDISCOVERD://��չ֧����
				E[v][u]->type = TREE;
				V[u].parent = v;
				if (!TSortSmall(u, clock, S))//������ʧ���� ������ʧ����
				{
					return false;
				}
				break;//�ݹ�
			case DISCOVERD://u�Ѿ������ֵ�û������ Ӧ�����ڱ����ָ������� ���������ı�˵������DAG
				E[v][u]->type = BACKWARD;
				return false;//�������� ���ر���ʧ��
			default://u�Ѿ����������
				E[v][u]->type = (V[v].dtime < V[u].dtime) ? FORWARD : CROSS; break;
			}
		}
		V[v].status = VISITED;//��Ƿ��ʹ��̽���
		S.push(V[v].data);//��Ǽ�����ջ
		V[v].ftime = ++clock;
		return true;//v����������ɹ�
	}
	bool TSortBig(int v, queue<datatype>& Q)
	{

	}
public:
	/*��������*/
	vector<Vertex> V;//���㼯
	Edge* E[20][20];//�߼� ��ά����
	int n;//��ĸ���
	int e;//�ߵ�����

	/*���캯��*/
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
	/*��ȡ��ı��*/
	int getIndex(datatype c)//����ָ�����ݵı��
	{
		vector<Vertex>::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			if (it->data == c)
			{
				return it->no;
			}
		}
		return -1;//û�����Ԫ��
	}
	int getIndexTwo(datatype c)//����ָ�����ݵ��±�
	{
		vector<Vertex>::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			if (it->data == c)
			{
				return it - V.begin();
			}
		}
		return -1;//û�����Ԫ��
	}
	/*��ȡ�ھ�*/
	bool exsit(int i, int j)//�ж�ĳ�����Ƿ����
	{
		return (0 <= j) && (0 <= i) && (i < n) && (j < n) && (E[i][j]);
	}
	int nextNbr(int i, int j)//���Ѿ�ö�ٵ�����i���ھ�j ö����һ��i���ھ�
	{
		while ((n>j) && !exsit(i, ++j));
		return j;
	}
	int firstNbr(int i)//ö�ٵ�i�ĵ�һ���ھӣ���i�е����ף�
	{
		return(nextNbr(i, -1));
	}
	bool hasNbr(int i)
	{
		if (firstNbr(i) == n)
			return false;
		return true;
	}
	/*��ʼ��ͼ;*/
	void initV()
	{//���������n ��ʼ��n������ �±��0-(n-1) ���ݴ�A��ʼ����n����ĸ
		//������e����
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
	{//�ֱ����붥��ͱ�;
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
	void initVertex(int size)//�û�ֱ�������ڽӾ���
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
	{//�����Ȩͼ���ڽӾ��� û�еĵ�Ȩ�ر���ֵΪ9999
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
	/*�����ɾ��;*/
	bool insertEdge(int i, int j, int w = 9999)//����һ����iָ��j�ı� Ȩ��Ϊw
	{
		if (E[i][j])
			return false;
		E[i][j] = new Edge(w);//�����±� Ȩ��Ϊw
		e++;
		V[i].outDegree++;
		V[j].inDegree++;
		return true;
	}
	void remove(int i)//ɾ����
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
			}//ɾ������
		}

		//V.erase(it);//ɾ������
		it->status = DELETED;//ɾ������

		for (j = 0; j < n; j++)
		{
			if (E[j][i])
			{
				delete E[j][i];
				E[j][i] = NULL;
				V[j].outDegree--;
				e--;
			}
		}//ɾ�����
	}
	void remove(int i, int j)//ɾ����
	{
		delete E[i][j];
		E[i][j] = NULL;
		V[i].outDegree--;
		V[j].inDegree--;
		e--;
	}
	void insertVertex(Vertex v)//���붥��v
	{
		n++;
		V.push_back(v);//�㼯�в���v
	}

	/*����������*/
	void bfs(int s)//ȫͼ�����������
	{//��α���
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
	void dfs(int s)//ȫͼ�����������
	{//�������discover �������visited
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
	bool tSortSmall(int s, stack<datatype>& S)//��ע��С����������� ����dfs��� ����Ҫ������ȳ��� 
	{//�����㱻���ΪVISITED��˳�򣨺�������� ǡ�ø�������һ���������������
		//���ַ��������ƻ�ͼ�ṹ ���Ǹ������������� ��һ�������Ȱ�С����ǰ�� ����һ���ǺϷ�����������
		int clock = 0;
		int v = s;
		do
		{
			if (UNDISCOVERD == V[v].status)
			{
				if (!TSortSmall(v, clock, S))//�������DAG
				{
					while (!S.empty())
					{
						S.pop();
					}//���ջ
					return false;//����ʧ�� S��
				}
			}
		} while (s != (v = (++v) % n));//vתһȦ�ص�s
		return true;//������ΪDAG ��S�ڸ������Զ��������
	}
	void tSortBig(int s, queue<datatype>& Q)//��ע���󶥵� Ҳ�������Ϊ0�Ķ��� ���ȿ���С�� ÿ�ζ�ժ�����Ϊ0�Ķ���
	{//�ƻ���ͼ�ṹ Ҳ�޷��ж��ǲ��������޻�ͼ
		Q.push(V.at(s).data);
		remove(s);//��s��ʼ
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
	/*����*/
	void showAdjacencyList()//����ڽӱ�
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
	void shortPath(int start)//���춥��start��ʼ����С·���� �����֮
	{
		int i, j, k, w, min, u,v;
		int P[20][20];//���·����
		int *D = new int[n];//�����¼�������������С·��Ȩֵ�ͣ���ʵ�ʳ��ȡ����룩
		bool* isFinal = new bool[n];//��¼ÿ�������Ƿ��Ѿ��ﵽѡ����̬
		int len[20];//��¼ÿ�����·���ĳ��ȣ���·���ϵĶ���ĸ�����

		/*��ʼ��*/
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
			P[i][0] = start;//��0
			P[i][1] = i;//��i
			//��¼�����ص�
			len[i] = 2;//����ʼ����Ϊ2�������ص��ܹ�������
		}
		D[start] = 0;//��㵽�Լ��ĳ���Ϊ0
		isFinal[start] = true;//��㴦�����

		/*��ѭ��*/
		/*�ܹ�n-1��*/
		/*��һ��*/

		//�ҳ�����һ���յ�����Ķ���w(��ʱ�ġ���һ�ε��յ�"��Ϊ���start)
		min = 9999;
		for (u = 0; u < n; u++)
		{
			if (D[u] < min && isFinal[u] == false)
			{
				min = D[u];
				w = u;//��Ӧ����
			}
		}//�ҳ��������С�� Ҳ����D[]����С��w
		isFinal[w] = true;//�ҵ��˼������󼯺� ��㵽w�ľ����Ѿ���� ����Ϊmin 
		//��㵽w��·���Ѿ�������P[][]


		/*��������n-2��*/

		//����start��w�ٵ���������ľ���(��������һ��ѭ����Ҫ�����ݣ�������һ�У�)
		//���ҳ�����һ���յ�w����Ķ���v��ѭ��ִ�У�
		for (k = 0; k < n - 2; k++)//��������n-2��
		{
			for (i = 0; i<n; i++)
			{
				if (isFinal[i])
					continue;//�����Ѿ�������ϵ�
				//D[i]ȡD[i]��min+E[w][i]->weight֮��С���Ǹ�
				if (D[i] > min + E[w][i]->weight)//D[i]����С ��㵽i��·���ܵ�Ӱ�죨��Ϊ��������㵽w������·�����̾��룩
				{
					D[i] = min + E[w][i]->weight;//����D[i] 
					/*������㵽w��·�� �ټ�һ���ߵ�i*/
					for (j = 0; j < len[w]; j++)
					{
						P[i][j] = P[w][j];
					}
					len[i] = len[w] + 1;
					P[i][len[w]] = i;
				}
			}//����D[]����һ��

			min = 9999;
			for (u = 0; u < n; u++)
			{
				if (D[u] < min && isFinal[u] == false)
				{
					min = D[u];
					v = u;//��Ӧ����
				}
			}//�����ҳ�D[]��С���Ǹ� Ҳ������w����Ǹ�v��Ϊ�µ�w
			isFinal[v] = true;
			//����w
			w = v;
		}
		/*������*/
		for (i = 0; i < n; i++)
		{
			if (i != start)//��㵽��㲻�����
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