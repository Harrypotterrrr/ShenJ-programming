/*1∞‡ 1651574 º÷Íª¡ÿ*/
#include <iostream>
using namespace std;
int main()
{
	int sum;
	bool flag;
	for (int i = 6; i <= 1000; i++) {
		sum = 0;
		flag = true;
		for (int j = 1; j <= i / 2;j++)
			if (!(i%j))
				if (sum < i)
					sum += j;
				else {
					flag = false;
					break;
				}
				if (sum == i && flag) {
					for (int j = i; j >= 2; j--)
						if (!(i%j)) {
							if (j == i)
								cout << i << ",its factors are " << i / j;
							else
								cout << "," << i / j;
						}
					putchar('\n');
				}
	}
	return 0;
}