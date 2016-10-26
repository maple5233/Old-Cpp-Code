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
		if (0>t || subString[j] == subString[t])//匹配 t小于0说明遇到了通配符 此时t=-1 t++ t变成0作为next的下一个值
		{
			//next[++j] = ++t; 可以改进为：
			j++;
			t++;
			next[j] = (subString[j] == subString[t]) ? next[t] : t;
		}
		else//失配
			t = next[t];
	}
}

void KMPSearch(string mainString, string subString)
{
	int l = subString.length();
	int* next =new int [l];
	*next = -1;

	creatNext(subString, next);

	int i = 0, j = 0;//i为文本串索引，j为模式串索引
	int m = subString.length();
	int n = mainString.length();

	int k;
	for (k = 0; k<m - 1; k++)
	{
		cout << next[k]+1<<' ';
	}
	cout << next[k] + 1 <<  ' '<< endl;

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
	if (j == m)//j到达最后代表匹配成功了
	//if ((i - j) <= (n - m))//如果匹配的位置在[0,n-m] 说明成功 不然说明不成功
	{
		cout << (i - j) +1<< endl;
		return;//匹配成功则从i-j开始是吻合的
	}
	cout << 0<<endl;
}
int main()
{
	int t;
	cin >> t;
	string mainString, subString;
	while (t--)
	{
		cin >> mainString >> subString;
		KMPSearch(mainString, subString);
	}
	system("pause");
	return 0;
}