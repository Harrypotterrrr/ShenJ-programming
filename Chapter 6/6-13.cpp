/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;
double func_sin(double x)
{
	return sin(x);
}
double func_cos(double x)
{
	return cos(x);
}
double func_exp(double x)
{
	return exp(x);
}
double definite_integration(double(*func)(double), double low, double high, int n)
{
	double sum = 0, dx = (high - low) / n;
	//for (double x = low; fabs(x - high) > eps; x += dx)
	for (double x = low; x - high < eps; x += dx)
		sum += func(x) * dx;
	return sum;
}
int main()
{
	double low, high, value;
	int n;
	while (true) {
		cout << "请输入sinxdx的上下限及区间划分数量\n";
		cin >> low >> high >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (low < high && n > 0)
			break;
	}
	value = definite_integration(func_sin, low, high, n);
	cout << "sinxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;

	while (true) {
		cout << "请输入cosxdx的上下限及区间划分数量\n";
		cin >> low >> high >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (low < high && n > 0)
			break;
	}
	value = definite_integration(func_cos, low, high, n);
	cout << "cosxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;

	while (true) {
		cout << "请输入e^xdx的上下限及区间划分数量\n";
		cin >> low >> high >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (low < high && n > 0)
			break;
	}
	value = definite_integration(func_exp, low, high, n);
	cout << "e^xdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	return 0;
}