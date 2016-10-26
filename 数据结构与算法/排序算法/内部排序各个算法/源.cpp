/*快速排序*/
#include <iostream>
using namespace std;
class FastSort
{
private:
	int* S;
	int size;
	/*轴点构造算法*/
	int partition(int low, int high)
	{
		int pivot = S[low];
		while (low < high)
		{
			while ((low < high) && (pivot <= S[high]))//在不小于轴点pivot的情况下
				high--;
			S[low] = S[high];
			while ((low < high) && (pivot >= S[low])) // 在不大于轴点pivot的情况下
				low++;
			S[high] = S[low];
		}
		S[low] = pivot;
		return low;
	}
	/*快速排序算法*/
	void QSort(int low, int high)
	{
		//displayS();
		if (high - low < 2) return;
		int mid = partition(low, high);
		QSort(low, mid);
		QSort(mid + 1, high);
	}
public:
	FastSort(int n = 10)
	{
		S = new int[n];
		size = n;
	}
	~FastSort(){ delete[] S; }
	void initS()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			cin >> S[i];
		}
	}
	void displayS()
	{
		int i;
		//cout << "此时序列为：";
		for (i = 0; i < size - 1; i++)
		{
			cout << S[i] << ' ';
		}
		cout << S[size - 1] <<' '<< endl;
	}
	void mySort()
	{
		QSort(0, size - 1);
		displayS();
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size;
		cin >> size;
		FastSort f(size);
		f.initS();
		f.mySort();
	}
}