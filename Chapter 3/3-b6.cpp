/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double a, b, c, p, s;
	cout << "请输入一个三角形的三边长度:\n";
	cin >> a >> b >> c;
	p = 0.5 *(a + b + c);
	s = p*(p - a)*(p - b)*(p - c);
	if (!(s > 0 && a > 0 && b > 0 && c > 0))
		cout << "不构成三角形\n";
	else
		cout << "三角形面积为：" << sqrt(s) << endl;
	return 0;
}
