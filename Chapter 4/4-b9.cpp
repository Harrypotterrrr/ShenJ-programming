/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Min(int, int, int);
	int Min(int, int, int, int);
	int Min(int, int, int, int, int);
	int n, a, b, c, d, minn;
	while (true) {
		cout << "请输入个数num及num个整数：\n";
		cin >> n>>a>>b;
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
		minn = Min(2, a, b);
	else if (n == 3)
		minn = Min(3, a, b, c);
	else
		minn = Min(4, a, b, c, d);
	cout << "min=" << minn << endl;
	return 0;
}
int Min(int n, int a, int b) {
	return a < b ? a : b;
}
int Min(int n, int a, int b, int c) {
	int minn = (a < b ? a : b);
	return minn < c ? minn : c;
}
int Min(int n, int a, int b, int c, int d) {
	int minn = (a < b ? a : b);
	minn = (minn < c ? minn : c);
	return minn < d ? minn : d;
}
