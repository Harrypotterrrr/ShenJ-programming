/*1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
using namespace std;
class Date;

class Time
{
	friend void display(Date &, Time &);
public:
	Time(int, int, int);
private:
	int hour;
	int minute;
	int sec;
};

class Date
{
	friend void display(Date &, Time &);
public:
	Date(int, int, int);
private:
	int month;
	int day;
	int year;
};

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void display(Date &d, Time &t)
{
	cout << d.month << "/" << d.day << "/" << d.year << endl;
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

int main()
{
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	display(d1, t1);
	return 0;
}