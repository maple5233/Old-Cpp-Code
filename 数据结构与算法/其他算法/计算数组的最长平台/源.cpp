#include<iostream>
#include <algorithm>
using namespace std;

int longest_plateau1(int x[], int n)
{
	
	int i = 1,length=1;
	for (i = 1; i < n; i++)
	{
		if (x[i] == x[i - length])
			length++;
	}
	return length;
}
//较好地利用了排序 不断把最大长度串区间往右移动
int longest_plateau2(int x[], int n)
{
	int i = 0 , length=1,count=1;
	for (i = 0; i < n; i++)
	{
		if (x[i] != x[i + 1])
		{
			length = count >= length ? count : length;
			count = 1;
			continue;
		}
		count++;
	}
	return length;
}
int main()
{
	cout << "请输入数组长度：" << endl;
	int n,i;
	cin >> n;
	int* x = new int[n];
	cout << "请依次输入数组数据：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	cout << "数组元素如下：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	sort(x, x + n);
	cout << endl<<endl;

	cout << "使用函数1计算出的最大长度为";
	cout << longest_plateau1(x, n) << endl<<endl;
	cout << "使用函数2计算出的最大长度为";
	cout << longest_plateau2(x, n) << endl<<endl;
	system("pause");
	delete[] x;
	return 0;
}