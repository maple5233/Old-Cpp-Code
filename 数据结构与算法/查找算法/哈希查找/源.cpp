#include <iostream>
using namespace std;
class EntryHT
{//������
public:
	int key;//�ؼ���
	EntryHT* next;//��������һ��
	EntryHT()
	{
		key = -9999;
		next = NULL;
	}
};
class HashSearch
{
private:
	int M;//Ͱ����
	EntryHT** ht;//Ͱ����
	int time;//���Ҵ���
	bool success;
	int index;//����λ��
	EntryHT* HitHead(const int& k)
	{//���Źؼ���k��Ӧ�Ĳ����� �ҵ���Ӧ��Ͱͷ Ҳ���� �ҵ��׸����ÿ�Ͱ(������ö������� �����ͷ)
		index = k % M;
		return ht[index];
	}
	void reset()
	{
		time = 0;
		success = false;
		index = 0;
	}
public:
	HashSearch(int c = 5)
	{
		int i;
		M = c;
		time = 0;
		success = false;
		ht = new EntryHT*[M];
		for (i = 0; i < M; i++)
		{
			ht[i] = new EntryHT();//��ʼ��ͷ�ڵ�
		}
	}
	void put(const int& k)
	{
		EntryHT* T = HitHead(k);
		if (!T->next)//��Ͱ
		{
			T->next = new EntryHT();
			T->next->key = k;
		}
		else//��ͻ
		{//�����ͷ
			EntryHT* tmp = T->next;
			T->next = new EntryHT();
			T->next->key = k;
			T->next->next = tmp;
		}
	}
	void search(const int& k)
	{
		EntryHT* T = HitHead(k);
		reset();
		while (T->next)
		{
			time++;
			if (T->next->key == k)
			{
				success = true;
				return;
			}
			T = T->next;
		}
	}
	void display()
	{
		if (!success)
		{
			time++;
		}
		cout << success << ' ' << index << ' ' << time << endl;
	}
};
int main()
{
	int T, size, i, tmp;
	cin >> T;
	while (T--)
	{
		HashSearch h(5);
		cin >> size;
		for (i = 0; i < size; i++)
		{
			cin >> tmp;
			h.put(tmp);
		}
		cin >> tmp;//����Ŀ��
		h.search(tmp);
		h.display();
	}
}

