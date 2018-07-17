/*1∞‡ 1651574 º÷Íª¡ÿ*/
#include <iostream>
#include <cmath>
#define eps 1e-6
using namespace std;
int main()
{
	double left = 0, right = 1;
	double mid, midValue = 2;
	while (fabs(midValue) > eps) {
		mid = (left + right) / 2;
		midValue = 2 * mid*mid*mid - 9 * mid*mid + 12 * mid - 3;
		if (midValue < 0)
			left = mid;
		else
			right = mid;
	}
	cout << "x=" << mid << endl;
	return 0;
}
