/*1�� 1651574 �����*/
#include <iostream>
#include <cmath>
#define eps 1e-5
using namespace std;
int main()
{
	double x, cmp = -1, a;
	cout << "������a��ֵ(����)\n";
	cin >> a;
	x = a;
	while (fabs(x - cmp) >= eps) {
		cmp = x;
		x = 0.5 * (x + a / x);
	}
	cout << a << "��ƽ����=" << x << endl;
	return 0;
}
