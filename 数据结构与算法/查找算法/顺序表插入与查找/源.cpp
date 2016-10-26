#include <iostream>
using namespace std;
#define maxSize 100
int main()
{
	int T,i;
	cin >> T;
	while (T--)
	{
		int* s = new int[maxSize];
		int usedSize = 0;
		int insert;
		int index;

		cin >> usedSize;
		for (i = 1; i <= usedSize; i++)
			cin >> s[i];

		cin >> index >> insert;
		for (i = usedSize; i >= index; i--)
			s[i + 1] = s[i];
		s[index] = insert;
		usedSize++;

		for (i = 1; i < usedSize; i++)
			cout << s[i] << ' ';
		cout << s[i] << endl;

		cin >> s[0];
		int ftime = 0;
		for (i = usedSize; i >=0; i--)
		{
			ftime++;
			if (s[i]==s[0])
			{
				break;
			}
		}
		if (i==0)
		{
			cout << 0 << ' ' << 0 << ' ' << ftime << endl;
		}
		else
		{
			cout << 1 << ' ' << i << ' ' << ftime<<endl;
		}
	}

}