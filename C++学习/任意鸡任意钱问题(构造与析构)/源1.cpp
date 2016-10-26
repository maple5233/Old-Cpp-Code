#include<iostream>
using namespace std;
class CChickProblem
{
private:
	int money,chi;
	int *gj, *mj, *xj;
	int sum;
public:
	CChickProblem(){ money = 100; chi = 100; gj = NULL; mj = NULL; xj = NULL; sum = 0; }
	CChickProblem(int m, int c){ money = m; chi = c; gj = NULL; mj = NULL; xj = NULL; sum = 0; }
	~CChickProblem()
	{ 
		delete[]gj;
	    delete[]mj;
	    delete[]xj;
	}
	void findSolution()
	{
		int gjmax = money / 5;
		int mjmax = money / 3;
		int xjmax = money * 3;
		int jie = 0;
		int i, j, k;
		for (i = 0; i <= gjmax; i++)
		{
			for (j = 0; j <= mjmax; j++)
			{
				for (k = 0; k <= xjmax; k++)
				{
					if ((i + j + k) == chi && (5 * i + 3 * j + k / 3) == money && k % 3 == 0 && i != 0 && j != 0 && k != 0)
						sum++;
				}
			}
		}
		gj = new int[sum];
		mj = new int[sum];
		xj = new int[sum];
		for (i = 0; i <= gjmax; i++)
		{
			for (j = 0; j <= mjmax; j++)
			{
				for (k = 0; k <= xjmax; k++)
				{
					if ((i + j + k) == chi && (5 * i + 3 * j + k / 3) == money && k % 3 == 0&&i!=0&&j!=0&&k!=0)
					{
						*(gj + jie) = i;
						*(mj + jie) = j;
						*(xj + jie) = k;
						jie++;
					}
				}
			}
		}
	}

	void printSolution()
	{
		int i;
		cout << sum << endl;
		for (i = 0; i < sum; i++)
		{
			cout << *(gj + i) << ' ' << *(mj + i) << ' ' << *(xj + i) << endl;
		}
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int umoney, uchi;
		cin >> umoney >> uchi;
		CChickProblem a(umoney,uchi);
		a.findSolution();
		a.printSolution();
	}
	return 0;
}