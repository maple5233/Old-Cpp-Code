/*******************************
*   p4_5.cpp                   *
* ººÅµËşÎÊÌâ                   *
*******************************/
#include <iostream>
using namespace std;
void move(int n, char source, char target)
{
	cout << "( " << n << ", " << source << "--->" << target << " )" << endl;
}
void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
		move(1, A, C);
	else
	{
		hanoi(n - 1, A, C, B);
		move(n, A, C);
		hanoi(n - 1, B, A, C);
	}
}
void main()
{
	int num;
	cout << "Input the number of diskes" << endl;
	cin >> num;
	hanoi(num, 'A', 'B', 'C');
	system("pause");
}

