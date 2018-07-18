/*¼Öê»ÁØ 1651574 1°à*/
#include <iostream>
using namespace std;

class Student
{
private:
	int num;
	int grade;
public:
	Student(int = 0, int = 0);
	void display();
	void input();
	//Student(int, int){}; //wrong!
};

Student::Student(int n, int g) :num(n), grade(g) {};
//Student::Student(int n = 0, int g = 0) :num(n), grade(g) {};//right
void Student::display()
{
	cout << "the number is:" << num << endl;
	cout << "the grade is:" << grade << endl;
}
void Student::input()
{
	cout << "input the num and grade:";
	cin >> num >> grade;
}
	

int main()
{
	Student *p, list[10];
	for (p = list; p < list + 5; p += 1) {
		p->input();
	}
	for (p = list; p < list + 5; p += 2) {
		p->display();
		putchar('\n');
	}
	return 0;
}