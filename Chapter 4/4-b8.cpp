/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Max(int, int, int);
	int Max(int, int, int, int);
	int Max(int, int, int, int, int);
	int n, a, b, c, d, maxn;
	while (true) {
		cout << "请输入个数num及num个整数：\n";
		cin >> n >> a >> b;
		if (n == 3)
			cin >> c;
		else if (n == 4)
			cin >> c >> d;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 2 && n <= 4)
			break;
	}
	if (n == 2)
		maxn = Max(2, a, b);
	else if (n == 3)
		maxn = Max(3, a, b, c);
	else
		maxn = Max(4, a, b, c, d);
	cout << "max=" << maxn << endl;
	return 0;
}
int Max(int n, int a, int b) {
	return a > b ? a : b;
}
int Max(int n, int a, int b, int c) {
	int maxn = (a > b ? a : b);
	return maxn > c ? maxn : c;
}
int Max(int n, int a, int b, int c, int d) {
	int maxn = (a > b ? a : b);
	maxn = (maxn > c ? maxn : c);
	return maxn > d ? maxn : d;
}
