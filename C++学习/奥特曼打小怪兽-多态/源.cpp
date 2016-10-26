#include <iostream>
using namespace std;

class Ultraman;
class Monster;

class Ultraman
{
public:
	Ultraman(int);
	~Ultraman(){}
	int GetRank(){ return this->rank; }
	int GetHp(){ return this->hp; }
	int GetDamage(){ return this->damage; }
	int GetExp(){ return this->expe; }
	int GetMoney(){ return this->money; }
	void SetHp(int a){ this->hp = a; }
	void Escape();// ����;
	void Attacked(Monster &m);
	void Restore();
	void Win(Monster &m);
	void Upgrade();
	void Display();
	void attack(Monster &m);
private:
	int rank;// �ȼ�;
	int hp;// ����;
	int damage;//  ����;
	int expe;// ����;
	int money;// Ǯ;
};



class Monster
{
public:
	Monster(int);
	Monster(){}
	~Monster(){}
	void setInfo(int);
	int GetRank(){ return this->rank; }
	int GetHp(){ return this->hp; }
	int GetDamage(){ return this->damage; }
	int GetExp(){ return this->expe; }
	int GetMoney(){ return this->money; }
	void Attacked(Ultraman &u);
	virtual void Display();
	void SetHp(int a){ hp = a; }
	virtual void Lose(){ cout << "Boss!Help!" << endl; }
	virtual void fightback(Ultraman &u);
protected:
	int rank;
	int hp;
	int damage;
	int expe;
	int money;
};

void Ultraman::Win(Monster &m)
{
	money += m.GetMoney();
	expe += m.GetExp();
}
void Ultraman::Upgrade()
{
	// �����Ǿ���ֵ��С�ڵȼ�10�����������۳���Ӧ�ľ���ֵ��������Ѫ�������������޺͹�������
	while (expe >= rank * 10)
	{
		expe -= rank * 10;
		rank++;
		hp = rank * 10;
		damage = rank * 3;
	}
}
void Ultraman::Display()
{
	cout << "������״̬(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
}

Ultraman::Ultraman(int a)
{
	rank = a;
	hp = rank * 10;
	damage = rank * 3;
	expe = 0;
	money = rank * 10;
}
void Ultraman::attack(Monster &m)
{
	m.SetHp(m.GetHp() - damage);
}
void Ultraman::Escape()
{
	money = 0;
}
void Ultraman::Attacked(Monster &m)
{
	hp -= m.GetDamage() / 2;
}
void Ultraman::Restore()
{
	if (GetHp() < rank * 5)
	{
		while (money >= 10)
		{
			money -= 10;
			hp++;
			if (hp >= rank * 10)
				break;
		}
	}

}

Monster::Monster(int a)
{
	rank = a;
	hp = rank * 20;
	damage = rank * 2;
	expe = rank * 10;
	money = rank * 10;
}
void Monster::setInfo(int a)
{
	rank = a;
	hp = rank * 20;
	damage = rank * 2;
	expe = rank * 10;
	money = rank * 10;
}
void Monster::Attacked(Ultraman &u)
{
	hp -= u.GetDamage();
}
void Monster::Display()
{
	cout << "����״̬(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
}
void Monster::fightback(Ultraman &u)
{
	int temp;
	temp = u.GetHp() - damage / 2;
	u.SetHp(temp);
}

class BOSS :public Monster
{
public:
	BOSS(){ rank = 10; hp = 300; expe = 1000; damage = 50; money = 1001; count = 0; }
	~BOSS(){}
	void XP(Ultraman &u);
	virtual void fightback(Ultraman &u);
	virtual void Lose(){ cout << "I'll be back!" << endl; }
	virtual void Display();
private:
	int count;
};




void BOSS::XP(Ultraman &u)
{
	cout << "XP*****" << endl;
	int temp;
	temp = damage / 2 * 3;
	temp = u.GetHp() - temp;
	u.SetHp(temp);
}

void BOSS::fightback(Ultraman &u)
{
	int temp;
	if (count == 5)
		XP(u);
	else
	{
		temp = u.GetHp() - damage / 2;
		u.SetHp(temp);
		count++;
	}
}

void BOSS::Display()
{
	cout << "Boss����״̬(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
}

int main()
{
	//����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��
	int urank, num;
	cin >> urank >> num;
	Ultraman u(urank);

	while (num-- && u.GetHp() > 10)// ֻҪ������û��Ҳû���ܣ��ͼ�������޵�ս��;
	{
		u.Display();
		Monster* m;
		char type = 0;
		while (1)
		{
			cin >> type;
			if (type == 'B')
			{
				m = new BOSS();
				break;
			}
			else if (type == 'M')
			{
				int r;
				cin >> r;
				m = new Monster(r);
				break;
			}
			else
				cout << "�����������������" << endl;
		}

		m->Display();
		int flag = 1;//����ս����־flagΪtrue������ս��ѭ�����������£�

		while (flag) //��ս��δ�����ͼ���
		{
			u.attack(*m);//����������1��            
			if (m->GetHp() > 0)  //����û��
			{
				m->fightback(u); //���޷���1��
				if (u.GetHp() > 10) //����������ֵ����10�㣬������
					u.Restore(); //��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
				else //���������ܣ������"lose"���س�
				{
					u.Escape();
					cout << "lose" << endl;
					u.Display();//���������״̬       
					flag = 0;//ֹͣս��                 
				}
			}

			else // ��������
			{
				u.Win(*m); // ������ʤ���������"win"���س�
				cout << "win" << endl;
				u.Upgrade();// ����������
				m->Lose();// �������ս����Ϣ
				flag = 0;// ֹͣս��
			}
		}
	}
	return 0;
}