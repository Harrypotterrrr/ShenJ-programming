/*1651574 1班 贾昊霖*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	void Print(int);
	int n;
	while (true) {
		cout << "请输入一个整数:\n";
		cin >> n;
		if (cin.good())
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (n < 0) {
		cout << "- ";
		n = -n;
	}
	Print(n);
	putchar('\n');
	return 0;
}
void Print(int num)
{
	if (!num)
		return;
	Print(num / 10);
	cout << num % 10 << " ";
}