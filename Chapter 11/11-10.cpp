/* 1651574 º÷Íª¡ÿ 1∞‡ */
#include <iostream>
#include <string>
#include <strstream>
using namespace std;

class Teacher
{
protected:
	int num;
	string name;
	char sex;
public:
	void TeacherDisplay();
};

class BirthDate
{
protected:
	int year;
	int month;
	int day;
public:
	void BirthDateSet(const int& y, const int& m, const int& d);
	void BirthDateShow();
};

class Professor :public Teacher
{
protected:
	BirthDate birthday;
public:
	Professor(const int& n,const string& nom,const char& s,const int& y,const int& m,const int& d);
	Professor() {};
	void ProfessorDisplay();
	void SetBirthday(const int& y, const int& m, const int& d);
};

void BirthDate::BirthDateSet(const int& y, const int& m, const int& d)
{
	year = y;
	month = m;
	day = d;
}

void Teacher::TeacherDisplay()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}

void BirthDate::BirthDateShow()
{
	cout << year << "--" << month << "--" << day << endl;
}


Professor::Professor(const int& n, const string& nom, const char& s, const int& y, const int& m, const int& d)
{
	num = n;
	name = nom;
	sex = s;
	birthday.BirthDateSet(y, m, d);
}

void Professor::ProfessorDisplay()
{
	TeacherDisplay();
	birthday.BirthDateShow();
}

void Professor::SetBirthday(const int& y, const int& m, const int& d)
{
	birthday.BirthDateSet(y,m,d);
}

int main()
{
	Professor pro(1651574,"º÷Íª¡ÿ",'M',1897,11,19);
	cout << "≥ı º◊¥Ã¨£∫" << endl;
	pro.ProfessorDisplay();
	int y, m, d;
	cout << " ‰»Î∏ƒ±‰µƒ»’∆⁄yyyy-mm-dd:" << endl;
	cin >> y >> m >> d;
	pro.SetBirthday(y,m,d);
	pro.ProfessorDisplay();
	return 0;
}
/*
1997 11 19
*/