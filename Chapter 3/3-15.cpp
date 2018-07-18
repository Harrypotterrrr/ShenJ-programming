/*1班 1651574 贾昊霖*/
#include <iostream>
using namespace std;
int main()
{
	cout << "输入两个正整数m,n：" << endl;
	int m, n, ans;
	cin >> m >> n;
	int Min = m >= n ? n : m;
	for (int i = Min; i >= 1; i--)
		if (!(m%i) && !(n%i)) {
			ans = i;
			break;
		}
	cout << "最大公约数：" << ans << endl;
	cout << "最小公倍数：" << m * n / ans << endl;
	return 0;
}
