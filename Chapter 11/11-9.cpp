/* 1651574 贾昊霖 1班 */
#include <iostream>
#include <string>
#include <strstream>
using namespace std;

class Teacher
{
protected:
	string name;
	int age;
	string sex;
	string addr;
	string phone;
	string title;
public:
	void TeacherSet();
	void TeacherDisplay();
};

class Cadre
{
protected:
	string name;
	int age;
	string sex;
	string addr;
	string phone;

	string post;
public:
	void CadreSet();
	void CadreDisplay();
};

class Teacher_Cadre :public Teacher, public Cadre
{
protected:
	double wages;
public:
	void Set();
	void Display();
};

void Teacher::TeacherDisplay()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "addr:" << addr << endl;
	cout << "phone:" << phone << endl;
	cout << "title:" << title << endl;
}

void Cadre::CadreDisplay()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "addr:" << addr << endl;
	cout << "phone:" << phone << endl;
	cout << "post:" << post << endl;
}

void Teacher_Cadre::Display()
{
	Teacher::TeacherDisplay();
	cout << "post:" << post << endl;
	cout << "wages:" << wages << endl;
}

void Teacher::TeacherSet()
{
	cin >> name >> age >> sex >> addr >> phone >> title;
}
void Cadre::CadreSet()
{
	cin >> name >> age >> sex >> addr >> phone >> post;
}
void Teacher_Cadre::Set()
{
	Teacher::TeacherSet();
	cin >> post;
	cin >> wages;
}


int main()
{

	Teacher_Cadre tc;
	tc.Set();
	tc.Display();
	return 0;
}

/*
贾昊霖 20 男 北京 110 元帅 中共中央军事委员会主席 0.0
*/