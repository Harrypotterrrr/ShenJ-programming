/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "请分别输入一个三角形的三个定点坐标(xi,yi),i=1~3:\n";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double tmp1 = fabs(x1 - x2)*(y2 - y3);
	double tmp2 = fabs(x2 - x3)*(y1 - y2);
	if (fabs(tmp1 - tmp2) < eps) {
		cout << "不构成三角形\n";
		return 0;
	}
	double S = fabs( x1*y2 +x2*y3 + x3*y1 - x1*y3 - x3*y2 - x2*y1) / 2;
		cout << "三角形面积为：" << S << endl;
	return 0;
}
