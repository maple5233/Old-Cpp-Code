/*#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(long num, string name, string sex) :num(num), name(name), sex(sex){}
	long getNum(){ return num; }
	string getName(){ return name; }
	string getSex(){ return sex; }
private:
	long num;
	string name;
	string sex;
};
class Teacher 
{
public:
	friend ostream& operator<<(ostream& output, Teacher t);
	Teacher(Student s){ num =s.getNum(); name = s.getName(); sex = s.getSex(); }
private:
	long num;
	string name;
	string sex;
};




ostream& operator<<(ostream& output, Teacher t)
{
	output << "I'm a teacher" << t.name << t.num << t.sex;
	return output;
}

int main(int argc, char* argv[])
{
	Student s(123, "Cjc", "man");
	cout << Teacher(s) << endl;
	system("pause");
	return 0;
	}*/