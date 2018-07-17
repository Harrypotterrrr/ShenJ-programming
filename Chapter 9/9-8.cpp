/*º÷Íª¡ÿ 1651574 1∞‡*/
#include <iostream>
using namespace std;

class Student
{
public:
	Student(int n, float s) :num(n), score(s) {};
	void change(int n, float s)
	{
		num = n;
		score = s;
	}
	void display()
	{
		cout << num << " " << score << endl;
	}
private:
	int num;
	float score;
};

void fun(Student &tmp)
{
	tmp.display();
	tmp.change(101, 80.5);
	tmp.display();
}
int main()
{
	Student stud(101, 78.5);
	fun(stud);
	return 0;
}