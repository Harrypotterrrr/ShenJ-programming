/* 1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int num;
	string name;
	char sex;
};


class Student1 :protected Student
{
private:
	int age;
	string addr;
public:
	void get_value1();
	void display1();
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

