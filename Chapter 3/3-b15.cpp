/* 1∞‡ 1651574 º÷Íª¡ÿ*/
#include <iostream>
#include <cmath>
#define eps 1e-6
using namespace std;
int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			if (j != 1)
				cout << "  ";
			cout << j << "*" << i << "=";
			if (i*j < 10)
				cout << " " << i*j;
			else
				cout << i*j;
		}
		cout << endl;
	}

	return 0;
}
