/*1651574 1∞‡ º÷Íª¡ÿ*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int Calc(int);
	int n;
	while (true) {
		cout << "¿¥∏ˆ ˝◊÷∞…∏Á:\n";
		cin >> n;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n >= 1 && n <= 4000)
			break;
	}

	if (n == 1)
		cout << "1^2=" << Calc(n);
	else if (n == 2)
		cout << "1^2+2^2=" << Calc(n);
	else
		cout<< "1^2+...+"<<n<<"^2=" << Calc(n);
	putchar('\n');
	return 0;
}
int Calc(int i)
{
	if (i == 1)
		return 1;
	return Calc(i - 1) + i * i;
}
