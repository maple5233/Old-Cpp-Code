#include<iostream>
using namespace std;
//计算一个数列连续增加或者连续降低的数字串的最大长度
int main()
{
	int T;
	cin >> T;
	int a[10000];
	int n,i;
	int count, max1, max2;
	while (T--)
	{
		count = 1;
		max1 = 1;
		max2 = 1;
		cin >> n;

		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (i = 1; i<n; i++)
			{
				if (a[i-1] >= a[i])
				{
					count = 1;        // 如果出现当前小于或等于前一个就把count置1，就是以当前数字为起点重新计数并直接 continue 检测下一个数
					continue;
				}
				count++;       // 只要当前数大于前一个 ， 其实就是前面的if不成立， count就加1
				if (count > max1) 
					max1= count;    // 每次检测一次  如果大于max就置max为count
			}

		count = 1;

		for (i = 1; i<n; i++)
			{
				if (a[i] >= a[i - 1])
				{
					count = 1;
					continue;
				}
				count++;
				if (count > max2) 
					max2 = count;   
			}

		if (max1 >= max2)
			cout << max1 << endl;
		else
			cout << max2 << endl;
	}
	return 0;
}