#include<iostream>
using namespace std;
//����һ�������������ӻ����������͵����ִ�����󳤶�
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
					count = 1;        // ������ֵ�ǰС�ڻ����ǰһ���Ͱ�count��1�������Ե�ǰ����Ϊ������¼�����ֱ�� continue �����һ����
					continue;
				}
				count++;       // ֻҪ��ǰ������ǰһ�� �� ��ʵ����ǰ���if�������� count�ͼ�1
				if (count > max1) 
					max1= count;    // ÿ�μ��һ��  �������max����maxΪcount
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