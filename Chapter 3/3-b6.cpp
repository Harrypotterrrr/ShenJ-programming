/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	double a, b, c, p, s;
	cout << "������һ�������ε����߳���:\n";
	cin >> a >> b >> c;
	p = 0.5 *(a + b + c);
	s = p*(p - a)*(p - b)*(p - c);
	if (!(s > 0 && a > 0 && b > 0 && c > 0))
		cout << "������������\n";
	else
		cout << "���������Ϊ��" << sqrt(s) << endl;
	return 0;
}
