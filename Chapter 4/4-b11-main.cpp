/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-8
void DeltaGreaterZero(double, double);
void DeltaLessZero(double, double);
void DeltaEqualZero(double, double);
void AEqualZero();
int main()
{
	double a, b, c, delta, pre, rear;
	while (true) {
		cout << "请输入一元二次方程的三个系数a,b,c:\n";
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
		DeltaLessZero(pre, rear);
	}
	else {
		rear = sqrt(delta) / (2 * a);
		if (fabs(delta) < eps)
			DeltaEqualZero(pre, rear);
		else
			DeltaGreaterZero(pre, rear);
	}
	return 0;
}