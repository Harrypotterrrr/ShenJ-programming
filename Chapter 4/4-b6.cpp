/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Fibonacci(int);
	int n;
	while (true) {
		cout << "请输入Fibonacci数列的项数：\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			//cin.ignore(cin.rdbuf()->in_avail(), '\n');
			continue;
		}
		if (n > 0)
			break;
	}
	cout << "Fibonacci数列第"<<n<<"项的值：" << Fibonacci(n);
	putchar('\n');
	return 0;
}
int Fibonacci(int i)
{
	if (i == 1 || i == 2)
		return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}
