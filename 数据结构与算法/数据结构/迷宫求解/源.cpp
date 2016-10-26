#include<iostream>
#include<stack>
using namespace std;
int map[20][20];//�Թ�����

class Index
{
public:
	int xp;
	int yp;
	Index(){}
	Index(int xp, int yp)
	{
		this->xp = xp;
		this->yp = yp;
	}
	bool operator ==(Index b)
	{
		if (xp == b.xp&&yp == b.yp)
			return true;
		return false;
	}
};//λ�õ�Ԫ������
class Item
{
public:
	Index index;//λ��
	int dir;//ǰ������
	int num;//ͨ�����
};//ջ��Ԫ������-ͨ����

bool isPass(Index item)
{
	if (map[item.xp][item.yp] == 0)
		return true;
	return false;
}
void markFoot(Index item)//�߹���λ����Ϊ1
{
	map[item.xp][item.yp] = 1;
}
void nextIndex(Index& item, int dir)
{
	switch (dir)
	{
	case 1: //��һģ��Ϊ����ģ��
		item.yp++; break;//�м�1 �в���
	case 2: //��һģ��Ϊ����ģ��
		item.xp++; break;//�м�1 �в���
	case 3: //��һģ��Ϊ����ģ��
		item.yp--; break;
	case 4: //��һģ��Ϊ����ģ��
		item.xp--; break;
	default:
		break;
	}
}
void display(stack<Item> path)
{
	stack<Index> path1;//��ʱ���� ���ڵ�·��
	Index cpos;
	if (!path.empty())	//�ҵ�·��
	{
		while (!path.empty())
		{
			cpos = path.top().index;
			path1.push(cpos);
			path.pop();
		}//��·������path1
		int i = 0;  //���ڷֶ����·��
		while (!path1.empty())
		{
			cpos = path1.top();
			if ((++i) % 4 == 0)
				cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--" << endl;
			else
				cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--";
			path1.pop();
		}
		cout << "END" << endl;
	}
	else
		cout << "no path" << endl; //�Ҳ���·�����no path
}

bool findPath(int mapsize, stack<Item>& path)
{
	Item e;
	Index start(0, 0);
	Index end(mapsize - 1, mapsize - 1);
	Index curpos = start;//��ǰλ��
	int curstep = 1;//�������

	do
	{
		if (isPass(curpos))
		{
			markFoot(curpos);
			e.dir = 1;
			e.num = curstep;
			e.index = curpos;
			path.push(e);
			if (curpos == end)
			{
				return true;//�����յ�
			}
			nextIndex(curpos, 1);//���ȿ��Ƕ���
			curstep++;
		}
		else//��ǰλ�ò���ͨ��
		{
			if (!path.empty())
			{
				e = path.top();
				path.pop();
				while (e.dir == 4 && (!path.empty()))
				{
					markFoot(e.index);//������������� ���´˵ز�ͨ�ı��
					e = path.top();
					path.pop();
				}
				if (e.dir<4)
				{
					e.dir++;// ����һ������̽��
					path.push(e);
					//curpos = nextIndex(e.index, e.dir);
					curpos = e.index;
					nextIndex(curpos, e.dir); // ��ǰλ����Ϊ�·�������ڿ�
				}
			}
		}
	} while (!path.empty());//���ջ����֤��ͨ���鱻������ û��· �Թ��޽�
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		stack<Item> path;
		int mapSize, i, j;

		cin >> mapSize;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
			{
				map[i][j] = 1;
			}
		}//��ʼ���Թ� �����߽�
		for (i = 0; i < mapSize; i++)
		{
			for (j = 0; j < mapSize; j++)
			{
				cin >> map[i][j];
			}
		}//�����Թ�
		findPath(mapSize, path);
		display(path);
	}
	return 0;
}