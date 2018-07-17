/* 1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int num;
	string name;
	char sex;
public:
	void get_value() {
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
};


class Student1 :private Student
{
private:
	int age;
	string addr;
public:
	void get_value_1() {
		get_value();
		cin >> age >> addr;
	}

	void display_1() {
		display();
		cout << "age:" << age << endl;
		cout << "address:" << addr << endl;
	}
};

int main()
{
	Student1 stud;
	stud.get_value_1();
	stud.display_1();
	return 0;
}
