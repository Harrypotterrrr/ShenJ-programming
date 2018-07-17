/*1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double solve(int, int, int, int);
	cout << "x=" << solve(1, 2, 3, 4)<<endl;
	return 0;
}
double Function(int a, int b, int c, int d, double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
double Derivative(int a, int b, int c, double x)
{
	return 3 * a * x * x + 2 * b * x + c;
}
double solve(int a, int b, int c, int d)
{
	double x = 1, Fx, Dx;
	while (fabs(Fx = Function(a, b, c, d, x)) > eps) {
		Dx = Derivative(a, b, c, x);
		x = x - Fx / Dx;
	}
	return x;
}

