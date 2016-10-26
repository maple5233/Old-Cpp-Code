#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, char>m;
	m.insert(pair<int, char>(0, 'a'));
	m.insert(pair<int, char>(1, 'b'));
	m.insert(pair<int, char>(2, 'c'));
	cout << m[1] << endl;
}