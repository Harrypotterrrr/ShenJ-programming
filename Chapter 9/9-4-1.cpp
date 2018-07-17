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
	//Student(int, int){}; //wrong!
};

Student::Student(int n, int g) :num(n), grade(g) {};
//Student::Student(int n = 0, int g = 0) :num(n), grade(g) {};//right
void Student::display()
{
	cout << "the number is:" << num << endl;
	cout << "the grade is:" << grade << endl;
}
int main()
{
	Student *p, list[10] = {Student(1651500,100),
						Student(1651501,90),
						Student(1651502,80),
						Student(1651503,70),
						Student(1651503,60)
	};
	for (p = list; p <= list + 5; p += 2) {
		p->display();
		putchar('\n');
	}
		
	return 0;
}