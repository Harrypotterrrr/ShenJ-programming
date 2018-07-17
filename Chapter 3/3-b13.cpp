/*1班 1651574 贾昊霖*/
#include <iostream>
#include <cmath>
#define eps 1e-6
using namespace std;
int main()
{
	double x, ans = 0, temp = 1;
	cout << "请输入x的值(整数)\n";
	cin >> x;
	for (int i = 1; temp >= eps;i++) {
		ans += temp;
		temp *= x;
		temp /= i;
	}
	cout << "e^" << x << "=" << ans << endl;
	return 0;
}
