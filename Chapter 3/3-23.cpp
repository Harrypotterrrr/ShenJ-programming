/*1班 1651574 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-5
using namespace std;
int main()
{
	double x, cmp = -1, a;
	cout << "请输入a的值(整数)\n";
	cin >> a;
	x = a;
	while (fabs(x - cmp) >= eps) {
		cmp = x;
		x = 0.5 * (x + a / x);
	}
	cout << a << "的平方根=" << x << endl;
	return 0;
}
