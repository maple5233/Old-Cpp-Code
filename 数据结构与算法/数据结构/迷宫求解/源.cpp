#include<iostream>
#include<stack>
using namespace std;
int map[20][20];//迷宫数组

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
};//位置的元素类型
class Item
{
public:
	Index index;//位置
	int dir;//前进方向
	int num;//通道序号
};//栈的元素类型-通道块

bool isPass(Index item)
{
	if (map[item.xp][item.yp] == 0)
		return true;
	return false;
}
void markFoot(Index item)//走过的位置置为1
{
	map[item.xp][item.yp] = 1;
}
void nextIndex(Index& item, int dir)
{
	switch (dir)
	{
	case 1: //下一模块为东临模块
		item.yp++; break;//列加1 行不变
	case 2: //下一模块为南临模块
		item.xp++; break;//行加1 列不变
	case 3: //下一模块为西临模块
		item.yp--; break;
	case 4: //下一模块为北临模块
		item.xp--; break;
	default:
		break;
	}
}
void display(stack<Item> path)
{
	stack<Index> path1;//临时变量 用于倒路径
	Index cpos;
	if (!path.empty())	//找到路径
	{
		while (!path.empty())
		{
			cpos = path.top().index;
			path1.push(cpos);
			path.pop();
		}//将路径倒入path1
		int i = 0;  //用于分段输出路径
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
		cout << "no path" << endl; //找不到路径输出no path
}

bool findPath(int mapsize, stack<Item>& path)
{
	Item e;
	Index start(0, 0);
	Index end(mapsize - 1, mapsize - 1);
	Index curpos = start;//当前位置
	int curstep = 1;//步骤序号

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
				return true;//到达终点
			}
			nextIndex(curpos, 1);//优先考虑东边
			curstep++;
		}
		else//当前位置不能通过
		{
			if (!path.empty())
			{
				e = path.top();
				path.pop();
				while (e.dir == 4 && (!path.empty()))
				{
					markFoot(e.index);//三面受阻则后退 留下此地不通的标记
					e = path.top();
					path.pop();
				}
				if (e.dir<4)
				{
					e.dir++;// 换下一个方向探索
					path.push(e);
					//curpos = nextIndex(e.index, e.dir);
					curpos = e.index;
					nextIndex(curpos, e.dir); // 当前位置设为新方向的相邻块
				}
			}
		}
	} while (!path.empty());//如果栈空了证明通道块被弹光了 没有路 迷宫无解
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
		}//初始化迷宫 产生边界
		for (i = 0; i < mapSize; i++)
		{
			for (j = 0; j < mapSize; j++)
			{
				cin >> map[i][j];
			}
		}//输入迷宫
		findPath(mapSize, path);
		display(path);
	}
	return 0;
}