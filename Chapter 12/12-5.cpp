/* 1651574 1∞‡ º÷Íª¡ÿ */
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);

class Shape
{
public:
	virtual ~Shape() {}

	virtual double area() = 0;
};

class Circle:public Shape
{
protected:
	double r;
public:
	
	double area()
	{
		return PI*r*r;
	}

	Circle(double r): r(r) {}
};

class Square :public Shape
{
protected:
	double a;
public:
	double area()
	{
		return a * a;
	}

	Square(double a) :a(a) {}
};

class Rectangle :public Shape
{
protected:
	double a, b;
public:
	double area()
	{
		return a * b;
	}

	Rectangle(double a, double b) :a(a), b(b) {}
};
class Trapezoid :public Shape
{
protected:
	double t, b, h;
public:

	double area()
	{
		return (t + b) / 2 * h;
	}

	Trapezoid(double t, double  b, double h) :t(t), b(b), h(h) {}
};

class Triangle :public Shape
{
protected:
	double a, b, c;
public:
	double area(){
		double p = (a + b + c) / 2;
		return sqrt((p - a)*(p - b)*(p - c));
	}

	Triangle(double a, double b, double c) :a(a), b(b), c(c) {}
};

int main()
{
	Circle c1(2);
	Square s1(3);
	Rectangle r1(4,5);
	Trapezoid t1(6,7,8);
	Triangle t2(3,4,5);
	Shape *s[5] = { &c1,&s1,&r1,&t1,&t2 };
	
	for (int i = 0;i < 5;i++)
		cout << s[i]->area() << endl;
	
	return 0;
}
