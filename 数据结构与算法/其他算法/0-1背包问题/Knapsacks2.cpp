#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void subRoutine(const int l, const int n, const int m, unsigned __int64 a[], unsigned __int64 L[]){
	for (int i = 0; i < n; i++) {
		unsigned __int64 sum = 0;
		for (int j = l, k = 0; j < m+l; j++,k++) {
			sum = sum + (i/(int)pow(2,k)%2)*a[j];
		}
		L[i] = sum;
		cout<<"["<<i<<"]:"<<L[i]<<endl;
	}
	for (int i = 0; i < n; i++)//对所取得的值，进行升序排序 
	{
		for (int j = 0; j < n-1; j++)
		{
			if (L[j] > L[j+1])
			{
				unsigned __int64 temp = L[j];
				L[j] = L[j+1];
				L[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)//打印排序的值 
	{
		//cout<<"L["<<i<<"]:"<<L[i]<<endl;
		cout<<L[i]<<endl;
	}
	

	cout<<endl;
}

void alogrithm2(int n1,int n2,int n3,int n4,unsigned __int64 L1[],unsigned __int64 R1[],unsigned __int64 L2[],unsigned __int64 R2[],const int n, unsigned __int64 s)
{
	__int64(*Q1)[3] = new __int64[n1][3];
	__int64(*Q2)[3] = new __int64[n3][3];
    for (int i=0;i<n1;i++)          // Q1 ,Q2 数组初始化
	{
		Q1[i][2]=L1[i]+R1[0];
	    Q1[i][1]=0;
		Q1[i][0]=i;
	}
	for (int i=0;i<n3;i++)
	{
        Q2[i][2]=s-L2[i]-R2[n4-1];
	    Q2[i][1]=n4-1;	
        Q2[i][0]=i;
	}
	
	for(int i=0;i<n1;i++)          //打印 Q1 ,Q2 初始化数组
	{
		cout<<Q1[i][2]<<","<<Q2[i][2]<<endl;
		cout<<Q1[i][1]<<","<<Q2[i][1]<<endl;
		cout<<Q1[i][0]<<","<<Q2[i][0]<<endl;
	
	}
	
    while(Q1!=NULL && Q2!=NULL)
    { 
        int j1=0,j2=0,k1,k2,l1,l2;
        __int64 q1,q2;
		for(int i=1;i<n1;i++)              //求Q1的最小值为q1
		{
			if (Q1[j1][2]>Q1[i][2])
				j1 = i;
		}
		q1 = Q1[j1][2];
		l1 = Q1[j1][1];
		k1 = Q1[j1][0];
		cout<<q1<<endl;
		cout<<l1<<endl;
		cout<<k1<<endl;
		for(int i=1;i<n3;i++)              //求Q2的最小值为q2
		{
			if (Q2[j2][2]>Q2[i][2])
				j2 = i;
		}
		q2 = Q2[j2][2];
		l2 = Q2[j2][1];
		k2 = Q2[j2][0];
		cout<<q2<<endl;
		cout<<l2<<endl;
		cout<<k2<<endl;
		
		if (q1<q2)                          
	     {if (l1!=n2-1)
			{
				l1 = l1 + 1;
				Q1[j1][1] = l1;
				Q1[j1][2] = L1[k1] + R1[l1];
				
			}
		else 
		    {
			    for(;j1<n1;j1++)
			    {
    				Q1[j1][2]=Q1[j1+1][2];
	                Q1[j1][1]=Q1[j1+1][1];
		            Q1[j1][0]=Q1[j1+1][0];
    			}
			    n1--;
			
            }
	     }
	     
	    if (q1>q2)
		 {if (l2!=0)
			{
				l2 = l2 - 1;
				Q2[j2][1] = l2;
				Q2[j2][2] = s - L2[k2] - R2[l2];
				
			}
		  else 
		    {
			    for(;j2<n3;j2++)
			    {
    				Q1[j2][2]=Q1[j2+1][2];
	                Q1[j2][1]=Q1[j2+1][1];
		            Q1[j2][0]=Q1[j2+1][0];
    			}
			    n3--;
			
            }
		 }
		
		if(q1==q2)
		{
			__int64 sol[4];
			sol[0]=Q1[j1][0];
			sol[1]=Q1[j1][1];
			sol[2]=Q2[j2][0];
			sol[3]=Q2[j2][1];
			cout<<"实验结果："<<endl;
			for(int i=0;i<4;i++)
			{cout<<sol[i]<<" ";}
			cout<<endl;
			break;
			for(;j1<n1;j1++)
			    {
    				Q1[j1][2]=Q1[j1+1][2];
	                Q1[j1][1]=Q1[j1+1][1];
		            Q1[j1][0]=Q1[j1+1][0];
    			}
			    n1--;
            for(;j2<n3;j2++)
			    {
    				Q1[j2][2]=Q1[j2+1][2];
	                Q1[j2][1]=Q1[j2+1][1];
		            Q1[j2][0]=Q1[j2+1][0];
    			}
			    n3--;			
		}
    }
}

//划分四个数组 
void alogrithm1(const int n, unsigned __int64 a[], unsigned __int64 s){
	int i = 0, j = 0, k = 0;
	int m1, m2, m3, m4; //分组大小 
	m1 = n/4;
	m2 = n/2 - m1;
	m3 = 3*n/4 - n/2;
	m4 = n - 3*n/4;
	int n1, n2, n3, n4; //数组大小 
	n1 = (int)pow(2, m1);
	n2 = (int)pow(2, m2);
	n3 = (int)pow(2, m3);
	n4 = (int)pow(2, m4);
	unsigned __int64 *L1 = new unsigned __int64[n1];
	unsigned __int64 *R1 = new unsigned __int64[n2];
	unsigned __int64 *L2 = new unsigned __int64[n3];
	unsigned __int64 *R2 = new unsigned __int64[n4];
	
	subRoutine(0, n1, m1, a, L1);
	subRoutine(m1, n2, m2, a, R1);
	subRoutine(m1+m2, n3, m3, a, L2);
	subRoutine(m1+m2+m3, n4, m4, a, R2);
	//alogrithm2(n1,n2,n3,n4,L1,R1,L2,R2,n,s);		
}
	

int main(){
	int n;
	cout << "输入n的大小" << endl;
	cin >> n;
	unsigned __int64 *a=new unsigned __int64[n], s;
	int *x = new int[n];
		
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)//随机取值 
	{
		a[i] = rand();
		for (int j = 0; j < 16; j++)
		{
			a[i] = a[i] + (rand()%2)*pow(2,j+32);
		}
	}
	
	for (int i = 0; i < n; i++)//对所取得的值，进行升序排序 
	{
		for (int j = 0; j < n-1; j++)
		{
			if (a[j] > a[j+1])
			{
				unsigned __int64 temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)//打印排序的值 
	{
		cout<<"a["<<i<<"]:"<<a[i]<<endl;
	}
	
	s = 0;
	for (int i = 0; i < n; i++)//随机取得一个总和 
	{
		x[i] = rand()%2;
		s = s + (x[i] * a[i]);
		cout << "x[" << i << "]:" << x[i] << " ";
	}
	cout<<endl;
	cout<<"s = "<<s<<endl;
    alogrithm1(n, a, s);
	system("pause");
	return 0;
}