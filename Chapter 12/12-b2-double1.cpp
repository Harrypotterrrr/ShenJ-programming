/* 1651574 º÷Íª¡ÿ 1∞‡ */
#include<cmath>
#include"12-b2-double1.h"
using namespace std;


double1::double1(const double a)
{
	x = a;
}

bool double1::operator==(const double1 &d1)
{
	if (fabs(x - d1.x) < 1e-6)
		return 1;
	else
		return 0;
}

bool double1::operator!=(const double1 &d1)
{
	if (fabs(x - d1.x) >= 1e-6)
		return 1;
	else
		return 0;

}
ostream& operator<<(ostream& out, const double1 &d1)
{
	out << d1.x;
	return out;
}

istream& operator>>(istream& in, double1 &d1)
{
	in >> d1.x;
	return in;
}

double1::double1(const int a)
{
	x = a;
}
