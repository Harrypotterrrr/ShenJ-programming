/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//while(true) {
	double a, temp, temp2;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a_1, a_2;
	cout << "����һ��0~100�ڵĸ�������" << endl;
	cin >> a;
	a1 = int(a / 10) % 10;
	a2 = int(a / 100) % 10;
	a3 = int(a / 1000) % 10;
	a4 = int(a / 10000) % 10;
	a5 = int(a / 100000) % 10;
	a6 = int(a / 1000000) % 10;
	a7 = int(a / 10000000) % 10;
	a8 = int(a / 100000000) % 10;
	a9 = int(a / 1000000000) % 10;
	temp = a - 1000000000. * a9 - 100000000. * \
		a8 - 10000000. * a7 - 1000000. * a6 - \
		100000. * a5 - 10000. * a4 - 1000. * a3 \
		- 100. * a2 - 10. * a1;
	a0 = int(temp);
	temp2 = temp - a0;
	temp2 += 0.005;
	a_1 = int(floor(temp2 * 10));
	a_2 = int(floor(temp2 * 100)) % 10;
	//��������
	cout << "ʮ��λ��" << a9 << endl
		<< "��λ��" << a8 << endl
		<< "ǧ��λ��" << a7 << endl
		<< "����λ��" << a6 << endl
		<< "ʮ��λ��" << a5 << endl
		<< "��λ��" << a4 << endl
		<< "ǧλ��" << a3 << endl
		<< "��λ��" << a2 << endl
		<< "ʮλ��" << a1 << endl
		<< "��λ��" << a0 << endl
		<< "ʮ��λ��" << a_1 << endl
		<< "�ٷ�λ��" << a_2 << endl;
//	}
	return 0;
}
