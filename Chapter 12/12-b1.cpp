/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);
const double dx = 1e-6;

class integral
{
public:
	virtual ~integral() {}
	virtual double value() = 0;
};

class integral_sin :public integral
{
protected:
	double left, right;

public:
	double value() {
		double value = 0;
		for (double x = left; x <= right; x += dx)
			value += sin(x);
		return value * dx;
	}
	friend istream& operator >> (istream& in, integral_sin &e);
};

class integral_cos :public integral
{
protected:
	double left, right;
public:
	double value() {
		double value = 0;
		double x;
		for (x = left; x <= right; x += dx)
			value += cos(x);
		return value * dx;
	}
	friend istream& operator >> (istream& in, integral_cos &e);
};

class integral_exp :public integral
{
protected:
	double left, right;
public:
	double value() {
		double value = 0;
		double x;
		for (x = left; x <= right; x += dx)
			value += exp(x);
		return value * dx;
	}

	friend istream& operator >> (istream& in, integral_exp &e);
};



istream& operator >> (istream& in, integral_sin &e)
{
	in >> e.left >> e.right;
	return in;
}
istream& operator >> (istream& in, integral_cos &e)
{
	in >> e.left >> e.right;
	return in;
}

istream& operator >> (istream& in, integral_exp &e)
{
	in >> e.left >> e.right;
	return in;
}

int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral *p;

	cin >> s1;
	p = &s1;
	cout << (p->value()) << endl;
	cin >> s2;
	p = &s2;
	cout << (p->value()) << endl;
	cin >> s3;
	p = &s3;
	cout << (p->value()) << endl;

	return 0;
}
