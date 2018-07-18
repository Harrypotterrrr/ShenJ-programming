/* 1651574 1°à ¼Öê»ÁØ */
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
protected:
	int num;
	string name;
	char sex;
};


class Student1 :public Student
{
public:
	void get_value1();
	void display1();
private:
	int age;
	string addr;
};

void Student1::display1()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	cout << "age:" << age << endl;
	cout << "address:" << addr << endl;
}

void Student1::get_value1()
{
	cin >> num >> name >> sex;
	cin >> age >> addr;
}

int main()
{
	Student1 stud;
	stud.get_value1();
	stud.display1();
	return 0;
}