#include <iostream>
using namespace std;
class EntryHT
{//词条类
public:
	int key;//关键码
	EntryHT* next;//独立链下一项
	EntryHT()
	{
		key = -9999;
		next = NULL;
	}
};
class HashSearch
{
private:
	int M;//桶容量
	EntryHT** ht;//桶数组
	int time;//查找次数
	bool success;
	int index;//命中位置
	EntryHT* HitHead(const int& k)
	{//沿着关键码k对应的查找链 找到对应的桶头 也就是 找到首个可用空桶(这里采用独立链法 插入表头)
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
			ht[i] = new EntryHT();//初始化头节点
		}
	}
	void put(const int& k)
	{
		EntryHT* T = HitHead(k);
		if (!T->next)//空桶
		{
			T->next = new EntryHT();
			T->next->key = k;
		}
		else//冲突
		{//插入表头
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
		cin >> tmp;//查找目标
		h.search(tmp);
		h.display();
	}
}

