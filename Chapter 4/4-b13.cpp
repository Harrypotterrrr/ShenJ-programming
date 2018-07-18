/*1651574 1�� �����*/
#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;
double pre, rear;
int main()
{
	void DeltaGreaterZero();
	void DeltaLessZero();
	void DeltaEqualZero();
	void AEqualZero();
	double a, b, c, delta;
	while (true) {
		cout << "������һԪ���η��̵�����ϵ��a,b,c:\n";
		cin >> a >> b >> c;
		if (cin.good())
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (!a) {
		AEqualZero();
		return 0;
	}
	delta = b * b - 4 * a * c;
	pre = -b / (2 * a);
	if (delta < 0) {
		rear = sqrt(-delta) / (2 * a);
		DeltaLessZero();
	}
	else {
		rear = sqrt(delta) / (2 * a);
		if (fabs(delta) < eps)
			DeltaEqualZero();
		else
			DeltaGreaterZero();
	}
	return 0;
}
void DeltaLessZero()
{
	cout << "�����������\n"
		<< "x1=" << pre << "+" << rear << "i\n"
		<< "x2=" << pre << "-" << rear << "i\n";
}
void DeltaGreaterZero()
{
	cout << "����������ʵ����\n"
		<< "x1=" << pre + rear << "\n"
		<< "x2=" << pre - rear << "\n";
}
void DeltaEqualZero()
{
	cout << "���������ʵ��:\nx1=x2=" << pre + rear << endl;
}
void AEqualZero()
{
	cout << "����һԪ���η���\n";
}
