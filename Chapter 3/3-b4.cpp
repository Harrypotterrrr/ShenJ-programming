/*1651574 1�� �����*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define pai 2 * asin(1)
using namespace std;

int main()
{
	int a, b, ang;
	double sq;
	cout << "��ֱ����������ε������ߺ��м�ļнǣ��������־�Ϊ��������\n";
	cin >> a >> b >> ang;
	sq = 0.5 * a * b * sin(ang * pai / 180.0);
	cout << setprecision(3) << setiosflags(ios::fixed);
	cout << "���������Ϊ��" << sq;
	return 0;
}