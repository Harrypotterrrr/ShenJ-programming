/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
char Change(int c)
{
	switch (c) {
		case(1):
			return '+';
		case(2):
			return '-';
		case(3):
			return '*';
		case(4):
			return '/';
	}
}

double Calc(double num1, char c, double num2)
{
	switch (c) {
		case('+'):
			return num1 + num2;
		case('-'):
			return num1 - num2;
		case('*'):
			return num1 * num2;
		default:
			return num1 / num2;
	}
}
bool Print(double a, double b, double c, double d, int x, int y, int z)
{
	bool flag = false;
	char X = Change(x), Y = Change(y), Z = Change(z);
	if (fabs(Calc(Calc(Calc(a, X, b), Y, c), Z, d) - 24) <= eps) {
		cout << "((" << a << X << b << ")" << Y << c << ")" << Z << d << "=24\n";
		flag = true;
	}
	if (fabs(Calc(Calc(a, X, Calc(b, Y, c)), Z, d) - 24) <= eps) {
		cout << "(" << a << X << "(" << b << Y << c << "))" << Z << d << "=24\n";
		flag = true;
	}
	if (fabs(Calc(a, X, Calc(b, Y, Calc(c, Z, d))) - 24) <= eps) {
		cout << a << X << "(" << b << Y << "(" << c << Z << d << "))" << "=24\n";
		flag = true;
	}
	if (fabs(Calc(a, X, Calc(Calc(b, Y, c), Z, d)) - 24) <= eps) {
		cout << a << X << "((" << b << Y << c << ")" << Z << d << ")" << "=24\n";
		flag = true;
	}
	if (fabs(Calc(Calc(a, X, b), Y, Calc(c, Z, d)) - 24) <= eps) {
		cout << "(" << a << X << b << ")" << Y << "(" << c << Z << d << ")" << "=24\n";
		flag = true;
	}
	if (flag)
		return true;
	return false;
}
bool Solve(double a, double b, double c, double d)
{
	bool flag = false;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				if (Print(a, b, c, d, i, j, k))
					flag = true;
	if (flag)
		return true;
	return false;
}


bool judge(double x)
{
	if (x > 0 && x <= 10)
		return true;
	return false;
}
int main()
{
	int num1, num2, num3, num4;
	while (true) {
		cout << "请输入四个（1-10）之间的整数 :\n";
		cin >> num1 >> num2 >> num3 >> num4;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (judge(num1) && judge(num2) && judge(num3) && judge(num4))
			break;
	}
	if(!Solve(num1, num2, num3, num4))
		cout<<"无解\n";
	return 0;
}
