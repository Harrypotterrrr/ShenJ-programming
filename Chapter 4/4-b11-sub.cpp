/* 1�� ����� 1651574 */
#include <iostream>
using namespace std;
void DeltaLessZero(double pre, double rear)
{
	cout << "�����������\n"
		<< "x1=" << pre << "+" << rear << "i\n"
		<< "x2=" << pre << "-" << rear << "i\n";
}
void DeltaGreaterZero(double pre, double rear)
{
	cout << "����������ʵ����\n"
		<< "x1=" << pre + rear << "\n"
		<< "x2=" << pre - rear << "\n";
}
void DeltaEqualZero(double pre, double rear)
{
	cout << "���������ʵ��:\nx1=x2=" << pre + rear << endl;
}
void AEqualZero()
{
	cout << "����һԪ���η���\n";
}