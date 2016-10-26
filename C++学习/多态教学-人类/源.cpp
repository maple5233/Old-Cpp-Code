#include <iostream>
#include <string>
using namespace std;
class People
{
protected:
	string name;
	bool isFull;
public:
	static int num;
public:
	People()
	{
		name = "С��";
		isFull = false;
		num++;
	}
	People(string name)
	{
		this->name = name;
		num++;
	}
	People(string name, bool isFull)
	{
		this->name = name;
		this->isFull = isFull;
		num++;
	}
	
	void setName(string Name)
	{
	}
	void setIsFull(bool b)
	{
		isFull = b;
	}
	void eat()
	{
		isFull = true;
	}
	virtual void say() = 0;
	friend void aoihdfiohwd(People& a);
};
class Student :public People
{
private:
	int stuNum;
public:
	Student()
	{
		num--;
	}
	Student(string Name)
	{
		this->name = Name;
		num--;
	}
	Student(string Name, bool b)
	{
		this->name = Name;
		this->isFull = b;
		num--;
	}
	void say()
	{
		cout << "�ҽ�" << name <<"����һ��ѧ����"<< endl;
		if (isFull)
		{
			cout << "�ҳԱ���" << endl;
		}
		else
		{
			cout << "�ö���" << endl;
		}
	}
	void setStuNum()
	{
	}
};
class Police :public People
{
private:
	int workTimes;
public:
	Police()
	{
		num--;
	}
	Police(string Name)
	{
		this->name = Name;
		num--;
	}
	Police(string Name, bool b)
	{
		this->name = Name;
		this->isFull = b;
		num--;
	}
	void say()
	{
		cout << "�ҽ�" << name << "����һ�����졣" << endl;
		if (isFull)
		{
			cout << "�ҳԱ���" << endl;
		}
		else
		{
			cout << "�ö���" << endl;
		}
	}
};
int People::num = 0;

int main()
{
	int a;
	Student HJY1("��1��ҫ",false);
	HJY1.say();
	Police HJY2("��1��",false);
	HJY2.say();
	//��̬����;
	
	People* p;
	cin >> a;
	if (a==1)
	{
		p = new Student();
	}
	else 
	{
		p = new Police();
	}
	p->say();
	//��̬����;
	system("pause");
	return 0;
}