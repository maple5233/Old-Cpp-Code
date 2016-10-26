#include <iostream>
using namespace std;
void insertSort(int L[],int size)
{
	int i, j;
	for (i = 1; i < size;i++)
	{
		if (L[i]<L[i - 1])
		{
			int temp = L[i];
			for (j = i - 1; j >= 0 && L[j]>temp; j--)//从右向左扫描找出第一个比它小的;
			{
				L[j + 1] = L[j];
			}
			L[j + 1] = temp;//此处就是a[j+1]=temp;
		}
	}
}
int main()
{
	int i;
	int* L;
	int size;
	cin >> size;
	L = new int[size];
	for (i = 0; i < size; i++)
	{
		cin >> L[i];
	}
	insertSort(L, size);
	for (i = 0; i < size-1; i++)
	{
		cout << L[i] << ' ';
	}
	cout << L[size - 1]<<' ' << endl;
	delete[] L;
	//system("pause");
	return 0;
}