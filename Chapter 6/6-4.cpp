/* 1班 贾昊霖 1651574 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void MoveArray(int *num, int n, int m)
{
	int tmp[25], *q = tmp + m, *p = num;
	for (; p < num + n; q++, p++) {
		if (q >= tmp + n)
			q = tmp;
		*q = *p;
	}
	for (p = num, q = tmp; p < num + n; p++, q++)
		*p = *q;
}
int main()
{
	int num[1000];
	int n, m, *p;
	while (true) {
		cout << "请输入整数的数量n(10-20):\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 10 && n <= 20)
			break;
	}
	cout << "请输入" << n << "个整数：\n";
	for (p = num; p < num + n; p++)
		cin >> *p;
	cout << "输入的整数序列为：\n";
	for (p = num; p < num + n; p++)
		cout << *p << " ";
	putchar('\n');
	cout << "请输入向后移动的位置m(≥1)\n";
	cin >> m;
	m %= 17;
	MoveArray(num, n, m);
	cout << "移动后的序列为\n";
	for (p = num; p < num + n; p++)
		cout << *p << " ";
	putchar('\n');
	return 0;
}