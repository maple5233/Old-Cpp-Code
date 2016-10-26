#include<iostream>
#include<string>
using namespace std;
/*next表的实质是，next[j]是模式串第j位的前缀部分[0,j) 的 最大的 自匹配的 真前缀和真后缀的长度值*/

/*构建模式串（假设长度为j）的next表的方法是，以自身[0,j)作为主串又作为模式串，找出最大的自匹配的串，其长度作为next表的第j位

而已知前面部分（j-1）的next表，就可以 以前面部分[0,j-1)又作为主串又作为模式串，找出最大的自匹配的串，从而求得next表下一位

因此已知第一位就可以 不断递归求得next的下一位

next[0]=-1 作为逻辑上的通配符 就像是next[0]前面有个通配符可以和任何字符匹配 当0>j时直接算作匹配成功 该位置上的next表值为0
*/

void creatNext(string subString, int* next)//构建next表
{
	int l = subString.length();
	int j = 0;
	int t = *next;
	while (j < l - 1)
	{
		if (0>t || subString[j] == subString[t])//匹配 t小于0说明遇到了通配符 t=-1 t++ t变成0作为next的下一个值
		{
			next[++j] = ++t;
		}
		else//失配
			t = next[t];
	}
}

int KMPSearch(string mainString, string subString)
{
	int l = subString.length();
	int* next = new int[l];
	*next = -1;

	creatNext(subString, next);

	int i = 0, j = 0;//i为文本串索引，j为模式串索引
	int m = subString.length();
	int n = mainString.length();

	while (j < m && i < n)//i到达最后代表没有匹配成功 j到达最后代表匹配成功了
	{
		if (0>j || mainString[i] == subString[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	delete[] next;

	if ((i - j) <= (n - m))
	{
		return i-j;//匹配成功则从i-j开始是吻合的
	}
	else
	{
		return -1;
	}
}

void swapString(string& oldString, string subString, string newString)
{
	string newS = "";
	unsigned int i;
	int index = KMPSearch(oldString, subString);
	if (index == -1)
		return;
	for (i = 0; i <index; i++)
	{
		newS += oldString[i];
	}
	newS += newString;
	for (i = index+subString.length();i<oldString.length(); i++)
	{
		newS += oldString[i];
	}
	oldString = newS;
}
int main()
{
	int t;
	cin >> t;
	string mainString, subString,newString;
	while (t--)
	{
		cin >> mainString >> subString >> newString;
		cout << mainString << endl;
		swapString(mainString, subString, newString);
		cout << mainString << endl;
	}
	return 0;
}