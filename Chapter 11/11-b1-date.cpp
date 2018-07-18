/* 1651574 1°à ¼Öê»ÁØ */
#include "11-b1-date.h"
using namespace std;

Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(const int y, const int m, const int d)
{
	if (y >= 1900 && y <= 2099 && m >= 1 && m <= 12 && d >= 1 && d <= Month2Day(y, m)) {
		this->year = y;
		this->month = m;
		this->day = d;
	}
	else
		*this = Date();
}

void Date::set(const int y, const int m, const int d)
{
	*this = Date(y, m, d);
}

Date::operator int()const
{
	int day = 0;
	day += this->day - 1;
	for (int i = 1; i < month; i++)
		day += Month2Day(year, i);
	for (int i = 1900; i < year; i++)
		day += 365 + isLeap(i);
	return day;
}

Date::Date(int  day)
{
	day = (day + MAX_DAY) % MAX_DAY;
	*this = Date(1900, 1, 1);
	while (day >= 365 + isLeap(year)) {
		day -= 365 + isLeap(year);
		year++;
	}

	while (day >= Month2Day(year, month)) {
		day -= Month2Day(year, month);
		month++;
	}

	this->day += day;
}

Date& Date::operator ++()
{
	day++;
	if (day > Month2Day(year, month)) {
		day = 1;
		month++;
		if (month == 13) {
			month = 1;
			year++;
			if (year == MAX_YEAR)
				year = MIN_YEAR;
		}
	}
	return *this;
}

Date Date::operator ++(int)
{
	Date tmp = *this;
	++(*this);
	return tmp;
}

Date& Date::operator --()
{
	day--;
	if (day == 0) {
		month--;
		if (month == 0) {
			month = 12;
			year--;
			if (year < MIN_YEAR)
				year = MAX_YEAR - 1;
		}
		day = Month2Day(year, month);
	}
	return *this;
}

Date Date::operator --(int)
{
	Date t = *this;
	--(*this);
	return t;
}

bool Date::operator >(const Date &date)const
{
	if (year > date.year)
		return 1;
	else if (year < date.year)
		return 0;
	else if (month > date.month)
		return 1;
	else if (month < date.month)
		return 0;
	else if (day > date.day)
		return 1;
	else
		return 0;
}

bool Date::operator <(const Date &date)const
{
	return date > *this;
}

bool Date::operator >=(const Date &date)const
{
	return !(date > *this);
}

bool Date::operator <=(const Date &date)const
{
	return !(*this > date);
}

bool Date::operator ==(const Date &date)const
{
	return year == date.year && month == date.month && day == date.day;
}

bool Date::operator !=(const Date &date)const
{
	return !(*this == date);
}

Date Date::operator +(const int &date)const
{
	return int(*this) + date;
}

Date Date::operator -(const int &date)const
{
	return int(*this) - date;
}

int  Date::operator -(const Date &date)const
{
	return int(*this) - int(date);
}

istream& operator >> (istream &in, Date &dt)
{
	int year, month, day;
	in >> year >> month >> day;
	dt.set(year, month, day);
	return in;
}

ostream& operator << (ostream &out, const Date &dt)
{
	out << dt.year << "Äê" << dt.month << "ÔÂ" << dt.day << "ÈÕ\n";
	return out;
}

bool isLeap(int year)
{
	if (!(year % 4) && (year % 100) || !(year % 400))
		return 1;
	else
		return 0;
}

int Month2Day(int year, int month)
{
	return month != 2 ? M[month] : (isLeap(year) ? 29 : 28);
}
