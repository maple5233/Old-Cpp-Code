/*��ά����������*/

#include<iostream>
#include<cmath>

using namespace std;
const int M = 50;

/*����PointX��PointY��ʾ��x�����y�����ź���ĵ�*/  
class PointX {
public:
	/*�Ƚ���*/
	bool operator<=(PointX a)const
	{
		return (x <= a.x);
	}
	int ID; //����  
	double x, y; //������   
};
class PointY {
public:
	bool operator<=(PointY a)const
	{
		return(y <= a.y);
	}
	int p; //ͬһ��������x�е������ź�������ţ�������м��и
	double x, y; //������  
};
/*����������*/
class Graph
{
private:
	/*��������*/
	int size;//�������
	PointX X[M];//�������
	PointX a;//����������һ����
	PointX b;//����������һ����
	double d;//�����Եľ���
	/*�������Ϳ�������*/
	template <class Type> double dis(const Type&u, const Type&v)
	{//����������ľ��� Type������PointX����PointY
		double dx = u.x - v.x;
		double dy = u.y - v.y;
		return sqrt(dx*dx + dy*dy);
	}
	template <class Type> void Copy(Type a[], Type b[], int left, int right)
	{//��������b��a Type������PointX����PointY
		int i;
		for (i = left; i <= right; i++)
			a[i] = b[i];
	}
	/*�鲢���� �˴�����Ҳ�Ƿ��η���Ӧ�õĹ鲢���� ��ʵ���������򷽷�Ҳ���� 
	���ڶԲ�ͬ�ඨ����˶�Ӧ�ıȽ��� TypeΪPointXʱ��x�������� ΪPointYʱ����y����������*/
	template <class Type> void Merge(Type c[], Type d[], int l, int m, int r)
	{//c d�ϲ�Ϊ�����d
		int i = l, j = m + 1, k = l;
		while ((i <= m) && (j <= r))
		{
			if (c[i] <= c[j])
			{
				d[k++] = c[i++];
			}
			else
			{
				d[k++] = c[j++];
			}
		}

		if (i>m)
		{
			for (int q = j; q <= r; q++)
			{
				d[k++] = c[q];
			}
		}
		else
		{
			for (int q = i; q <= m; q++)
			{
				d[k++] = c[q];
			}
		}
	}
	template <class Type>  void MergeSort(Type a[], Type b[], int left, int right)
	{//�鲢����
		if (left<right)
		{
			int i = (left + right) / 2;
			MergeSort(a, b, left, i);
			MergeSort(a, b, i + 1, right);//�ָ�������
			Merge(a, b, left, i, right);//�ϲ�������b  
			Copy(a, b, left, right);//���ƻ�����a         
		}
	}
	/*����С���*/
	void closest(PointX X[], PointY Y[], PointY Z[], int l, int r, PointX& a, PointX& b, double& d)
	{
		int i, j;
		if (r - l == 1) //��������� �ݹ�� 
		{
			a = X[l];
			b = X[r];
			d = dis(X[l], X[r]);
			return;
		}

		if (r - l == 2) //��������� �ݹ��
		{
			double d1 = dis(X[l], X[l + 1]);
			double d2 = dis(X[l + 1], X[r]);
			double d3 = dis(X[l], X[r]);

			if (d1 <= d2 && d1 <= d3)
			{
				a = X[l];
				b = X[l + 1];
				d = d1;
				return;
			}

			if (d2 <= d3)
			{
				a = X[l + 1];
				b = X[r];
				d = d2;
			}
			else {
				a = X[l];
				b = X[r];
				d = d3;
			}
			return;
		}

		//����3������Σ��÷��η� �ݹ鵽�ݹ��Ϊֹ  
		int m = (l + r) / 2;
		int f = l, g = m + 1;

		//���㷨Ԥ����׶Σ��Ѿ�������X�еĵ���x�������򣬽�����Y�еĵ���y��������  
		//�㷨�ָ�׶Σ���������X[l:r]���Ȼ��ֳ��������ཻ���Ӽ���ȡm=(l+r)/2  
		//X[l:m]��X[m+1:r]��������Ҫ��ķָ  
		for (i = l; i <= r; i++)
		{
			if (Y[i].p>m) 
				Z[g++] = Y[i];//�Ұ벿��Ϊl,m
			else 
				Z[f++] = Y[i];//��벿��Ϊm+1,r
		}

		closest(X, Z, Y, l, m, a, b, d);//���X[l:m] �ѷֺõ�Z����Y���� Z��Y����ѭ��ʹ��
	

		PointX ar, br;
		double dr;
		closest(X, Z, Y, m + 1, r, ar, br, dr);//���X[m+1:r] �ѷֺõ�Z����Y���� Z��Y����ѭ��ʹ��

		if (dr<d)
		{
			a = ar;
			b = br;
			d = dr;
		}//�Ƚ�����������Ľ�

		/*����������ߵ������� ���ºϲ���*/
		Merge(Z, Y, l, m, r);//�ع�����Y  
		//��P1�����е�p�����ź���ĵ�����һ��ɨ��
		//�Ϳ����ҳ�������ӽ���Եĺ�ѡ�ߣ���P1��ÿһ�����ֻҪ���P2���ź�������6���㡣

		//d�������ڵĵ�����Z[l:k-1]��  
		int k = l;
		for (i = l; i <= r; i++)
		{
			if (fabs(X[m].x - Y[i].x)<d)//fabs()���󸡵����ľ���ֵ
			{
				Z[k++] = Y[i];
			}
		}

		
		//����Z[l:k-1]  ��������һ�����ֻ��6����
		for ( i = l; i<k; i++)
		{//����ÿ��p
			for ( j = i + 1; j<k && Z[j].y - Z[i].y<d; j++)
			{
				double dp = dis(Z[i], Z[j]);
				if (dp<d)
				{
					d = dp;
					a = X[Z[i].p];
					b = X[Z[j].p];
				}
			}
		}
	}
	bool Cpair2(int n)//n�Ǳ��αȽϵ�����ĵ�ĸ���
	{//Ԥ����
		int i;
		if (n<2) return false;
		PointX* tmpX = new PointX[n];
		MergeSort(X, tmpX, 0, n - 1);//��x������

		PointY* Y = new PointY[n];
		for (i = 0; i<n; i++) //������X�еĵ㸴�Ƶ�����Y��  
		{
			Y[i].p = i;
			Y[i].x = X[i].x;
			Y[i].y = X[i].y;
		}

		PointY* tmpY = new PointY[n];
		MergeSort(Y, tmpY, 0, n - 1);//����Y��y������
		//tmpX tmpY ���ǹ鲢��������Ҫ����ʱ����

		PointY* Z = new PointY[n];
		closest(X, Y, Z, 0, n - 1, a, b, d);//�������

		delete[]Y;
		delete[]Z;
		delete[]tmpX;
		delete[]tmpY;
		return true;
	}
public:
	void initX()
	{
		int i;
		cout << "������������"<<endl;
		cin >> this->size;
		cout << "������ÿ�Ե㣺" << endl;
		for (i = 0; i<this->size; i++)
		{
			X[i].ID = i;//���
			cin>>X[i].x>>X[i].y;
		}
	}
	void display()
	{
		Cpair2(size);
		cout << "���ڽ����Ϊ��(" << a.x << "," << a.y << ")��(" << b.x << "," << b.y << ") " << endl;
		cout << "���ڽ�����Ϊ�� " << d << endl;
	}
};
int main()
{
	while (true)
	{
		Graph gr;
		gr.initX();
		gr.display();
		cout << "����Ҫ������(����0�˳�������1����)" << endl;
		int r;
		cin >> r;
		if (r==0)
			break;
		else
			continue;
	}
	
}