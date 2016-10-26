#include<iostream>
#include<algorithm>
using namespace std;
#define datatype int
class SearchIndex
{//索引表类
public:
	int max;
	int head;
	int tail;
};
class Search
{
private:
	datatype* main;//主表
	int size;//表的大小
	bool success;//是否成功
	int index;//成功的位置
	void seqSearch()//顺序查找
	{
		int n = size;
		while (n--)
		{
			if (main[0] == main[n])
			{
				index = n;
				if (n == 0)
				{
					success = false;
				}
				return;
			}
		}
	}
	void binarySearch_1()//已经排好序了折半查找迭代实现
	{
		int low = 1, high = size, key = main[0];
		int mid = 0;
		success = false;
		while (low < high)//可以有等号 low < = high,不影响判断。  
		{
			mid = (low + high) >> 1;
			if (main[mid] == key)
			{
				index = mid;
				success = true;
				return;
			}
			if (main[mid] > key)
				high = mid - 1;
			if (main[mid] < key)
				low = mid + 1;
		}
	}
	int binarySearch_2(int low, int high)//已经排好序了折半查找递归实现
	{
		if (low > high)
		{
			return 0;//查找失败
		}
		int mid = (low + high) >> 1;//折半
		if (main[mid] == main[0])
		{
			success = true;
			return mid;
		}
		if (main[mid] > main[0])
			return binarySearch_2(low, mid - 1);
		else
			return binarySearch_2(mid + 1, high);
	}
	void mianSort()//排序
	{
		if (main)
		{
			sort(main + 1, main + size);
		}
	}
public:
	Search()
	{
		main = NULL;
		success = true;
	}
	Search(int size)
	{
		main = new datatype[size + 1];
		this->size = size + 1;
		success = true;
	}
	~Search()
	{
		if (main)
			delete[] main;
	}
	void initMain()
	{
		int i = 0;
		for (i = 1; i < size; i++)
		{
			cin >> main[i];
		}
	}
	void seqDisplay()
	{
		cin >> main[0];//输入待查找的值
		seqSearch();
		if (success)
		{
			cout << index << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	void binarySearch_1_display()
	{
		cin >> main[0];
		mianSort();
		binarySearch_1();
		if (success)
		{
			cout << index << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	void binarySearch_2_display()
	{
		cin >> main[0];
		success = false;
		mianSort();
		index = binarySearch_2(1, size);
		if (index)
		{
			cout << index << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	void fkSearch_display()
	{
		main[0] = 9999;
		int i,m, j = 0;
		int k, no, key, num = 0;
		//k表示索引表长度 no表示待查找数据的个数 key表示待查找的数据 num表示每次查找花费的时间

		/*构建索引表*/
		cin >> k;//输入索引表长度
		SearchIndex* ind = new SearchIndex[k];
		for (i = 0; i < k; i++)
		{
			cin >> ind[i].max;
		}//输入索引表各项最大值
		for (i = 0; i < k; i++)
		{
			j++;
			ind[i].head = j;
			while (main[j] <= ind[i].max)
			{
				j++;
			}
			j--;
			ind[i].tail =j ;
		}//分块

		/*查找*/
		cin >> no;//输入查找次数
		for (m = 0; m < no; i++)
		{
			success = false;
			num = 1;
			cin >> key;
			for (j = 0; j < k; j++)
			{
				if (key <= ind[j].max)
				{
					break;
				}
				num++;
			}//找到在哪一块
			if (j == 3)//比任何一块都大
			{
				cout << "error" << endl;
				break;
			}
			for (i = ind[j].head; i != ind[j].tail+1; i++)
			{
				num++;
				if (key == main[i])
				{
					success = true;
					cout << i << '-' << num << endl;
					break;
				}
			}//在该块查找
			if (!success)
			{
				cout << "error" << endl;
			}
		}
		delete[] ind;
	}
};
int main()
{
	int size;
	cin >> size;
	Search my(size);
	my.initMain();
	int T;
	cin >> T;
	while (T--)
	{
		my.binarySearch_2_display();
	}
	system("pause");
	return 0;
}