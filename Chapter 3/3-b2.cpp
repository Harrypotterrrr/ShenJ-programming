/*1651574 1�� �����*/
#include <iostream>
using namespace std;

int main()
{

	int a, a0, a1, a2, a3, a4;
	cout << "����һ��������30000����������" << endl;
	cin >> a;
	a0 = a % 10;
	a1 = (a / 10) % 10;
	a2 = (a / 100) % 10;
	a3 = (a / 1000) % 10;
	a4 = (a / 10000) % 10;
	cout <<"��λ��" << a4 << endl
		<< "ǧλ��" << a3 << endl
		<< "��λ��" << a2 << endl
		<< "ʮλ��" << a1 << endl
		<< "��λ��" << a0 << endl;
	return 0;
}