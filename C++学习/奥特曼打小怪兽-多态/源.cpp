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
	void Escape();// 逃跑;
	void Attacked(Monster &m);
	void Restore();
	void Win(Monster &m);
	void Upgrade();
	void Display();
	void attack(Monster &m);
private:
	int rank;// 等级;
	int hp;// 生命;
	int damage;//  攻击;
	int expe;// 经验;
	int money;// 钱;
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
	// 条件是经验值不小于等级10倍。升级将扣除相应的经验值，生命满血，更新生命上限和攻击力。
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
	cout << "奥特曼状态(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
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
	cout << "怪兽状态(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
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
	cout << "Boss怪兽状态(rank=" << rank << " hp=" << hp << " damage=" << damage << " exp=" << expe << " money=" << money << ")" << endl;
}

int main()
{
	//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
	int urank, num;
	cin >> urank >> num;
	Ultraman u(urank);

	while (num-- && u.GetHp() > 10)// 只要奥特曼没死也没逃跑，就继续与怪兽的战斗;
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
				cout << "请重新输入怪兽类型" << endl;
		}

		m->Display();
		int flag = 1;//设置战斗标志flag为true，启动战斗循环，具体如下：

		while (flag) //当战斗未结束就继续
		{
			u.attack(*m);//奥特曼攻击1次            
			if (m->GetHp() > 0)  //怪兽没死
			{
				m->fightback(u); //怪兽反击1次
				if (u.GetHp() > 10) //奥特曼生命值大于10点，不逃跑
					u.Restore(); //奥特曼回血，在方法中判断是否需要加血
				else //奥特曼逃跑，并输出"lose"并回车
				{
					u.Escape();
					cout << "lose" << endl;
					u.Display();//输出奥特曼状态       
					flag = 0;//停止战斗                 
				}
			}

			else // 怪兽死了
			{
				u.Win(*m); // 奥特曼胜利，并输出"win"并回车
				cout << "win" << endl;
				u.Upgrade();// 奥特曼升级
				m->Lose();// 输出怪兽战败信息
				flag = 0;// 停止战斗
			}
		}
	}
	return 0;
}