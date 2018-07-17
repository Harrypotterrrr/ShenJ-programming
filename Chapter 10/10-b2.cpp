/* 1651574 贾昊霖 1班 */
#include <iostream>
#include "10-b2.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int year, int month, int day)
{
	if (year > 2099 || year < 1900)
		this->year = 2000;
	else
		this->year = year;
	if (month > 12 || month < 1)
		this->month = 1;
	else
		this->month = month;
	if (day < 1 || day > month2day(this->year, this->month))
		this->day = 1;
	else
		this->day = day;
}

void Date::set(int year, int month, int day)
{
	if (!year)
		year = this->year;
	if (!month)
		month = this->month;
	if (!day)
		day = this->day;
	*this = Date(year, month, day);
}

void Date::get(int &year, int &month, int &day)
{
	year = this->year;
	month = this->month;
	day = this->day;
}

void Date::show()
{
	cout << year << "年" << month << "月" << day << "日\n";
}

Date::Date(int day)
{
	if (day < 1)
		day = 1;
	else if (day > 73049)
		day = 73049;
	*this = Date(1900, 1, 1);
	while (day > 365 + isLeap(year)){
		day -= 365 + isLeap(year);
		year++;
	}
	while (day > month2day(year, month)){
		day -= month2day(year, month);
		month++;
	}
	this->day += day - 1;
}

Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int n)
{
	Date tmp = *this;
	*this = *this + 1;
	return tmp;
}

Date& Date::operator--()
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int n)
{
	Date tmp = *this;
	*this = *this - 1;
	return tmp;
}

Date::operator int()
{
	int day = 1;
	day += this->day - 1;
	int i;
	for (i = 1; i < this->month; i++)
		day += month2day(this->year, i);
	for (i = 1900; i<this->year; i++)
		day += 365 + isLeap(i);

	return day;
}

ostream& operator<<(ostream& out, const Date& dt)
{
	out << dt.year << "年" << dt.month << "月" << dt.day << "日\n";
	return out;
}

istream& operator>>(istream& in, Date& dt)
{
	int y, m, d;
	in >> y >> m >> d;
	dt.set(y, m, d);
	return in;
}

Date operator+(Date& dt, int n)
{
	Date tmp;
	int ctr_day = int(dt);
	tmp = Date(ctr_day + n);
	return tmp;
}

Date operator-(Date& dt, int n)
{
	Date tmp;
	int ctr_day = int(dt);
	tmp = Date(ctr_day - n);
	return tmp;
}

Date operator+(int n, Date& dt )
{
	Date tmp;
	int ctr_day = int(dt);
	tmp = Date(ctr_day + n);
	return tmp;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
bool isLeap(int year)
{
	return (!(year % 4) && (year % 100) || !(year % 400));
}


int month2day(int y, int m)
{
	if (m != 2)
		return M[m - 1];
	else{
		if (isLeap(y))
			return 29;
		return 28;
	}
}

