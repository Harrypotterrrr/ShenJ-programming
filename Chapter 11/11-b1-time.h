/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_TIME = 86400;
class Time
{
protected:
	int hour;
	int min;
	int sec;
public:
	Time();
	Time(const int ,const int ,const int );
	void set(const int , const int , const int );
	operator int()const;
	Time(int );
	Time& operator ++();
	Time operator ++(int);
	Time& operator --();
	Time operator --(int);
	bool operator >(const Time &)const;
	bool operator >=(const Time &)const;
	bool operator <(const Time &)const;
	bool operator <=(const Time &)const;
	bool operator ==(const Time &)const;
	bool operator !=(const Time &)const;
	Time operator +(const int &)const;
	Time operator -(const int &)const;
	int  operator -(const Time &)const;


	friend istream& operator >> (istream &in, Time &dt);
	friend ostream& operator << (ostream &out, const Time &dt);
};
