/*1651574 1∞‡ º÷Íª¡ÿ*/
#include <iostream>
//#include <Windows.h>
#include <iomanip>
#include <cmath>
#define eps 1e-8
using namespace std;
int main()
{
	int num[15] = { 0,1 };
	for (int i = 1; i <= 10; i++) {
		for (int j = (i + 1) / 2; j >= 1; j--)
			num[j] = num[j] + num[j - 1];
		for (int j = (i + 3) / 2; j <= i; j++)
			num[j] = num[i + 1 - j];
		for (int j = 1; j <= i; j++)
				cout << setw(6) << num[j];
		putchar('\n');
	}
	return 0;
}
