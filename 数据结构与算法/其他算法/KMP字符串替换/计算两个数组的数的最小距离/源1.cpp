#include <algorithm>//Ҫ�����õ�������sort()
#include <iostream>
#include <cmath>//Ҫ�þ���ֵ����abs()
#define  min(x, y)     ((x) < (y) ? (x) : (y))//�궨�� �����Զ����max����
using namespace std;
int min_distance(int x[], int y[], int m, int n)//m��x�ĳ��ȣ�n��y�ĳ���
{
	int temp = abs(x[0] - y[0]);//��tempһ����ʼֵ ��ȥ������
	int  index_x = 0, index_y = 0;//index_x������x������ index_y������y������ �����ƶ��Ƚ�

	while (index_x < m && index_y < n)//�������û�е���ͷ ��ô�Ƚ�û�����
	{
		if (x[index_x] >= y[index_y])
		{
			temp = min(temp, x[index_x] - y[index_y]);
			index_y++; //���x�����������y������
		}
		else
		{
			temp = min(temp, y[index_y] - x[index_x]);
			index_x++; //���y�����������x������
		}
	}
	//�����ߵ�������β �ȽϽ���
	return temp;
}
int main()
{
	int m, n, i, x[10000], y[10000];
	cout << "��ֱ�������������ĳ��ȣ�" << endl;
	cin >> m >> n;
	cout << "����������1�������ݣ�" << endl;
	for (i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	cout << "����������2�������ݣ�" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	sort(x, x + m);
	sort(y, y + n);
	cout << "��С��ֵΪ" << min_distance(x,y,m,n) << endl;
	system("pause");
	return 0;
}