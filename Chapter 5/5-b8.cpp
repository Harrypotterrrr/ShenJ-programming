/*1班 贾昊霖 1651574*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#define eps 1e-8
using namespace std;
bool Judge_Mul(double coord[][2], int n)
{
	double x1 = coord[0][0] - coord[n - 1][0];
	double y1 = coord[0][1] - coord[n - 1][1];
	double x2 = coord[1][0] - coord[0][0];
	double y2 = coord[1][1] - coord[0][1];
	double Cross = x1*y2 - y1*x2;
	bool flag = (fabs(Cross) > eps);
	if (!flag)
		return false;
	flag = Cross > 0;
	for (int i = 1; i <= n - 2; i++) {
		x1 = coord[i][0] - coord[i - 1][0];
		y1 = coord[i][1] - coord[i - 1][1];
		x2 = coord[i + 1][0] - coord[i][0];
		y2 = coord[i + 1][1] - coord[i][1];
		Cross = x1*y2 - y1*x2;
		if (fabs(Cross) < eps || flag != bool(Cross > 0))
			return false;
	}
	return true;
}
double Calc(double coord[][2], int n)
{
	double Square = 0;
	double x1, y1, x2, y2, temp;
	for (int i = 1; i <= n - 2; i++) {
		x1 = coord[i][0] - coord[0][0];
		y1 = coord[i][1] - coord[0][1];
		x2 = coord[i + 1][0] - coord[i][0];
		y2 = coord[i + 1][1] - coord[i][1];
		temp = x1*y2 - x2*y1;
		Square += temp;
	}
	Square = 0.5 * fabs(Square);
	return Square;
}
int main()
{
	double coord[9][2];
	int n;
	while (true) {
		cout << "请输入多边形的顶点数量(4-7)\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 4 && n <= 7)
			break;
	}
	cout << "请按顺时针/逆时针方向输入4个顶点的x,y坐标：\n";
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个顶点的坐标：\n";
		cin >> coord[i][0] >> coord[i][1];
	}
	if (!Judge_Mul(coord, n)) {
		cout << "不是凸" << n << "边形\n";
		return 0;
	}
	cout << "凸" << n << "边形的面积=" << Calc(coord, n) << endl;
	return 0;
}