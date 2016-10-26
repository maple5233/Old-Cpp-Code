#include<iostream>
#include<string>
using namespace std;
/*next���ʵ���ǣ�next[j]��ģʽ����jλ��ǰ׺����[0,j) �� ���� ��ƥ��� ��ǰ׺�����׺�ĳ���ֵ*/

/*����ģʽ�������賤��Ϊj����next��ķ����ǣ�������[0,j)��Ϊ��������Ϊģʽ�����ҳ�������ƥ��Ĵ����䳤����Ϊnext��ĵ�jλ

����֪ǰ�沿�֣�j-1����next���Ϳ��� ��ǰ�沿��[0,j-1)����Ϊ��������Ϊģʽ�����ҳ�������ƥ��Ĵ����Ӷ����next����һλ

�����֪��һλ�Ϳ��� ���ϵݹ����next����һλ

next[0]=-1 ��Ϊ�߼��ϵ�ͨ��� ������next[0]ǰ���и�ͨ������Ժ��κ��ַ�ƥ�� ��0>jʱֱ������ƥ��ɹ� ��λ���ϵ�next��ֵΪ0
*/

void creatNext(string subString, int* next)//����next��
{
	int l = subString.length();
	int j = 0;
	int t = *next;
	while (j < l - 1)
	{
		if (0>t || subString[j] == subString[t])//ƥ�� tС��0˵��������ͨ��� t=-1 t++ t���0��Ϊnext����һ��ֵ
		{
			next[++j] = ++t;
		}
		else//ʧ��
			t = next[t];
	}
}

int KMPSearch(string mainString, string subString)
{
	int l = subString.length();
	int* next = new int[l];
	*next = -1;

	creatNext(subString, next);

	int i = 0, j = 0;//iΪ�ı���������jΪģʽ������
	int m = subString.length();
	int n = mainString.length();

	while (j < m && i < n)//i����������û��ƥ��ɹ� j����������ƥ��ɹ���
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
		return i-j;//ƥ��ɹ����i-j��ʼ���Ǻϵ�
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