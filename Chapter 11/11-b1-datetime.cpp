/* 1651574 1班 贾昊霖 */
#include "11-b1-datetime.h"
using namespace std;

void DateTime::set(int year, int month, int day, int hour, int minute, int second)
{
	*this = DateTime(year, month, day, hour, minute, second);
}

DateTime::operator long long()const
{
	long long tmp;
	tmp = long long(int(Date(*this)))*long long(MAX_TIME) + long long(int(Time(*this)));
	//由于DateTime是继承的Date和Time 因此可以直接Date(Datetime) !!!
	return tmp;
}

DateTime::DateTime(long long  d)
{
	Date date(int(d / MAX_TIME));
	Time time(int(d % MAX_TIME));
	*this = DateTime(date, time);
}

DateTime& DateTime::operator ++()
{
	this->Time::operator++();
	if(Time(*this) == Time(0))
		this->Date::operator++();
	return *this;
}

DateTime DateTime::operator ++(int)
{
	DateTime t = *this;
	++(*this);
	return t;
}

DateTime& DateTime::operator --()
{
	this->Time::operator--();
	if (Time(*this) == Time(-1))
		this->Date::operator--();
	return *this;
}

DateTime DateTime::operator --(int)
{
	DateTime t = *this;
	--(*this);
	return t;
}

bool DateTime::operator >(const DateTime &date_time)const
{
	if (this->Date::operator>(date_time))
		return 1;
	else if (this->Date::operator<(date_time))
		return 0;
	else
		return this->Time::operator>(date_time);
}

bool DateTime::operator <(const DateTime &date_time)const
{
	return date_time>*this;
}

bool DateTime::operator >=(const DateTime &date_time)const
{
	return !(date_time > *this);
}

bool DateTime::operator <=(const DateTime &date_time)const
{
	return !(*this > date_time);
}

bool DateTime::operator ==(const DateTime &date_time)const
{
	if (this->Date::operator==(date_time) && this->Time::operator==(date_time))
		return 1;
	return 0;
}

bool DateTime::operator !=(const DateTime &date_time)const
{
	return !(*this == date_time);
}

DateTime DateTime::operator +(const int &date_time)const
{
	return (long long(*this) + date_time);
	
}

DateTime DateTime::operator -(const int &date_time)const
{
	return (long long(*this) - date_time);
}

long long  DateTime::operator -(const DateTime &date_time)const
{
	return long long(*this) - long long(date_time);
}

istream& operator >> (istream &in, DateTime &dt)
{
	Date day;
	Time time;
	in >> day >> time;
	dt = DateTime(day, time);
	return in;
}

ostream& operator << (ostream &out, const DateTime &dt)
{
	out << Date(dt) << Time(dt);
	return out;
}
