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
		L[0] = L[i];//���ڱ���ֵ;
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			mid = (high + low) >> 1;
			if (L[0] >= L[mid])
				low = mid + 1;//�߰���;
			else
				high = mid - 1;//�Ͱ���;
		}
		//high+1==low���ǲ����λ��
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