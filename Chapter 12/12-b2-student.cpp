/* ����� 1651574 1�� */
#include<cmath>
#include"12-b2-student.h"
using namespace std;

/* ���캯�� */
student::student(const int n, const string nam, const char s , const float sc, const string ad)
{
	num = n;
	name = nam;
	sex = s;
	score = sc;
	addr = ad;
}


bool student::operator==(const student &s1)
{
	if (num == s1.num)
		return 1;
	else
		return 0;
}
bool student:: operator!=(const student &s1)
{
	return num != s1.num;
}
student& student:: operator=(const student &s1)
{
	num = s1.num;
	name = s1.name;
	sex = s1.sex;
	score = s1.score;
	addr = s1.addr;

	return *this;
}


ostream& operator<<(ostream& out, const student &s1)
{
	out << "ѧ�ţ�" << s1.num << ' ' << "������" << s1.name << ' ' << "�Ա�" << s1.sex << ' ' << "������" << s1.score << ' ' << "��ַ��" << s1.addr;
	return out;
}


istream& operator>>(istream& in, student &s1)
{
	in >> s1.num >> s1.name >> s1.sex >> s1.score >> s1.addr;
	return in;
}

