/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include "11-b1-date.h"
#include "11-b1-time.h"
using namespace std;

class DateTime:public Date,public Time
{
protected:
	operator long long()const;
	DateTime(long long  d);

public:
	DateTime() :Date(), Time() {};
	DateTime(Date date, Time time) :Date(date), Time(time) {};
	DateTime(int year, int month, int day, int hour, int minute, int second) 
		:Date(year, month, day), Time(hour, minute, second) {};
	void set(int , int , int , int , int , int );
	DateTime& operator ++();
	DateTime operator ++(int);
	DateTime& operator --();
	DateTime operator --(int);
	bool operator >(const DateTime &)const;
	bool operator >=(const DateTime &)const;
	bool operator <(const DateTime &)const;
	bool operator <=(const DateTime &)const;
	bool operator ==(const DateTime &)const;
	bool operator !=(const DateTime &)const;
	DateTime operator +(const int &)const;
	DateTime operator -(const int &)const;
	long long  operator -(const DateTime &)const;

	friend istream& operator >> (istream &in, DateTime &dt);
	friend ostream& operator << (ostream &out, const DateTime &dt);
};

