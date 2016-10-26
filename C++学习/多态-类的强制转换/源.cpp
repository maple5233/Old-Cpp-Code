#include<iostream>
#include<string>
using namespace std;
class Teacher
{
public:
	friend ostream& operator<<(ostream& output, Teacher t);
private:
	long num;
	string name;
	string sex;
};
class Student : public Teacher
{
public:
	Student(long num, string name, string sex) :num(num), name(name), sex(sex){}
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
	cout << Teacher(s);
	return 0;
}