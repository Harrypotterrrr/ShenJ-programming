/* 1班 贾昊霖 1651574 */
#include <iostream>
using namespace std;
void DeltaLessZero(double pre, double rear)
{
	cout << "有两个虚根：\n"
		<< "x1=" << pre << "+" << rear << "i\n"
		<< "x2=" << pre << "-" << rear << "i\n";
}
void DeltaGreaterZero(double pre, double rear)
{
	cout << "有两个不等实根：\n"
		<< "x1=" << pre + rear << "\n"
		<< "x2=" << pre - rear << "\n";
}
void DeltaEqualZero(double pre, double rear)
{
	cout << "有两个相等实根:\nx1=x2=" << pre + rear << endl;
}
void AEqualZero()
{
	cout << "不是一元二次方程\n";
}