/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
using namespace std;

const int M[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int MAX_DAY = 73049;
const int MAX_YEAR = 2100;
const int MIN_YEAR = 1900;

class Date
{
protected:
	int year;
	int month;
	int day;
	
public:
	Date();
	Date(int );
	Date(const int , const int , const int );
	void set(const int , const int , const int );
	operator int()const;

	Date& operator ++();
	Date operator ++(int);
	Date& operator --();
	Date operator --(int);

	bool operator >(const Date &)const;
	bool operator >=(const Date &)const;
	bool operator <(const Date &)const;
	bool operator <=(const Date &)const;
	bool operator ==(const Date &)const;
	bool operator !=(const Date &)const;
	Date operator +(const int &)const;
	Date operator -(const int &)const;
	int  operator -(const Date &)const;

	friend istream& operator >> (istream &, Date &);
	friend ostream& operator << (ostream &,const Date &);

};

/* other function */
bool isLeap(int y);
int Month2Day(int y, int m);