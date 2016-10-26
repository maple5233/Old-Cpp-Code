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
		if (0>t || subString[j] == subString[t])//ƥ�� tС��0˵��������ͨ��� ��ʱt=-1 t++ t���0��Ϊnext����һ��ֵ
		{
			//next[++j] = ++t; ���ԸĽ�Ϊ��
			j++;
			t++;
			next[j] = (subString[j] == subString[t]) ? next[t] : t;
		}
		else//ʧ��
			t = next[t];
	}
}

void KMPSearch(string mainString, string subString)
{
	int l = subString.length();
	int* next =new int [l];
	*next = -1;

	creatNext(subString, next);

	int i = 0, j = 0;//iΪ�ı���������jΪģʽ������
	int m = subString.length();
	int n = mainString.length();

	int k;
	for (k = 0; k<m - 1; k++)
	{
		cout << next[k]+1<<' ';
	}
	cout << next[k] + 1 <<  ' '<< endl;

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
	if (j == m)//j����������ƥ��ɹ���
	//if ((i - j) <= (n - m))//���ƥ���λ����[0,n-m] ˵���ɹ� ��Ȼ˵�����ɹ�
	{
		cout << (i - j) +1<< endl;
		return;//ƥ��ɹ����i-j��ʼ���Ǻϵ�
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