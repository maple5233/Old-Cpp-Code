#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		stack<char> s;
		cin >> a;
		bool same=true;
		string::iterator it;
		for (it = a.begin(); it < a.end(); it++)
		{
			s.push(*it);
		}
		for (it = a.begin(); it < a.end(); it++)
		{
			char c = s.top();
			if (c!=*it)
			{
				same = false;
				break;
			}
			s.pop();
		}
		int result=same?1:-1;
		cout << result << endl;
	}
}