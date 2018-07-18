/*1651574 1班 贾昊霖*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define pai 2 * asin(1)
using namespace std;

int main()
{
	int a, b, ang;
	double sq;
	cout << "请分别输入三角形的两个边和中间的夹角，其中数字均为正整数：\n";
	cin >> a >> b >> ang;
	sq = 0.5 * a * b * sin(ang * pai / 180.0);
	cout << setprecision(3) << setiosflags(ios::fixed);
	cout << "三角形面积为：" << sq;
	return 0;
}