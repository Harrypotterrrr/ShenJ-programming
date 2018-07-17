/* 1651574 1°à ¼Öê»ÁØ */
#include "11-b1-time.h"
using namespace std;

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(const int hour, const int minute, const int second)
{
	if (hour >= 0 && hour < 24 && minute >= 0 && minute <60 && second >= 0 && second<60) {
		this->hour = hour;
		this->min = minute;
		this->sec = second;
	}
	else
		*this = Time();
}

void Time::set(const int hour, const int minute, const int second)
{
	*this = Time(hour,minute,second);
}

Time::operator int()const
{
	int tmp = hour * 3600 + min * 60 + sec;
	return tmp;
}

Time::Time(int  n)
{
	n = (n + MAX_TIME) % MAX_TIME;
	sec = n % 60;
	n /= 60;
	min = n % 60;
	n /= 60;
	hour = n;
}

Time& Time::operator ++()
{
	sec++;
	if (sec >= 60) {
		sec = 0;
		min++;
		if (min>=60) {
			min = 0;
			hour++;
			if (hour >= 24)
				hour = 0;
		}
	}
	return *this;
}

Time Time::operator ++(int)
{
	Time t = *this;
	++(*this);
	return t;
}

Time& Time::operator --()
{
	sec--;
	if (sec < 0) {
		min--;
		if (min < 0) {
			min = 59;
			hour--;
			if (hour < 0)
				hour = 23;
		}
		sec = 59;
	}
	return *this;
}

Time Time::operator --(int)
{
	Time t = *this;
	--(*this);
	return t;
}

bool Time::operator >(const Time &time)const
{
	if (hour > time.hour)
		return 1;
	else if (hour < time.hour)
		return 0;
	else if (min > time.min)
		return 1;
	else if (min < time.min)
		return 0;
	else if (sec > time.sec)
		return 1;
	else
		return 0;
}

bool Time::operator <(const Time &time)const
{
	return time>*this;
}

bool Time::operator >=(const Time &time)const
{
	return !(time > *this);
}

bool Time::operator <=(const Time &time)const
{
	return !(*this > time);
}

bool Time::operator ==(const Time &time)const
{
	if (hour == time.hour && min == time.min && sec == time.sec)
		return 1;
	return 0;
}

bool Time::operator !=(const Time &time)const
{
	return !(*this == time);
}

Time Time::operator +(const int &time)const
{
	return int(*this) + time;
}

Time Time::operator -(const int &time)const
{
	return int(*this) - time;
}

int Time::operator -(const Time &time)const
{
	return int(*this) - int(time);
}

istream& operator >> (istream &in, Time &time)
{
	int h, m, s;
	in >> h >> m >> s;
	time.set(h, m, s);
	return in;
}

ostream& operator << (ostream &out, const Time &time)
{
	out << setfill('0');
	out << setw(2)<<time.hour << ":" <<setw(2)<< time.min << ":" <<setw(2)<< time.sec << endl;
	return out;
}