/*1651574 1�� �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Fibonacci(int);
	int n;
	while (true) {
		cout << "������Fibonacci���е�������\n";
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
	cout << "Fibonacci���е�"<<n<<"���ֵ��" << Fibonacci(n);
	putchar('\n');
	return 0;
}
int Fibonacci(int i)
{
	if (i == 1 || i == 2)
		return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}
