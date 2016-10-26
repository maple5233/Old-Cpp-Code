#include<iostream>
#include<queue>
using namespace std;
void addTime(char c, queue<int>& peopleTime, int& A, int& B, int& C,int& an,int& bn,int& cn)
{
	int tmpNum;
	tmpNum = peopleTime.front();
	peopleTime.pop();
	switch (c)
	{
	case'A':A += tmpNum; an++; break;
	case'B':B += tmpNum; bn++; break;
	case'C':C += tmpNum; cn++; break;
	default:
		break;
	}
}
int main()
{
	int peopleNum, tmpTime, i;
	char tmpClass;
	queue<char> peopleClass;
	queue<int> peopleTime;
	int  ATime=0, BTime=0, CTime=0;
	int  ANum = 0,BNum=0,CNum=0;

	cin >> peopleNum;
	for (i = 0; i < peopleNum; i++)
	{
		cin >> tmpClass;
		peopleClass.push(tmpClass);
	}
	for (i = 0; i < peopleNum; i++)
	{
		cin >> tmpTime;
		peopleTime.push(tmpTime);
	}

	while (!peopleClass.empty())
	{
		tmpClass = peopleClass.front();
		peopleClass.pop();
		addTime(tmpClass, peopleTime, ATime, BTime, CTime, ANum, BNum,CNum);
	}

	cout << ATime / ANum << endl;
	cout << BTime / BNum << endl;
	cout << CTime / CNum << endl;
	system("pause");
	return 0;
}