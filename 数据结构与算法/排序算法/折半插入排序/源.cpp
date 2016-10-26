#include<iostream>
using namespace std;
int main()
{
	int size,i,j,low,high,mid;
	cin >> size;
	int *L = new int[size + 1];
	L[0] = 0;
	for (i = 1; i <= size;i++)
	{
		cin >> L[i];
	}
	for (i = 2; i <= size;i++)
	{
		L[0] = L[i];//给哨兵赋值;
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			mid = (high + low) >> 1;
			if (L[0] >= L[mid])
				low = mid + 1;//高半区;
			else
				high = mid - 1;//低半区;
		}
		//high+1==low就是插入的位置
		for (j = i - 1; j >= high + 1; j--)
		{
			L[j+1] = L[j];
		}
		L[high+1] = L[0];
	}
	for (i = 1; i <= size; i++)
	{
		cout << L[i] << ' ';
	}
	cout << endl;
}