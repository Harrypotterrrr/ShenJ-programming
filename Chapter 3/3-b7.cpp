/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double x1, y1, x2, y2, x3, y3;
	cout << "��ֱ�����һ�������ε�������������(xi,yi),i=1~3:\n";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double tmp1 = fabs(x1 - x2)*(y2 - y3);
	double tmp2 = fabs(x2 - x3)*(y1 - y2);
	if (fabs(tmp1 - tmp2) < eps) {
		cout << "������������\n";
		return 0;
	}
	double S = fabs( x1*y2 +x2*y3 + x3*y1 - x1*y3 - x3*y2 - x2*y1) / 2;
		cout << "���������Ϊ��" << S << endl;
	return 0;
}
