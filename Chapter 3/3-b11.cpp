/*1651574 1班 贾昊霖*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double m;
	int N = 0, n_50, n_20, n_10, n_5, n_1, n_05, n_01, n_005, n_002, n_001;
	cout << "请输入人民币币值:\n";
	cin >> m;
	m += 0.005;

	n_50 = int(m / 50);
	N += n_50;
	m -= n_50 * 50;

	n_20 = int(m / 20);
	N += n_20;
	m -= n_20 * 20;

	n_10 = int(m / 10);
	N += n_10;
	m -= n_10 * 10;

	n_5 = int(m / 5);
	N += n_5;
	m -= n_5 * 5;

	n_1 = int(m / 1);
	N += n_1;
	m -= n_1 * 1;

	n_05 = int(m / 0.5);
	N += n_05;
	m -= n_05 * 0.5;

	n_01 = int(m / 0.1);
	N += n_01;
	m -= n_01 * 0.1;

	n_005 = int(m / 0.05);
	N += n_005;
	m -= n_005 * 0.05;

	n_002 = int(m / 0.02);
	N += n_002;
	m -= n_002 * 0.02;

	n_001 = int(m / 0.01);
	N += n_001;
	m -= n_001 * 0.01;

	cout << "共" << N << "张找零，具体如下：\n";
	if (n_50)
		cout << "50元：" << n_50 << "张\n";
	if (n_20)
		cout << "20元：" << n_20 << "张\n";
	if (n_10)
		cout << "10元：" << n_10 << "张\n";
	if (n_5)
		cout << "5元：" << n_5 << "张\n";
	if (n_1)
		cout << "1元：" << n_1 << "张\n";
	if (n_05)
		cout << "5角：" << n_05 << "张\n";
	if (n_01)
		cout << "1角：" << n_01 << "张\n";
	if (n_005)
		cout << "5分：" << n_005 << "张\n";
	if (n_002)
		cout << "2分：" << n_002 << "张\n";
	if (n_001)
		cout << "1分：" << n_001 << "张\n";
	return 0;
}
