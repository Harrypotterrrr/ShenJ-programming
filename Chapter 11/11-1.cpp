/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int num;
	string name;
	char sex;
public:
	void get_value() {
		cin >> num >> name >> sex;
	}
	void display() {
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
};


class Student1 :public Student
{
protected:
	int age;
	string addr;

public:
	void get_value_1() {
		cin >> age >> addr;
	}

	void display_1() {
		cout << "age:" << age << endl;
		cout << "address:" << addr << endl;
	}
};

int main()
{
	Student1 stud;
	stud.get_value();
	stud.get_value_1();
	stud.display();
	stud.display_1();
	return 0;
}
