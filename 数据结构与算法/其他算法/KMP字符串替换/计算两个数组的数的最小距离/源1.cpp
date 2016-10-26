#include <algorithm>//要用内置的排序函数sort()
#include <iostream>
#include <cmath>//要用绝对值函数abs()
#define  min(x, y)     ((x) < (y) ? (x) : (y))//宏定义 代替自定义的max函数
using namespace std;
int min_distance(int x[], int y[], int m, int n)//m是x的长度，n是y的长度
{
	int temp = abs(x[0] - y[0]);//给temp一个初始值 再去减少它
	int  index_x = 0, index_y = 0;//index_x是数组x的索引 index_y是数组y的索引 用于移动比较

	while (index_x < m && index_y < n)//如果索引没有到尽头 那么比较没有完成
	{
		if (x[index_x] >= y[index_y])
		{
			temp = min(temp, x[index_x] - y[index_y]);
			index_y++; //如果x组的数大右移y的索引
		}
		else
		{
			temp = min(temp, y[index_y] - x[index_x]);
			index_x++; //如果y组的数大右移x的索引
		}
	}
	//索引走到了数组尾 比较结束
	return temp;
}
int main()
{
	int m, n, i, x[10000], y[10000];
	cout << "请分别输入两个数组的长度：" << endl;
	cin >> m >> n;
	cout << "请输入数组1各项数据：" << endl;
	for (i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	cout << "请输入数组2各项数据：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	sort(x, x + m);
	sort(y, y + n);
	cout << "最小差值为" << min_distance(x,y,m,n) << endl;
	system("pause");
	return 0;
}